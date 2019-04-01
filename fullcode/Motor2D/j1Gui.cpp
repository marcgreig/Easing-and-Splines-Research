#include "j1Render.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Input.h"
#include "j1Window.h"
#include "j1Gui.h"
#include "j1Gui_Elements.h"

#include "j1Gui_Image.h"
#include "j1Gui_Label.h"


j1Gui::j1Gui() : j1Module()
{
	name.assign("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.data());

	bool ret = true;


	return ret;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	bool ret = true;

	std::list <Gui_Elements*>::const_iterator item = List_elem.begin();

	Gui_Elements* pElem = NULL;

	for (; item != List_elem.end() && ret; ++item)
	{
		pElem = *item;

		ret = (*item)->PreUpdate();
	}

	return ret;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	bool ret = true;

	std::list <Gui_Elements*>::const_iterator item = List_elem.begin();

	Gui_Elements* pElem = NULL;

	for (; item != List_elem.end() && ret; ++item)
	{
		pElem = *item;

		ret = (*item)->PostUpdate();

		if (ret == false)
			break;
	}

	return ret;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	bool ret = true;

	std::list <Gui_Elements*>::const_iterator item = List_elem.begin();

	Gui_Elements* pElem = NULL;

	for (; item != List_elem.end() && ret; ++item)
	{
		pElem = *item;

		ret = (*item)->CleanUp();

		if (ret == false)
			break;
	}

	return ret;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

Gui_Elements* j1Gui::Create_Image(Element_type element, iPoint position, SDL_Rect rect, bool visible, bool In_Game, bool dragable, SDL_Texture* tex, Gui_Elements* Parent)
{
	Gui_Elements* elem = nullptr;
	elem = new Gui_Image(element, position, rect, visible, In_Game, dragable, tex, Parent);

	if (elem != nullptr)
		List_elem.push_back(elem);

	return elem;
}

Gui_Elements* j1Gui::Create_Label(Element_type element, iPoint position, bool visible, bool In_Game, std::string Text, SDL_Color Color, _TTF_Font* Font, Gui_Elements* Parent)
{
	Gui_Elements* elem = nullptr;
	elem = new Gui_Label(element, position, visible, In_Game, Text, Color, Font, Parent);

	if (elem != nullptr)
		List_elem.push_back(elem);

	return elem;
}
