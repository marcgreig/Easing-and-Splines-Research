#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Fonts.h"
#include "j1Scene.h"
#include "j1Player.h"
#include "EasingFunctions.h"

j1Scene::j1Scene() : j1Module()
{
	name.assign("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	bool ret = true;

	for (pugi::xml_node stage = config.child("map_name"); stage; stage = stage.next_sibling("map_name"))
	{
		std::string* StageName = new std::string(stage.attribute("path").as_string());
		StageList.push_back(StageName);
	}

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	// --- Loading map ---

	App->map->Load(StageList.front()->data());

	debug_tex = App->tex->Load("maps/path2.png");

	speedX = 0;

	total_iterations = 300;

	pointA = { -500, 500 };
	pointB = { 400, 500 };


	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	
	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN) {
		SetCameraToPoint(pointB);
	}
	
	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN) {
		SetCameraToPoint(pointA);
		iterations = 0;
		easing_active = true;
	}
	
	if (easing_active == true)
	App->render->camera.x -= EaseCameraBetweenPoints(pointA, pointB) * dt;
	// for debugging purposes
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) {
		App->render->camera.y += 5;
	}
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) {
		App->render->camera.y -= 5;
	}
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) {
		App->render->camera.x += 5;
	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
		App->render->camera.x -= 5;
	}
	if (App->input->GetKey(SDL_SCANCODE_0) == KEY_DOWN) {
		App->render->camera.x = 0;
	}	

	App->map->Draw();

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;
	App->render->Blit(App->player->graphics, pointA.x, pointA.y);

	App->render->Blit(App->player->graphics2, pointB.x, pointB.y);

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	std::vector<std::string*>().swap(StageList);

	return true;
}

bool j1Scene::SetCameraToPoint(iPoint position)
{

	App->render->camera.x = App->win->screen_surface->w / 2 - position.x;
	
	App->render->camera.y = App->win->screen_surface->h / 2 - position.y;
	

	return true;
}

float j1Scene::EaseCameraBetweenPoints(iPoint posA, iPoint posB)
{
	float value = function.backEaseOut(iterations, posA.x, posB.x - posA.x, total_iterations);
	
	
	//speedY = function.linearEaseNull(iterations, 472, 572, 300);

	//App->render->camera.y += speedY;

	if (iterations < total_iterations)
	iterations++;

	else iterations = 0;

	return value;
}




