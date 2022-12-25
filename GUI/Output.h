#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawSquare(Point P1, GfxInfo squareGfxInfo, bool selected = false) const;
	void Drawcircle(Point P1, Point p2, GfxInfo circleGfxInfo, bool selected = false) const;
	void DrawTraingle(Point P1, Point P2, Point P3, GfxInfo traingleGfxInfo, bool selected = false) const;
	void DrawHexagon(Point P1, GfxInfo hexagonGfxInfo, bool selected = false) const;
	///TODO: Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	void setCrntDrawColor(color c);
	void setCrntFillColor(color c);

	string EncodeColor(color c) const; //takes color and returns corresponding name
	color DecodeColor(string s) const; //takes color name and returns corresponding color

	
	~Output();
};

#endif