#pragma once
#include "Action.h"
class ChangeDrawClrAction : public Action
{
	color NewDraw;
	bool chosen;
public:
	ChangeDrawClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
	virtual void UndoExcute() override;
	~ChangeDrawClrAction();
};

