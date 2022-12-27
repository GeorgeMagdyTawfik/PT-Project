#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;

public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual void Draw(Output* pOut) const override;
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& InFile) override;
	virtual bool CheckInside(int x, int y) const override;
	virtual void Move(Point destination) override;
};

#endif