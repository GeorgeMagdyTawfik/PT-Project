#include "CSquare.h"

CSquare::CSquare( Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P;
	ID = GetFigCount();
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSquare(center, FigGfxInfo, Selected);
}

bool CSquare::CheckInside(int X, int Y) const
{
	//I have Point center
	Point corner1, corner2;
	corner1.x = center.x - 50;
	corner1.y = center.y - 50;
	corner2.x = center.x + 50;
	corner2.y = center.y + 50;

	return
	(
		X >= corner1.x
		&& X <= corner2.x
		&& Y >= corner1.y
		&& Y <= corner2.y
	);
}

void CSquare::PrintInfo(Output* pOut)
{
	string msg = "Square : ID = " + to_string(ID);
	msg += ", Center(" + to_string(center.x) + ", " + to_string(center.y) + ")";
	msg += ", side length = 100";
	pOut->PrintMessage(msg);
}