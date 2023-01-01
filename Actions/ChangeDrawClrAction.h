#pragma once
#include "Action.h"
class ChangeDrawClrAction : public Action
{
	color NewDraw;
	bool chosen;
	color prevUIDraw;
	color prevFigDraw;
	CFigure* pFig;

public:
	ChangeDrawClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual bool Execute(bool ReadParamsFirst = true) override;
	virtual void UndoExcute() override;
	virtual void RedoExcute() override;
	~ChangeDrawClrAction();

};

