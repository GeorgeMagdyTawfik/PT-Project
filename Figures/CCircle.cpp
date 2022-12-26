#include "CCircle.h"


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	distance = P2;
	Radius = sqrt(
		pow(P1.x - P2.x, 2)
		+
		pow(P1.y - P2.y, 2)
	);
	ID = GetNumberOfFigures();
}


void CCircle::Draw(Output* pOut) const
{
		
	pOut->Drawcircle(center, distance, FigGfxInfo, Selected);
}

bool CCircle::CheckInside(int X, int Y) const
{
	// distance from clicked point to the center
	int d = sqrt(
		pow(center.x - X, 2)
		+
		pow(center.y - Y, 2)
	);

	return (d <= Radius);
}

void CCircle::PrintInfo(Output* pOut)
{
	string msg = "Circle : ID = " + to_string(ID);
	msg += ", Center(" + to_string(center.x) + ", " + to_string(center.y) + ") , Radius = " +
		to_string(Radius);
	pOut->PrintMessage(msg);
}