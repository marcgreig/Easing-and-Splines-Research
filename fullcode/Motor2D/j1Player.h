#ifndef __j1Player_H__
#define __j1Player_H__

#include "j1Module.h"
#include "p2Point.h"

struct SDL_Texture;

class j1Player :public j1Module
{
public:

	j1Player();
	~j1Player();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	bool UpdateTick(float dt);

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();


public:

	iPoint position = {0,0};
	iPoint position2 = {0,0};

	//uint speed, health, armor, strength = 0;

	SDL_Texture * graphics = nullptr;
	SDL_Texture * graphics2 = nullptr; 

};

#endif // __j1Player_H__
