#include "SceneManager.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Render.h"
#include "Input.h"
#include "Log.h"

SceneManager::SceneManager() : current_scene(nullptr)
{
	name = "sceneManager";
}

SceneManager::~SceneManager()
{

}

bool SceneManager::Awake(pugi::xml_node& config)
{
	bool ret = true;
	
	ScenePushbacks();
	
	LoadInitialScene();

	current_scene->Awake(config);

	return ret;
}

bool SceneManager::Start()
{
	bool ret = true;

	current_scene->Start();

	return ret;
}

bool SceneManager::PreUpdate()
{
	bool ret = true;

	current_scene->PreUpdate();

	return ret;
}

bool SceneManager::Update(float dt)
{
	bool ret = true;

	current_scene->Update(dt);

	return ret;
}

bool SceneManager::PostUpdate()
{
	bool ret = true;

	current_scene->PostUpdate();

	if (app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
	{
		ret = false;
	}

	return ret;
}

bool SceneManager::CleanUp()
{
	bool ret = true;

	ListItem<Scene*>* item = scenes.start;

	while (item != NULL)
	{
		RELEASE(item->data);
		item = item->next;
	}
	scenes.Clear();

	return ret;
}

// -------------- SCENE MANAGEMENT METHODS --------------
void SceneManager::LoadInitialScene()
{
	current_scene = scenes.start->data;
}

void SceneManager::SwitchScene(SCENES scene_name)
{	
	current_scene->CleanUp();

	ListItem<Scene*>* item = scenes.start;

	while (item != NULL)
	{
		if (item->data->scene_name == scene_name)
		{
			current_scene = item->data;
		}
		item = item->next;
	}

	if (current_scene != nullptr)
	{
		current_scene->Start();
	}
}

void SceneManager::LoadScene(SCENES scene_name)
{
	ListItem<Scene*>* item = scenes.start;

	while (item != NULL)
	{
		if (item->data->scene_name == scene_name)
		{
			if (next_scene == nullptr)
			{
				next_scene = item->data;
			}
			else
			{
				next_scene->CleanUp();

				next_scene = item->data;
			}
		}
		item = item->next;
	}

	next_scene->Start();
}

void SceneManager::UnloadScene(Scene* scene_to_unload)
{
	ListItem<Scene*>* item = scenes.start;

	while (item != NULL)
	{
		if (item->data == scene_to_unload)
		{
			if (item->data == current_scene)
			{
				if (next_scene != nullptr)
				{
					Scene* tmp = current_scene;

					current_scene = next_scene;

					next_scene = tmp;

					tmp = nullptr;

					next_scene->CleanUp();

					next_scene = nullptr;
				}
				else
				{
					LOG("UNLOAD SCENE ERROR: Two scenes were not active at the same time.");
				}

				break;
			}
			else
			{
				if (current_scene != nullptr)
				{
					item->data->CleanUp();

					next_scene = nullptr;
				}
				else
				{
					LOG("UNLOAD SCENE ERROR: Two scenes were not active at the same time.");
				}

				break;
			}
		}
		item = item->next;
	}
}

// ---------------- CREATE SCENE METHODS ----------------
Scene* SceneManager::CreateScene(SCENES scene_name)
{
	Scene* item = nullptr;

	switch (scene_name)
	{
	case SCENES::SCENE1:

		item = new Scene1();
		
		break;

	case SCENES::SCENE2:
		
		item = new Scene2();
		
	break;
	}

	if (item != nullptr)
	{
		scenes.Add(item);
	}

	return item;
}

void SceneManager::ScenePushbacks()
{
	CreateScene(SCENES::SCENE1);
	CreateScene(SCENES::SCENE2);
}