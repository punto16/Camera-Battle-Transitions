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
	//TODO 4: THE SAME, IT IS THE EASIER OF THEM ALL, ITS JUST A CUT SO..., JUST SWITCH THE SCENE AND FIND THE CORRECT
	//FUNCTION TO MODIFY THE BOOLEAN OF THE PREVIOUS TODO AND DELETING THE TRANSITION (BECAUSE IT WOULD BE FINISHED)
}