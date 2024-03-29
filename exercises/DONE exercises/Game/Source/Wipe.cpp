#include "Wipe.h"
#include "TransitionManager.h"

Wipe::Wipe(SCENES next_scene, float step_duration, bool non_lerp, bool vertical, bool wipe_from_right, bool wipe_from_bottom, Color wipe_colour) 
	: Transition(next_scene, step_duration, non_lerp)
	, vertical(vertical)
	, wipe_from_right(wipe_from_right)
	, wipe_from_bottom(wipe_from_bottom)
	, wipe_colour(wipe_colour)
{
	InitWipe();
}

Wipe::~Wipe()
{

}

void Wipe::StepTransition()
{
	current_cutoff += GetCutoffRate(step_duration);
	
	switch (step)
	{
	case TRANSITION_STEP::ENTERING:

		Entering();

		break;

	case TRANSITION_STEP::CHANGING:

		Changing();

		break;

	case TRANSITION_STEP::EXITING:

		Exiting();

		break;
	}

	TranslateWipe();
}

void Wipe::Entering()
{
	if (current_cutoff >= MAX_CUTOFF)
	{
		current_cutoff = MIN_CUTOFF;

		step = TRANSITION_STEP::CHANGING;
	}
}

void Wipe::Changing()
{
	app->sceneManager->SwitchScene(next_scene);

	step = TRANSITION_STEP::EXITING;
}

void Wipe::Exiting()
{					
	if (current_cutoff >= MAX_CUTOFF)
	{
		current_cutoff = MIN_CUTOFF;
		
		step = TRANSITION_STEP::NONE;

		app->transitionManager->DeleteActiveTransition();
	}
}

void Wipe::TranslateWipe()
{
	if (!vertical)
	{
		HorizontalWipe();
	}
	else
	{
		VerticalWipe();
	}

	DrawWipe();
}

void Wipe::HorizontalWipe()
{
	if (!wipe_from_right)
	{
		if (step == TRANSITION_STEP::ENTERING)										
		{
			if (!non_lerp)
			{
				screen.x = Lerp(-screen.w, 0, current_cutoff);						
			}
			else
			{
				screen.x = N_Lerp(-screen.w, 0, current_cutoff);					
			}
		}

		if (step == TRANSITION_STEP::EXITING)										
		{
			if (!non_lerp)
			{
				screen.x = Lerp(0, screen.w, current_cutoff);
			}
			else
			{
				screen.x = N_Lerp(0, screen.w, current_cutoff);
			}
		}
	}
	else
	{
		if (step == TRANSITION_STEP::ENTERING)										
		{
			if (!non_lerp)
			{
				screen.x = Lerp(screen.w, 0, current_cutoff);
			}
			else
			{
				screen.x = N_Lerp(screen.w, 0, current_cutoff);
			}
		}

		if (step == TRANSITION_STEP::EXITING)										
		{
			if (!non_lerp)
			{
				screen.x = Lerp(0, -screen.w, current_cutoff);
			}
			else
			{
				screen.x = N_Lerp(0, -screen.w, current_cutoff);
			}
		}
	}
}

void Wipe::VerticalWipe()
{
	if (!wipe_from_bottom)
	{
		if (step == TRANSITION_STEP::ENTERING)											
		{
			if (!non_lerp)
			{
				screen.y = Lerp(-screen.h, 0, current_cutoff);							
			}
			else
			{
				screen.y = N_Lerp(-screen.h, 0, current_cutoff);						
			}
		}

		if (step == TRANSITION_STEP::EXITING)											
		{
			if (!non_lerp)
			{
				screen.y = Lerp(0, screen.h, current_cutoff);
			}
			else
			{
				screen.y = N_Lerp(0, screen.h, current_cutoff);
			}
		}
	}
	else
	{
		if (step == TRANSITION_STEP::ENTERING)										
		{
			if (!non_lerp)
			{
				screen.y = Lerp(screen.h, 0, current_cutoff);
			}
			else
			{
				screen.y = N_Lerp(screen.h, 0, current_cutoff);
			}
		}

		if (step == TRANSITION_STEP::EXITING)										
		{
			if (!non_lerp)
			{
				screen.y = Lerp(0, -screen.h, current_cutoff);
			}
			else
			{
				screen.y = N_Lerp(0, -screen.h, current_cutoff);
			}
		}
	}
}

void Wipe::DrawWipe()
{
	SDL_SetRenderDrawColor(app->render->renderer, wipe_colour.r, wipe_colour.g, wipe_colour.b, 255);
	SDL_RenderFillRect(app->render->renderer, &screen);
}

void Wipe::InitWipe()
{
	SDL_SetRenderDrawBlendMode(app->render->renderer, SDL_BLENDMODE_BLEND);

	app->win->GetWindowRect(screen);

	step = TRANSITION_STEP::ENTERING;
}