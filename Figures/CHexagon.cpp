#include "CHexagon.h"
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	ID = GetNumberOfFigures();
	hexagonside = 50;
}

CHexagon::CHexagon()
{
	hexagonside = 50;
}


void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHexagon(center, FigGfxInfo, hexagonside, Selected);
}

float CHexagon::GetHexagonArea() const
{
	int side = 50; /// We have aggreed on this 
	return 1.5 * sqrt(3) * pow(side, 2);
}

float CHexagon::CalcAreaOfTriangle(Point A, Point B, Point C) const
{
	return (1.0 / 2) * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

bool CHexagon::CheckInside(int X, int Y)
{
	int l = 50; /// We agreed on this as the side length of the hexagon
	Point c = center;
	
	Point p; // clicked point
	p.x = X;
	p.y = Y;

	Point P1, P2, P3, P4, P5, P6; // hexagon vertices
	P1.x = c.x + l / 2;
	P1.y = c.y - 0.5 * sqrt(3) * l;

	P2.x = c.x + l;
	P2.y = c.y;

	P3.x = P1.x;
	P3.y = c.y + 0.5 * sqrt(3) * l;

	P4.x = c.x - l / 2;
	P4.y = P3.y;

	P5.x = c.x - l;
	P5.y = c.y;

	P6.x = P4.x;
	P6.y = P1.y;

	float SubTriangleAreas[6];
	SubTriangleAreas[0] = CalcAreaOfTriangle(p, P1, P2);
	SubTriangleAreas[1] = CalcAreaOfTriangle(p, P2, P3);
	SubTriangleAreas[2] = CalcAreaOfTriangle(p, P3, P4);
	SubTriangleAreas[3] = CalcAreaOfTriangle(p, P4, P5);
	SubTriangleAreas[4] = CalcAreaOfTriangle(p, P5, P6);
	SubTriangleAreas[5] = CalcAreaOfTriangle(p, P6, P1);

	float sumAreas = 0;
	for (int i = 0; i < 6; i++)
	{
		sumAreas += SubTriangleAreas[i];
	}

	return abs(GetHexagonArea() - sumAreas) < 30;
}

void CHexagon::Move(Point destination)
{
	center = destination;
}

void CHexagon::PrintInfo(Output* pOut)
{
	string msg = "Hexagon : ID = " + to_string(ID);
	msg += ", Center (" + to_string(center.x) + ", " + to_string(center.y) + ") , side length = 50 , area = "
		+ to_string((int)GetHexagonArea());
	pOut->PrintMessage(msg);
}


char CHexagon::GetMyType()
{
	return 'h';
}

void CHexagon::ResizeByDragging(Point NewLocation)
{
	hexagonside = sqrt(pow(center.x - NewLocation.x, 2) + pow(center.y - NewLocation.y, 2));
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << setw(10) << left << "HEXAGON" << setw(5) << ID << setw(5) << center.x
		<< setw(5) << center.y << setw(8) << EncodeColor(FigGfxInfo.DrawClr);

	if (!FigGfxInfo.isFilled)
		OutFile << setw(8) << "NO_FILL" << endl << endl;
	else
		OutFile << setw(8) << EncodeColor(FigGfxInfo.FillClr) << endl << endl;
}

void CHexagon::Load(ifstream& InFile)
{
	string color1, color2;

	InFile >> ID >> center.x >> center.y >> color1 >> color2;

	FigGfxInfo.DrawClr = DecodeColor(color1);
	UpdateFigGfxDrawClr(FigGfxInfo.DrawClr);

	if (color2 == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		UnfillFigGfxInfo();
	}
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = DecodeColor(color2);
		UpdateFigGfxFillClr(FigGfxInfo.FillClr);
	}
}

Point CHexagon::GetCenter()
{
	return center;
}
