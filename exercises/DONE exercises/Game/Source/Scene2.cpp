#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene2.h"
#include "SceneManager.h"
#include "Transition.h"
#include "TransitionManager.h"

#include "Defs.h"
#include "Log.h"

Scene2::Scene2() : Scene(SCENES::SCENE2)
{

}

// Destructor
Scene2::~Scene2()
{

}

// Called before render is available
bool Scene2::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene 2");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene2::Start()
{
	//app->audio->PlayMusic("Assets/Audio/Music/music_spy.ogg");

	InitScene();
	return true;
}

// Called each loop iteration
bool Scene2::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene2::Update(float dt)
{
	DrawScene();
	return true;
}

// Called each loop iteration
bool Scene2::PostUpdate()
{
	bool ret = true;

	ExecuteTransition();

	return ret;
}

// Called before quitting
bool Scene2::CleanUp()
{
	LOG("Freeing scene");

	app->tex->UnLoad(scene_texture);

	if (scene_texture != nullptr)
	{
		app->tex->UnLoad(scene_texture);
	}

	//if (SDL_RenderClear(scene_renderer) == 0)
	//{
	//	scene_renderer = nullptr;
	//}

	if (scene_surface != nullptr)
	{
		SDL_FreeSurface(scene_surface);
	}

	return true;
}

void Scene2::InitScene()
{
	uint w, h;
	scene_texture = app->tex->Load("Assets/Textures/scene2.png"/*, scene_renderer*/);
	app->win->GetWindowSize(w,h);
	map_width = w;
	map_height = h;
}

void Scene2::DrawScene()
{
	app->render->DrawTexture(scene_texture, 0, 0);
}

SDL_Texture* Scene2::SceneToTexture()
{
	//app->render->CreateSubRenderer(map_width, map_height, scene_surface/*, scene_renderer*/);
	//scene_texture = app->tex->Load("Assets/Textures/scene2.png"/*, scene_renderer*/);

	//app->render->DrawTexture(scene_texture, 0, 0/*, scene_renderer*/);
	scene_pretransition_texture = SDL_CreateTextureFromSurface(app->render->renderer, scene_surface);

	return scene_pretransition_texture;
}

void Scene2::ExecuteTransition()
{
	if (!app->transitionManager->is_transitioning)
	{
		if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
		{
			app->transitionManager->CreateCut(SCENES::SCENE1);
		}

		if (app->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
		{
			app->transitionManager->CreateFadeToColour(SCENES::SCENE1);
		}

		if (app->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
		{
			app->transitionManager->CreateSlide(SCENES::SCENE1, 0.5f, true);
		}

		if (app->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN)
		{
			app->transitionManager->CreateSlide(SCENES::SCENE1, 0.5f, true, true);
		}

		if (app->input->GetKey(SDL_SCANCODE_5) == KEY_DOWN)
		{
			app->transitionManager->CreateWipe(SCENES::SCENE1, 0.5f, true);
		}

		if (app->input->GetKey(SDL_SCANCODE_6) == KEY_DOWN)
		{
			app->transitionManager->CreateWipe(SCENES::SCENE1, 0.5f, true, true);
		}

		if (app->input->GetKey(SDL_SCANCODE_7) == KEY_DOWN)
		{
			app->transitionManager->CreateAlternatingBars(SCENES::SCENE1, 0.5f, true);
		}

		if (app->input->GetKey(SDL_SCANCODE_8) == KEY_DOWN)
		{
			app->transitionManager->CreateExpandingBars(SCENES::SCENE1, 0.5f, true);
		}

		if (app->input->GetMouseButtonDown(SDL_BUTTON_RIGHT) == KEY_DOWN)
		{
			iPoint mouse_pos;
			app->input->GetMousePosition(mouse_pos.x, mouse_pos.y);

			app->transitionManager->CreateZoomToMouse(SCENES::SCENE1, mouse_pos, 0.5f, true);
		}

		if (app->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN)
		{
			iPoint mouse_pos;
			app->input->GetMousePosition(mouse_pos.x, mouse_pos.y);

			app->transitionManager->CreateCameraToMouse(mouse_pos, 0.5f, true);
		}

		//if (app->input->GetKey(SDL_SCANCODE_9) == KEY_DOWN)
		//{
		//	if (scene_texture != nullptr)
		//	{
		//		app->transitionManager->CreateDissolve(SCENES::SCENE1, 1.0f);
		//	}
		//}

		//if (app->input->GetMouseButtonDown(SDL_BUTTON_MIDDLE) == KEY_DOWN)
		//{
		//	iPoint mouse_pos;
		//	app->input->GetMousePosition(mouse_pos.x, mouse_pos.y);

		//	if (scene_texture != nullptr)
		//	{
		//		app->transitionManager->CreateZoomToTexture(SCENES::SCENE1, mouse_pos);
		//	}
		//}
	}
}