#pragma once
#include "CFigure.h"
class CHexagon :public CFigure
{
private:
	Point center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

