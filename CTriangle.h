#pragma once
#include"Figures/CFigure.h"
class CTriangle :public CFigure
{
private:
	Point p1;
	Point p2;
	Point p3;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);





};

