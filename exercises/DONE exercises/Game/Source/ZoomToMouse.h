#ifndef __ZOOM_TO_MOUSE_H__
#define __ZOOM_TO_MOUSE_H__

#include  "Transition.h"

class ZoomToMouse : public Transition
{
public:
	ZoomToMouse(SCENES next_scene, iPoint mouse_position, float step_duration, bool non_lerp, float zoom_scale);
	~ZoomToMouse();

	void StepTransition();

public:
	void Entering();
	void Changing();
	void Exiting();

	void ApplyZoom();
	float GetZoomRate() const;							

	void InitZoomToMouse(iPoint mouse_position);

private:
	iPoint mouse_position;
	iPoint original_position;
	iPoint target_position;

	float original_scale;								
	float zoom_scale;									
	float zoom_rate;									
};

#endif // !__ZOOM_TO_MOUSE_H__
