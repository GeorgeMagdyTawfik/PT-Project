#pragma once
#include "Figures/CFigure.h"
class CCircle:public CFigure
{
	private:
		Point center;
		Point destance;
	public:
		CCircle(Point, Point, GfxInfo FigureGfxInfo);
		virtual void Draw(Output* pOut) const;
};


