#include "Scene.h"
#include "Render.h"
#include "Input.h"

Scene::Scene(SCENES scene_name) : scene_name(scene_name), scene_surface(nullptr),/* scene_renderer(nullptr),*/ scene_texture(nullptr)
{

}

Scene::~Scene()
{

}

bool Scene::Awake(pugi::xml_node& config)
{
	return true;
}

bool Scene::Start()
{
	return true;
}

bool Scene::PreUpdate()
{
	return true;
}

bool Scene::Update(float dt)
{
	return true;
}

bool Scene::PostUpdate()
{
	return true;
}

bool Scene::CleanUp()
{
	return true;
}

void Scene::InitScene()
{

}

void Scene::DrawScene()
{

}

SDL_Texture* Scene::SceneToTexture()
{
	SDL_Texture* ret = nullptr;

	return ret;
}

void Scene::ExecuteTransition()
{

}