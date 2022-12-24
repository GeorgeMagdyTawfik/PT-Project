#pragma once

#include "Figures/CFigure.h"

class CSquare : public CFigure
{
private:
	Point center;

public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
};
