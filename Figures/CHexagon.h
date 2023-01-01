#pragma once
#include "CFigure.h"
class CHexagon :public CFigure
{
private:
	Point center;
	int hexagonside;

public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const override;
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& InFile) override;
	float GetHexagonArea() const;
	float CalcAreaOfTriangle(Point A, Point B, Point C) const;
	virtual bool CheckInside(int X, int Y);
	virtual void Move(Point destination) override;
	virtual Point GetCenter();
	virtual void PrintInfo(Output* pOut);
	virtual char GetMyType();
	virtual void ResizeByDragging(Point);
	
};

