#pragma once
#include "Figures/CFigure.h"
class CHexagon :public CFigure
{
private:
	Point center;

public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
};

