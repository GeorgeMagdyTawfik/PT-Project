#pragma once
#include "CFigure.h"
class CCircle:public CFigure
{
	private:
		Point center;
	    Point distance;
		int Radius;
	public:
		CCircle(Point, Point, GfxInfo FigureGfxInfo);
		CCircle();
		virtual void Draw(Output* pOut) const override;
	    virtual bool CheckInside(int X, int Y) const override;
		virtual void Save(ofstream& OutFile) override;
		virtual void Load(ifstream& InFile) override;
		virtual void Move(Point destination) override;
		CFigure* getfigure();
		virtual Point GetCenter();
		virtual void PrintInfo(Output* pOut);
		virtual CFigure* getpointerfig();
		virtual char GetMyType();
	
};	