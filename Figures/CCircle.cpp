#include "CCircle.h"


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	distance = P2;
}


void CCircle::Draw(Output* pOut) const
{
		
	pOut->Drawcircle(center, distance, FigGfxInfo, Selected);
}

bool CCircle::CheckInside(int X, int Y) const
{
	Point C = center;
	Point A = distance; // DISTANCE : a point on the circle's circumference
	int radius = sqrt(
		pow(C.x - A.x, 2)
		+
		pow(C.y - A.y, 2)
	);

	// distance from clicked point to the center
	int d = sqrt(
		pow(C.x - X, 2)
		+
		pow(C.y - Y, 2)
	);
		
	return (d <= radius);
}