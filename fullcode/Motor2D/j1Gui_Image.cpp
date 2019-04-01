#include "j1Gui_Image.h"

Gui_Image::Gui_Image(Element_type type, iPoint position, SDL_Rect rect, bool Visible, bool In_Game, bool Dragable, SDL_Texture* tex, Gui_Elements* Parent) : Gui_Elements(type, position, rect, Visible, In_Game, Parent, tex)
{

	texture = tex;
	dragable = Dragable;

	if (parent != nullptr)
	{
		if (parent->type == Element_type::SLIDER)
		{
			hovering_rect = { 723, rect.y, rect.w, rect.h };
			clicking_rect = { 677, rect.y - 2, rect.w, rect.h };
			parent->Value = (((GlobalPos.x - parent->GlobalPos.x) * 100) / parent->Rect.w - rect.w) + rect.w;
		}
	}

}

Gui_Image::~Gui_Image() {}

bool Gui_Image::Awake()
{

	return true;
}

bool Gui_Image::Start()
{

	return true;
}

bool Gui_Image::PreUpdate()
{
	
	if (parent != nullptr)
	{
		GlobalPos.x = parent->GlobalPos.x + pos.x;
		GlobalPos.y = parent->GlobalPos.y + pos.y;

		if (parent->type == Element_type::SLIDER)
		{
			if (GlobalPos.x < parent->GlobalPos.x)
			{
				GlobalPos.x = parent->GlobalPos.x;
			}
			else if (GlobalPos.x > parent->GlobalPos.x + parent->Rect.w)
			{
				GlobalPos.x = parent->GlobalPos.x + parent->Rect.w;
			}

			parent->Value = (((GlobalPos.x - parent->GlobalPos.x) * 100) / parent->Rect.w - Rect.w) + Rect.w;
		}

		visible = parent->visible;
	}
	else
	{
		GlobalPos.x = pos.x;
		GlobalPos.y = pos.y;
	}

	debug_rect.x = GlobalPos.x;
	debug_rect.y = GlobalPos.y;

	return true;
}

bool Gui_Image::PostUpdate()
{
	if (visible && !in_game)
	{
		if (parent != nullptr)
		{
			if (parent->type == Element_type::SLIDER)
			{
				if (clicking_left == true)
				{
					App->render->Blit(texture, GlobalPos.x, GlobalPos.y, &clicking_rect, SDL_FLIP_NONE, 0);
				}
				else if (hovering == true)
				{
					App->render->Blit(texture, GlobalPos.x, GlobalPos.y, &hovering_rect, SDL_FLIP_NONE, 0);
				}
				else
				{
					App->render->Blit(texture, GlobalPos.x, GlobalPos.y, &Rect, SDL_FLIP_NONE, 0);
				}
			}
			else
			{
				App->render->Blit(texture, GlobalPos.x, GlobalPos.y, &Rect, SDL_FLIP_NONE, 0);
			}
		}
		else
		{
			App->render->Blit(texture, GlobalPos.x, GlobalPos.y, &Rect, SDL_FLIP_NONE, 0);
		}
	
	}

	return true;
}

bool Gui_Image::CleanUp()
{

	return true;
}