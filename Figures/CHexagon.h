#pragma once
#include "CFigure.h"
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
	float GetHexagonArea() const;
	float CalcAreaOfTriangle(Point A, Point B, Point C) const;
	virtual bool CheckInside(int X, int Y) const;
	virtual void PrintInfo(Output* pOut);
};

