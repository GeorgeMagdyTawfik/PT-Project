#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

CFigure::CFigure()
{
	Selected = false;
}

int CFigure::FigCount = 0;

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
color CFigure::DecodeColor(string s) const
{
	if (s == "BLUE")
		return color(0, 87, 231);
	if (s == "GREEN")
		return color(0, 135, 68);
}
string CFigure::EncodeColor(color c) const      //takes color and returns corresponding string
{
	if (c == color(0, 87, 231))
		return "BLUE";
	if (c == color(0, 135, 68))
		return "GREEN";
}

int CFigure::GetFigCount()
{
	FigCount++;
	return FigCount;
}

