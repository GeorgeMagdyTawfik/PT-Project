#include "CTriangle.h"
CTriangle::CTriangle(Point point1, Point point2,Point point3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
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

float CTriangle::CalcArea(Point A, Point B, Point C) const
{
	return (1.0 / 2) * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

float CTriangle::GetMyArea() const
{
	return CalcArea(p1, p2, p3);
}

bool CTriangle::CheckInside(int X, int Y) const
{
	// the point clicked
	Point p;
	p.x = X;
	p.y = Y;

	float A1 = CalcArea(p, p1, p2);
	float A2 = CalcArea(p, p2, p3);
	float A3 = CalcArea(p, p3, p1);

	return (GetMyArea() == A1 + A2 + A3);
}


void CTriangle::Save(ofstream& OutFile)
{
	OutFile << setw(10) << left << "TRIANG" << setw(5) << ID << setw(5) << p1.x << setw(5)
		<< p1.y << setw(5) << p2.x << setw(5) << p2.y << setw(5) << p3.x << setw(5) << p3.y
		<< setw(8) << EncodeColor(FigGfxInfo.DrawClr);

	if (!FigGfxInfo.isFilled)
		OutFile << setw(8) << "NO_FILL" << endl << endl;
	else
		OutFile << setw(8) << EncodeColor(FigGfxInfo.FillClr) << endl << endl;
}

void CTriangle::Load(ifstream& InFile)
{
	string color1, color2;

	InFile >> ID >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y
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
CFigure* CTriangle::getfigure()
{
	return this;
}