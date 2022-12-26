#include "CTriangle.h"
CTriangle::CTriangle(Point point1, Point point2,Point point3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1 = point1;
	p2 = point2;
	p3 = point3;
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

void CTriangle::PrintInfo(Output* pOut)
{
	string msg = "Triangle -> ";
	msg += "P1 (" + to_string(p1.x) + ", " + to_string(p1.y) + ")";
	msg += " | P2 (" + to_string(p2.x) + ", " + to_string(p2.y) + ")";
	msg += " | P3 (" + to_string(p3.x) + ", " + to_string(p3.y) + ")";
	msg += " | Area = " + to_string((int)GetMyArea());
	pOut->PrintMessage(msg);
}