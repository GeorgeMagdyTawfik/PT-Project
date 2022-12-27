#include "CSquare.h"

CSquare::CSquare( Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P;

	ID = GetFigCount();
}

CSquare::CSquare()
{
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSquare(center, FigGfxInfo, Selected);
}

bool CSquare::CheckInside(int X, int Y) const
{
	//I have Point center
	Point corner1, corner2;
	corner1.x = center.x - 50;
	corner1.y = center.y - 50;
	corner2.x = center.x + 50;
	corner2.y = center.y + 50;

	return
	(
		X >= corner1.x
		&& X <= corner2.x
		&& Y >= corner1.y
		&& Y <= corner2.y
	);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << setw(10) << left << "SQUARE" << setw(5) << ID << setw(5) << center.x
		<< setw(5) << center.y << setw(8) << EncodeColor(FigGfxInfo.DrawClr);

	if (!FigGfxInfo.isFilled)
		OutFile << setw(8) << "NO_FILL" << endl << endl;
	else
		OutFile << setw(8) << EncodeColor(FigGfxInfo.FillClr) << endl << endl;
}

void CSquare::Load(ifstream& InFile)
{
	string color1, color2;

	InFile >> ID >> center.x >> center.y >> color1 >> color2;

	FigGfxInfo.DrawClr = DecodeColor(color1);

	if (color2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = DecodeColor(color2);
	}
}

void CSquare::Move(Point destination)
{
	center = destination;
}
