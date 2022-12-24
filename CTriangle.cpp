#include "CTriangle.h"
CTriangle::CTriangle(Point point1, Point point2, Point point3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1 = point1;
	p2 = point2;
	p3 = point3;

	ID = GetFigCount();
}
CTriangle::CTriangle()
{
}
void CTriangle::Draw(Output* pOut) const
{


	pOut->DrawTraingle(p1, p2, p3, FigGfxInfo, Selected);
}

void CTriangle::Save(ofstream& OutFile)
{
	if (FigGfxInfo.DrawClr == color(0, 87, 231))
		ccode1 = "BLUE";

	if (!FigGfxInfo.isFilled)
		ccode2 = "NO_FILL";
	else
		if (FigGfxInfo.FillClr == color(0, 135, 68))
			ccode2 = "GREEN";

	OutFile << setw(10) << left << "TRIANG" << setw(5) << ID << setw(5)
		<< p1.x << setw(5) << p1.y << setw(5) << p2.x << setw(5)
		<< p2.y << setw(5) << p3.x << setw(5) << p3.y << setw(8)
		<< ccode1 << setw(8) << ccode2 << endl << endl;
}

void CTriangle::Load(ifstream& InFile)
{
	string ccode1, ccode2;

	InFile >> ID >> p1.x >> p2.y >> p2.x >> p2.y 
		>> p3.x >> p3.y >> ccode1 >> ccode2;

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
