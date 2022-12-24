#pragma once
#include "Figures/CFigure.h"
class CCircle :public CFigure
{
private:
	Point center;
	Point destance;

public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
};

