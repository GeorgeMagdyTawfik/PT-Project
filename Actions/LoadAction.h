#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class LoadAction : public Action
{
	Output* pOut;
	Input* pIn;
	ifstream InFile;
	string filename;
	int FigCount;
	string FigName;

public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute(bool ReadParamsFirst = true) override;
	virtual void UndoExcute();
	virtual void RedoExcute();
	~LoadAction();

	virtual bool CheckRecordability() const;
};

