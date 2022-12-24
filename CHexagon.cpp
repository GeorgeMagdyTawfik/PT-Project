#include "CHexagon.h"
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;

	ID = GetFigCount();

}

CHexagon::CHexagon()
{
}


void CHexagon::Draw(Output* pOut) const
{

	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}

void CHexagon::Save(ofstream& OutFile)
{
	if (FigGfxInfo.DrawClr == color(0, 87, 231))
		ccode1 = "BLUE";

	if (!FigGfxInfo.isFilled)
		ccode2 = "NO_FILL";
	else
		if (FigGfxInfo.FillClr == color(0, 135, 68))
			ccode2 = "GREEN";

	OutFile << setw(10) << left << "HEXAGON" << setw(5) << ID << setw(5) << center.x << setw(5)
		<< center.y << setw(8) << ccode1 << setw(8) << ccode2 << endl << endl;
}

void CHexagon::Load(ifstream& InFile)
{
	string ccode1, ccode2;

	InFile >> ID >> center.x >> center.y >> ccode1 >> ccode2;

	if (ccode1 == "BLUE")
		FigGfxInfo.DrawClr = color(0, 87, 231);

	if (ccode2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		if (ccode2 == "GREEN")
			FigGfxInfo.FillClr = color(0, 135, 68);
	}
}
