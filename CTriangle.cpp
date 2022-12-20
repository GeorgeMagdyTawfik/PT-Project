#include "CTriangle.h"
CTriangle::CTriangle(Point point1, Point point2,Point point3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1 = point1;
	p2 = point2;
	p3 = point3;
}
void CTriangle::Draw(Output* pOut) const
{


	pOut->DrawTraingle(p1, p2, p3, FigGfxInfo, Selected);
}