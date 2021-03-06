#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_ELLIPSE,		//Draw Ellipse
	DRAW_RHOMBUS,//Draw Rhombus
	DRAW_Colors,
	DRAW_BLACK,			//Draw with black color
	DRAW_WHITE,			//Draw with white color
	DRAW_RED,			//Draw with red color
	DRAW_BLUE,			//Draw with blue color
	DRAW_GREEN,			//Draw with green color
	SELECT,				//select
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	COPY,			//copy
	CUT,			//cut
	PASTE,			//delete
	DEL,			//Delete a figure(s)
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	RESIZE,			//resize figure
	PUSH_FRONT,		//make figure at top of other figures
	PUSH_BACK,		//make figure at the back of other figures
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	SELECTBYCOLOR,	//select by color in play mode
	SELECTBYFIGURE,	//select by type in play mode

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode

	MUTE,
	UNMUTE

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif