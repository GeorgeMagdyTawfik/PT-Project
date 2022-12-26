#include "CFigure.h"

int CFigure::NumberOfFigures = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;

	NumberOfFigures++;
  
	if (FilledAsDefault)
		FigGfxInfo.isFilled = true;
}

CFigure::CFigure()
{
	Selected = false;
}

int CFigure::FigCount = 0;
bool CFigure::FilledAsDefault = false;

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
color CFigure::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}
void CFigure::SetFilledAsDefault()
{
	FilledAsDefault = true;
}
color CFigure::DecodeColor(string s) const
{
	if (s == "BLACK")
		return BLACK;
	if (s == "RED")
		return RED;
	if (s == "ORANGE")
		return ORANGE;
	if (s == "YELLOW")
		return color(255, 215, 0);
	if (s == "BLUE")
		return color(0, 87, 231);
	if (s == "GREEN")
		return color(0, 135, 68);
}
string CFigure::EncodeColor(color c) const      //takes color and returns corresponding string
{
	if (c == BLACK)
		return "BLACK";
	if (c == RED)
		return "RED";
	if (c == ORANGE)
		return "ORANGE";
	if (c == color(255, 215, 0))
		return "YELLOW";
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

void CFigure::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure of ID : " + to_string(ID));
}

int CFigure::GetNumberOfFigures()
{
	return NumberOfFigures;
}