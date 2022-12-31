#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,

	DRAW_TRIANGLE,
	DRAW_HEXAGON,
	DRAW_CIRCLE,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY_DRAW,			//A click on empty place in the DRAW toolbar
	EMPTY_PLAY,         //A click on an empty area in the PLAY toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar

	///TODO: Add the other action types of the two modes

	//Draw Mode actions
	SAVE_GRAPH,
	LOAD_GRAPH,
	START_REC,
	STOP_REC,
	PLAY_REC,
	SELECT,
	CHANGE_DRAW_CLR,
	CHANGE_FILL_CLR,
	MOVE,
	DELETE_SHAPE,
	UNDO,
	REDO,
	BLACKCLR,
	REDCLR,
	ORANGECLR,
	YELLOWCLR,
	GREENCLR,
	BLUECLR,
	CLEAR_ALL,
	SOUND,

	//Play mode actions
	SWITCH_BACK,
	PICK_BY_TYPE,
	PICK_BY_CLR,
	PICK_BY_TYPE_AND_CLR,
	
};

enum FillColors
{
	black,
	red,
	orange,
	yellow,
	green,
	blue,
	UNFILLED
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif