#include "CCircle.h"


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	destance = P2;

	ID = GetFigCount();

}

CCircle::CCircle()
{
}


void CCircle::Draw(Output* pOut) const
{

	pOut->Drawcircle(center, destance, FigGfxInfo, Selected);
}

void CCircle::Save(ofstream& OutFile)
{
	if (FigGfxInfo.DrawClr == color(0, 87, 231))
		ccode1 = "BLUE";

	if (!FigGfxInfo.isFilled)
		ccode2 = "NO_FILL";
	else
		if (FigGfxInfo.FillClr == color(0, 135, 68))
			ccode2 = "GREEN";

	OutFile << setw(10) << left << "CIRCLE" << setw(5) << ID << setw(5) << center.x << setw(5)
		<< center.y << setw(5) << destance.x << setw(5) << destance.y << setw(8)
		<< ccode1 << setw(8) << ccode2 << endl << endl;
}

void CCircle::Load(ifstream& InFile)
{
	string ccode1, ccode2;

	InFile >> ID >> center.x >> center.y >> destance.x >> destance.y
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
