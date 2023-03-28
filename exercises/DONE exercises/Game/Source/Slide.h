#ifndef __SLIDE_H__
#define __SLIDE_H__

#include "Transition.h"
#include "Color.h"

class Slide : public Transition
{
public:
	Slide(SCENES next_scene, float step_duration, bool non_lerp, bool vertical, bool slide_from_right, bool slide_from_bottom, Color slide_colour);
	~Slide();

	void StepTransition();

public:
	void Entering();
	void Changing();
	void Exiting();

	void TranslateSlide();
	void HorizontalSlide();								
	void VerticalSlide();								
	void DrawSlide();

	void InitSlide();

private:
	SDL_Rect	screen;
	Color		slide_colour;

	bool		vertical;								
	bool		slide_from_right;						
	bool		slide_from_bottom;						
};

#endif // !__SLIDE_H__