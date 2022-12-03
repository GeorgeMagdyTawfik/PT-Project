#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if( (Key == 8) && (Label.size() >= 1) )	//BackSpace is pressed
			Label.resize(Label.size() -1 );		
		//if( (Key == 8) && (Label.size() == 0))
		//	continue;
		else
			Label += Key;
		if (pO)     //I guess this is to show the user what is being typed in RT 
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SAVE_GRAPH: return SAVE_GRAPH;
			case ITM_LOAD_GRAPH: return LOAD_GRAPH;

			case ITM_START_REC: return START_REC;
			case ITM_STOP_REC: return STOP_REC; 
			case ITM_PLAY_REC: return PLAY_REC;

			case ITM_SELECT: return SELECT;
			case ITM_CHANGE_DRAWING_CLR: return CHANGE_DRAW_CLR;
			case ITM_CHANGE_FILL_CLR: return CHANGE_FILL_CLR;
			case ITM_MOVE: return MOVE;

			case ITM_DELETE: return DELETE_SHAPE;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;

			case ITM_BLACK: return BLACKCLR;
			case ITM_RED: return REDCLR;
			case ITM_ORANGE: return ORANGECLR;
			case ITM_YELLOW: return YELLOWCLR;
			case ITM_GREEN: return GREENCLR;
			case ITM_BLUE: return BLUECLR;
			case ITM_CLEARALL: return CLEAR_ALL;

			case ITM_RECT: return DRAW_RECT;
			
			case ITM_SQUARE: return DRAW_SQUARE;
			
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEXAGON: return DRAW_HEXAGON;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_EXIT: return EXIT;	
			case ITM_SWITCH: return TO_PLAY;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int clickedItm = (x / UI.MenuItemWidth);

			switch (clickedItm)
			{
			case ITM_SWITCH_BACK: return TO_DRAW;
			case ITM_PICK_AND_HIDE: return PICK_AND_HIDE;
			case ITM_PICK_BY_TYPE: return PICK_BY_TYPE;
			case ITM_PICK_BY_CLR: return PICK_BY_CLR;
			case ITM_PICK_BY_TYPE_AND_CLR: return PICK_BY_TYPE_AND_CLR;
			case ITM_RESTART: return RESTART;

			default: return EMPTY;
			}
		}
		//return TO_PLAY;	just for now. This should be updated

		// User clicks on the drawing area 
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		// User clicks on the status bar
		return STATUS;
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
