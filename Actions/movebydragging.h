#pragma once
#include "Action.h"
class movebydragging : public Action
{
	Point destination;
	CFigure* pFig;
	//CFigure* saved;
	Point prevlocation;
	//CFigure* moved;
	Point newlocation;

public:
	movebydragging(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual bool Execute(bool ReadParamsFirst = true) override;
	virtual void UndoExcute() override;
	virtual void RedoExcute() override;
	~movebydragging();
};

