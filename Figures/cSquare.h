#pragma once

#include "CFigure.h"

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
	virtual bool CheckInside(int X, int Y) const;
	virtual CFigure* getfigure();
	virtual void Draw(Output* pOut) const override;
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& InFile) override;
	virtual bool CheckInside(int X, int Y) const override;
	virtual void Move(Point destination) override;
};
