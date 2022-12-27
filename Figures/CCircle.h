#pragma once
#include "CFigure.h"
class CCircle:public CFigure
{
	private:
		Point center;
	    Point distance;
	public:
		CCircle(Point, Point, GfxInfo FigureGfxInfo);
		CCircle();
		virtual void Draw(Output* pOut) const;
	    virtual bool CheckInside(int X, int Y) const;
		virtual void Save(ofstream& OutFile);
		virtual void Load(ifstream& InFile);
		virtual void Move(Point destination) override;
	
};

