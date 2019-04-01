#include "j1Player.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Input.h"
#include "p2Log.h"

j1Player::j1Player(): j1Module()
{
	name.assign("player");
}

j1Player::~j1Player()
{
}

bool j1Player::Awake()
{	
	return true;
}

bool j1Player::Start()
{
	graphics = App->tex->Load("textures/character.png");
	graphics2 = App->tex->Load("textures/character2.png"); 


	position.x = -400;
	position.y = 700;

	position2.x = 600; 
	position2.y = 400; 
	
	return true;
}

bool j1Player::PreUpdate()
{
	return true;
}


bool j1Player::Update(float dt)
{
	

	return true;
}

bool j1Player::PostUpdate()
{

	return true;
}

bool j1Player::CleanUp()
{
	App->tex->UnLoad(graphics);
	App->tex->UnLoad(graphics2); 

	return true;
}
