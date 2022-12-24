#pragma once
#include "CFigure.h"
class CHexagon :public CFigure
{
private:
	Point center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	float GetHexagonArea() const;
	float CalcAreaOfTriangle(Point A, Point B, Point C) const;
	virtual bool CheckInside(int X, int Y) const;
};

