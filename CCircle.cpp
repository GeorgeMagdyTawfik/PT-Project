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
	OutFile << setw(10) << left << "CIRCLE" << setw(5) << ID << setw(5) << center.x << setw(5)
		<< center.y << setw(5) << destance.x << setw(5) << destance.y << setw(8)
		<< EncodeColor(FigGfxInfo.DrawClr);

	if (!FigGfxInfo.isFilled)
		OutFile << setw(8) << "NO_FILL" << endl << endl;
	else
		OutFile << setw(8) << EncodeColor(FigGfxInfo.FillClr) << endl << endl;
}

void CCircle::Load(ifstream& InFile)
{
	string color1, color2;

	InFile >> ID >> center.x >> center.y >> destance.x >> destance.y
		>> color1 >> color2;

	FigGfxInfo.DrawClr = DecodeColor(color1);

	if (color2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = DecodeColor(color2);
	}
}
