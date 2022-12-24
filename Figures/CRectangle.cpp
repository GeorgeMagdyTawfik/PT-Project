#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

	ID = GetFigCount();

}

CRectangle::CRectangle()
{
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& OutFile)
{
	if (FigGfxInfo.DrawClr == color(0, 87, 231))
		ccode1 = "BLUE";

	if (!FigGfxInfo.isFilled)
		ccode2 = "NO_FILL";
	else
		if (FigGfxInfo.FillClr == color(0, 135, 68))
			ccode2 = "GREEN";

	OutFile << setw(10) << left << "RECT" << setw(5) << ID << setw(5) << Corner1.x << setw(5)
		<< Corner1.y << setw(5) << Corner2.x << setw(5) << Corner2.y << setw(8)
		<< ccode1 << setw(8) << ccode2 << endl << endl;
}

void CRectangle::Load(ifstream& InFile)
{
	string ccode1, ccode2;

	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y
		>> ccode1 >> ccode2;

	if (ccode1 == "BLUE")
		FigGfxInfo.DrawClr = color(0, 87, 231);

	if (ccode2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		if (ccode2 == "GREEN")
			FigGfxInfo.FillClr = color(0, 135, 68);
	}
}
