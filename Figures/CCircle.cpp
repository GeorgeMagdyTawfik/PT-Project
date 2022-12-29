#include "CCircle.h"


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	distance = P2;
	Radius = sqrt(
		pow(P1.x - P2.x, 2)
		+
		pow(P1.y - P2.y, 2)
	);
	ID = GetNumberOfFigures();
}

CCircle::CCircle()
{
}

void CCircle::Draw(Output* pOut) const
{
		
	pOut->Drawcircle(center, distance, FigGfxInfo, Selected);
}

bool CCircle::CheckInside(int X, int Y) const
{
	// distance from clicked point to the center
	int d = sqrt(
		pow(center.x - X, 2)
		+
		pow(center.y - Y, 2)
	);
	return (d <= Radius);
}

void CCircle::PrintInfo(Output* pOut)
{
	string msg = "Circle : ID = " + to_string(ID);
	msg += ", Center(" + to_string(center.x) + ", " + to_string(center.y) + ") , Radius = " +
		to_string(Radius);
	pOut->PrintMessage(msg);
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << setw(10) << left << "CIRCLE" << setw(5) << ID << setw(5) << center.x << setw(5)
		<< center.y << setw(5) << distance.x << setw(5) << distance.y << setw(8)
		<< EncodeColor(FigGfxInfo.DrawClr);

	if (!FigGfxInfo.isFilled)
		OutFile << setw(8) << "NO_FILL" << endl << endl;
	else
		OutFile << setw(8) << EncodeColor(FigGfxInfo.FillClr) << endl << endl;
}

void CCircle::Load(ifstream& InFile)
{
	string color1, color2;

	InFile >> ID >> center.x >> center.y >> distance.x >> distance.y
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
CFigure* CCircle::getfigure()
{
	return this;
}

void CCircle::Move(Point destination)
{
	Point RadialPoint;
	
	RadialPoint.x = destination.x + abs(center.x - distance.x);
	RadialPoint.y = destination.y + abs(center.y - distance.y);

	center = destination;
	distance = RadialPoint;
}
Point CCircle::GetCenter()
{
	return center;
}