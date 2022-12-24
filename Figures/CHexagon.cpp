#include "CHexagon.h"
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	
}


void CHexagon::Draw(Output* pOut) const
{

	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}