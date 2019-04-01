#ifndef __j1GUI_ELEMENTS_H__
#define __j1GUI_ELEMENTS_H__

#include "j1Gui.h"
#include "SDL/include/SDL.h"
#include "SDL_TTF\include\SDL_ttf.h"
#include "p2Point.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Scene.h"

class Gui_Elements
{
public:

	Gui_Elements(Element_type type, iPoint position, SDL_Rect rect, bool Visible, bool In_Game = false, Gui_Elements* Parent = nullptr, SDL_Texture* tex = nullptr);

	virtual ~Gui_Elements();

	virtual bool Awake() { return true; }

	virtual bool Start() { return true; }

	virtual bool PreUpdate() { return true; }

	virtual bool PostUpdate() { return true; }

	virtual bool CleanUp() { return true; }


	void Show_Debug_Rect();

	void ValuetoString(int value, std::string text);




public:

	Element_type type = Element_type::NONE;

	std::string text;
	SDL_Color color;
	TTF_Font* font;

	iPoint pos;
	iPoint GlobalPos;

	int Value = 0;

	SDL_Texture* texture = nullptr;
	SDL_Rect Rect;
	SDL_Rect hovering_rect;
	SDL_Rect clicking_rect;
	SDL_Rect debug_rect;

	bool hovering = false;
	bool clicking_left = false;
	bool do_action = false;
	bool dragable = false;
	bool visible = true;
	bool in_game = false;

	Gui_Elements* parent = nullptr;
	std::list <Gui_Elements*> childrens;
};

#endif //__j1GUI_ELEMENTS_H__