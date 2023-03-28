#include "ZoomToMouse.h"
#include "TransitionManager.h"

ZoomToMouse::ZoomToMouse(SCENES next_scene, iPoint mouse_position, float step_duration, bool non_lerp, float zoom_scale) : Transition(next_scene, step_duration, non_lerp)
, zoom_scale(zoom_scale)
, mouse_position(mouse_position)
{
	InitZoomToMouse(mouse_position);
}

ZoomToMouse::~ZoomToMouse()
{

}

void ZoomToMouse::StepTransition()
{
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

	ApplyZoom();
}

void ZoomToMouse::Entering()
{
	current_cutoff += GetCutoffRate(step_duration);

	if (current_cutoff >= MAX_CUTOFF)
	{
		current_cutoff = MAX_CUTOFF;

		step = TRANSITION_STEP::CHANGING;
	}
}

void ZoomToMouse::Changing()
{
	app->sceneManager->SwitchScene(next_scene);
	
	step = TRANSITION_STEP::EXITING;
}

void ZoomToMouse::Exiting()
{
	current_cutoff -= GetCutoffRate(step_duration);

	if (current_cutoff <= MIN_CUTOFF)
	{
		step = TRANSITION_STEP::NONE;

		app->transitionManager->DeleteActiveTransition();
	}
}

void ZoomToMouse::ApplyZoom()
{
	zoom_rate = GetZoomRate();																				

	if (!non_lerp)
	{
		app->render->camera.x = Lerp(original_position.x, target_position.x, current_cutoff);				
		app->render->camera.y = Lerp(original_position.y, target_position.y, current_cutoff);				
	}
	else
	{
		
		

		app->render->camera.x = N_Lerp(original_position.x, target_position.x, current_cutoff);
		app->render->camera.y = N_Lerp(original_position.y, target_position.y, current_cutoff);
	}

	SDL_RenderSetScale(app->render->renderer, zoom_rate, zoom_rate);
}

float ZoomToMouse::GetZoomRate() const
{
	float rate = original_scale + zoom_scale * current_cutoff;

	if (rate > original_scale + zoom_scale)
	{
		rate = original_scale + zoom_scale;
	}

	if (rate < original_scale)
	{
		rate = original_scale;
	}

	return rate;
}

void ZoomToMouse::InitZoomToMouse(iPoint mouse_position)
{
	original_scale = app->win->GetScale();

	original_position.x = app->render->camera.x;
	original_position.y = app->render->camera.y;
	
	target_position.x = (-mouse_position.x) + app->render->camera.w * 0.25f;		
	target_position.y = (-mouse_position.y) + app->render->camera.h * 0.25f;		

	step = TRANSITION_STEP::ENTERING;
}