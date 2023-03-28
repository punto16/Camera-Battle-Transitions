#ifndef __SCENE2_H__
#define __SCENE2_H__

#include "Module.h"
#include "Scene.h"

struct SDL_Texture;

class Scene2 : public Scene
{
public:

	Scene2();

	// Destructor
	virtual ~Scene2();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();


	// Init scene elements
	void InitScene();

	// Draw scene elements
	void DrawScene();

	// To get a texture from screen
	SDL_Texture* SceneToTexture();

	// To execute transition depending on input
	void ExecuteTransition();

private:
};

#endif // __SCENE2_H__