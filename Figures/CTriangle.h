#pragma once
#include"CFigure.h"
class CTriangle:public CFigure
{
private:
	Point p1;
	Point p2;
	Point p3;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const override;
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& InFile) override;
	virtual bool CheckInside(int X, int Y) override;
	float CalcArea(Point A, Point B, Point C) const;
	float GetMyArea() const;
	virtual void Move(Point destination) override;
	virtual Point GetCenter();
	virtual void PrintInfo(Output* pOut);
	virtual char GetMyType();
	virtual void ResizeByDragging(Point);
};

