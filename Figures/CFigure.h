#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Base class for all figures
class CFigure
{
	static int FigCount;
	static bool FilledAsDefault;

protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	color GetDrawClr();             //returns the figure's drawing color
	color GetFillClr();

	void SetFilledAsDefault(); //sets filled as the default for figures

	string EncodeColor(color c) const; //takes color and returns corresponding string
	color DecodeColor(string s) const; //takes string and returns corresponding color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	static int GetFigCount();

	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& InFile) = 0;	//Load the figure parameters to the file

	virtual void Move(Point dest) = 0;

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	
	// To check whether a point belongs to the shape's area or not 
	virtual bool CheckInside(int x, int y) const = 0; /// pure virtual function (overridden in each class)
};

#endif