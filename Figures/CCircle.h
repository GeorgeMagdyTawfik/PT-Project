#pragma once
#include "CFigure.h"
class CCircle:public CFigure
{
private:
	Point center;
	Point distance;
	int Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CheckInside(int X, int Y) const;
	virtual void PrintInfo(Output* pOut);
};


