#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>
#include "SDL/include/SDL.h"
#include "PugiXml\src\pugixml.hpp"

#include "App.h"

#define MAXSCENES 2

enum class SCENES
{
	SCENE1,
	SCENE2,
	NONE
};

class Scene
{
public:
	Scene(SCENES scene_name);
	virtual ~Scene();

	virtual bool Awake(pugi::xml_node& config);
	virtual bool Start();
	virtual bool PreUpdate();
	virtual bool Update(float dt);
	virtual bool PostUpdate();
	virtual bool CleanUp();

public:
	virtual void InitScene();
	virtual void DrawScene();
	virtual SDL_Texture* SceneToTexture();

	virtual void ExecuteTransition();

public:
	SCENES			scene_name;

	int map_width;
	int map_height;

public:
	SDL_Surface* scene_surface;
	//SDL_Renderer* scene_renderer;
	SDL_Texture* scene_texture;
	SDL_Texture* scene_pretransition_texture;
};

#endif // !__SCENE_H__