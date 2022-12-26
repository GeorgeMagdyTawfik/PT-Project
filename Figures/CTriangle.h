#pragma once
#include"CFigure.h"
class CTriangle:public CFigure
{
private:
	Point p1;
	Point p2;
	Point p3;
public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CheckInside(int X, int Y) const;
	float CalcArea(Point A, Point B, Point C) const;
	float GetMyArea() const;
	virtual void PrintInfo(Output* pOut);
};

