#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	UL.x = (Corner1.x < Corner2.x) ? Corner1.x : Corner2.x;
	UL.y = (Corner1.y < Corner2.y) ? Corner1.y : Corner2.y;

	BR.x = (Corner2.x > Corner1.x) ? Corner2.x : Corner1.x;
	BR.y = (Corner2.y > Corner1.y) ? Corner2.y : Corner1.y;
	ID = GetFigCount();
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::CheckInside(int x, int y) const
{
	// check using upperleft and bottomright corners
	return
		(
			x >= UL.x
		&&	x <= BR.x
		&&	y >= UL.y
		&&	y <= BR.y
		);
}

void CRectangle::PrintInfo(Output* pOut)
{
	string msg = "Rectangle : ID = " + to_string(ID);
	msg += ", Start(" + to_string(UL.x) + ", " + to_string(UL.y) + ") " +
		" End (" + to_string(BR.x) + ", " + to_string(BR.y) + ")";
	msg += ", length = " + to_string(BR.x - UL.x)
		+ ", width = " + to_string(BR.y - UL.y);
	pOut->PrintMessage(msg);
}