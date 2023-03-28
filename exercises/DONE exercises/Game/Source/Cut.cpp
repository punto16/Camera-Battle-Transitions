#include "Cut.h"
#include "TransitionManager.h"

Cut::Cut(SCENES next_scene) : Transition(next_scene, 0.0f)
{

}

Cut::~Cut()
{

}

void Cut::StepTransition()
{
	app->sceneManager->SwitchScene(next_scene);

	app->transitionManager->DeleteActiveTransition();
}