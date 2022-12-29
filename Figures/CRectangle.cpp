#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

	ID = GetFigCount();
}

CRectangle::CRectangle()
{
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << setw(10) << left << "RECT" << setw(5) << ID << setw(5) << Corner1.x << setw(5)
		<< Corner1.y << setw(5) << Corner2.x << setw(5) << Corner2.y << setw(8)
		<< EncodeColor(FigGfxInfo.DrawClr);

	if (!FigGfxInfo.isFilled)
		OutFile << setw(8) << "NO_FILL" << endl << endl;
	else
		OutFile << setw(8) << EncodeColor(FigGfxInfo.FillClr) << endl << endl;
}

void CRectangle::Load(ifstream& InFile)
{
	string color1, color2;

	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y
		>> color1 >> color2;

	FigGfxInfo.DrawClr = DecodeColor(color1);

	if (color2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = DecodeColor(color2);
	}
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
CFigure* CRectangle::getfigure()
{
	return this;
}


void CRectangle::Move(Point destination)
{
	int height, width;

	height = abs(Corner1.y - Corner2.y);
	width = abs(Corner1.x - Corner2.x);

	Corner1.x = destination.x - width/2;
	Corner2.x = destination.x + width/2;

	Corner1.y = destination.y - height/2;
	Corner2.y = destination.y + height/2;
}
Point CRectangle::GetCenter()
{
	Point c;
	c.x = (Corner1.x + Corner2.x) / 2;
	c.y= (Corner1.y + Corner2.y) / 2;
	return c;
}