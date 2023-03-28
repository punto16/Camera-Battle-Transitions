#ifndef __WIPE_H__
#define __WIPE_H__

#include "Transition.h"
#include "Color.h"

class Wipe : public Transition
{
public:
	Wipe(SCENES next_scene, float step_duration, bool non_lerp, bool vertical, bool wipe_from_right, bool wipe_from_bottom, Color wipe_colour);
	~Wipe();

	void StepTransition();

public:
	void Entering();
	void Changing();
	void Exiting();

	void TranslateWipe();
	void HorizontalWipe();						
	void VerticalWipe();						
	void DrawWipe();

	void InitWipe();

private:
	SDL_Rect	screen;
	Color		wipe_colour;

	bool		vertical;						
	bool		wipe_from_right;				
	bool		wipe_from_bottom;				
};

#endif // !__WIPE_H__