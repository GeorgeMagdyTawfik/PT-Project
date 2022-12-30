#pragma once
#include "CFigure.h"
class CHexagon :public CFigure
{
private:
	Point center;

public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const override;
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& InFile) override;
	float GetHexagonArea() const;
	float CalcAreaOfTriangle(Point A, Point B, Point C) const;
	virtual bool CheckInside(int X, int Y) const;
	virtual CFigure* getfigure();
	virtual void Move(Point destination) override;
	virtual Point GetCenter();
	virtual void PrintInfo(Output* pOut);
	virtual CFigure*getpointerfig();
	virtual char GetMyType();
	
};

