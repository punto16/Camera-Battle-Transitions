#include "ZoomToTexture.h"
#include "TransitionManager.h"

ZoomToTexture::ZoomToTexture(SCENES next_scene, iPoint mouse_position, float step_duration, float zoom_scale) : Transition(next_scene, step_duration)
, zoom_scale(zoom_scale)
, mouse_position(mouse_position)
{
	InitZoomToTexture(mouse_position);
}

ZoomToTexture::~ZoomToTexture()
{

}

void ZoomToTexture::StepTransition()
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

void ZoomToTexture::Entering()
{
	current_cutoff += GetCutoffRate(step_duration);
	
	if (current_cutoff >= MAX_CUTOFF)
	{
		current_cutoff = MAX_CUTOFF;

		step = TRANSITION_STEP::CHANGING;
	}
}

void ZoomToTexture::Changing()
{
	app->sceneManager->SwitchScene(next_scene);

	target_to_zoom = app->sceneManager->current_scene->scene_texture;

	step = TRANSITION_STEP::EXITING;
}

void ZoomToTexture::Exiting()
{
	current_cutoff -= GetCutoffRate(step_duration);
	
	if (current_cutoff <= MIN_CUTOFF)
	{	
		step = TRANSITION_STEP::NONE;

		app->transitionManager->DeleteActiveTransition();
	}
}

void ZoomToTexture::ApplyZoom()
{
	zoom_rate = original_scale + current_cutoff * zoom_scale;														

	app->render->DrawTexture(target_to_zoom, x_increase_rate, y_increase_rate, app->render->renderer, NULL, zoom_rate);
}

void ZoomToTexture::InitZoomToTexture(iPoint mouse_position)
{
	
	original_scale			= app->win->GetScale();																		
	
	target_to_zoom			= app->sceneManager->current_scene->scene_texture;											
	
	float total_zoom		= original_scale + zoom_scale;																
	
	float half_map_width	= app->sceneManager->current_scene->map_width * 0.5f;										
	float half_map_height	= app->sceneManager->current_scene->map_height * 0.5f;										
	
	float x_increment		= Lerp(half_map_width, half_map_width * zoom_scale, zoom_rate);
	float y_increment		= Lerp(half_map_height, half_map_height * zoom_scale, zoom_rate);

	x_increase_rate			= -mouse_position.x - x_increment;
	y_increase_rate			= -mouse_position.y + y_increment;
	
	
	step = TRANSITION_STEP::ENTERING;
}