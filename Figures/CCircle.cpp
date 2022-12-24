#include "CCircle.h"


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	destance = P2;
}


void CCircle::Draw(Output* pOut) const
{
		
	pOut->Drawcircle(center, destance, FigGfxInfo, Selected);
}