#include "j1Gui_Elements.h"
#include "j1Textures.h"

Gui_Elements::Gui_Elements(Element_type Type, iPoint position, SDL_Rect rect, bool Visible, bool In_Game, Gui_Elements* Parent, SDL_Texture* tex)
{
	pos.x = position.x;
	pos.y = position.y;
	parent = Parent;
	Rect = rect;
	type = Type;


	if (parent != nullptr)
	{
		parent->childrens.push_back(this);
		visible = parent->visible;
		in_game = parent->in_game;

		GlobalPos.x = parent->GlobalPos.x + pos.x;
		GlobalPos.y = parent->GlobalPos.y + pos.y;

	}
	else
	{
		visible = Visible;
		in_game = In_Game;

		GlobalPos.x = pos.x;
		GlobalPos.y = pos.y;
	}

	debug_rect.x = GlobalPos.x;
	debug_rect.y = GlobalPos.y;
	debug_rect.w = rect.w;
	debug_rect.h = rect.h;
}

Gui_Elements::~Gui_Elements() {}

void Gui_Elements::Show_Debug_Rect()
{
	App->render->DrawQuad(debug_rect, 255, 0, 0, 255, false, false);
}

void Gui_Elements::ValuetoString(int value, std::string text)
{
	std::string s = std::to_string(value);

	std::string t("%%");

	s += t;

	text = s.c_str();

	App->tex->UnLoad(texture);

	texture = App->font->Print(text.data(), color, font);

	int width = 0, height = 0;
	App->font->CalcSize(text.data(), width, height, font);
	Rect.w = width;
	Rect.h = height;
}
