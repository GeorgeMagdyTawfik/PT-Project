#pragma once
#include "CFigure.h"
class CCircle:public CFigure
{
	private:
		Point center;
	    Point distance;
	public:
		CCircle(Point, Point, GfxInfo FigureGfxInfo);
		virtual void Draw(Output* pOut) const;
	    virtual bool CheckInside(int X, int Y) const;
	CCircle();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	virtual CFigure* getfigure();
		CCircle();
		virtual void Draw(Output* pOut) const override;
	    virtual bool CheckInside(int X, int Y) const override;
		virtual void Save(ofstream& OutFile) override;
		virtual void Load(ifstream& InFile) override;
		virtual void Move(Point destination) override;
	
};

