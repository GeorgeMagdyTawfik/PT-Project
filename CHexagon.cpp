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

	InFile >> ID >> center.x >> center.y >> center.x >> center.y
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
