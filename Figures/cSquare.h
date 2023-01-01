#pragma once

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point center;
	int squareside;

public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	virtual bool CheckInside(int X, int Y);

	virtual Point GetCenter();
	virtual void Move(Point destination) override;
	virtual void PrintInfo(Output* pOut);
	virtual char GetMyType();
	virtual void ResizeByDragging(Point);
};
