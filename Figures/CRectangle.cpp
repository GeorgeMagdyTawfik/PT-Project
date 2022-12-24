#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::CheckInside(int x, int y) const
{
	// UPPERLEFT, BOTTOMRIGHT
	Point UL, BR;

	UL.x = (Corner1.x < Corner2.x) ? Corner1.x : Corner2.x;
	UL.y = (Corner1.y < Corner2.y) ? Corner1.y : Corner2.y;

	BR.x = (Corner2.x > Corner1.x) ? Corner2.x : Corner1.x;
	BR.y = (Corner2.y > Corner1.y) ? Corner2.y : Corner1.y;

	return
		(
			x >= UL.x
		&&	x <= BR.x
		&&	y >= UL.y
		&&	y <= BR.y
		);
}