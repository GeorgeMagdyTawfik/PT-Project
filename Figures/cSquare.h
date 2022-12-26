#pragma once

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CheckInside(int X, int Y) const;
	virtual void PrintInfo(Output* pOut);
};
