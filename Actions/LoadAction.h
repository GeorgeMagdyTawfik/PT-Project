#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class LoadAction : public Action
{
	Output* pOut;
	Input* pIn;
	ifstream InFile;
	string filename;

	string ccode1, ccode2;
	int FigCount;
	string FigName;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
	~LoadAction();
};

