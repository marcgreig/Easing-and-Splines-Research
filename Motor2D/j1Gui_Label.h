#ifndef __j1GUI_LABEL_H__
#define __j1GUI_LABEL_H__

#include "j1Gui_Elements.h"

class Gui_Label :public Gui_Elements
{
public:
	Gui_Label(Element_type type, iPoint position, bool visible, bool In_Game, std::string Text, SDL_Color Color, TTF_Font* Font, Gui_Elements* Parent);

	~Gui_Label();

	bool Awake();

	bool Start();

	bool PreUpdate();

	bool PostUpdate();

	bool CleanUp();
};


#endif //__j1GUI_LABEL_H__