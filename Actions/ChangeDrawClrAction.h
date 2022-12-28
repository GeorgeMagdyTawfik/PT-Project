#pragma once
#include "Action.h"
class ChangeDrawClrAction : public Action
{
	color NewDraw;
	bool chosen;
public:
	ChangeDrawClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute(bool ReadParamsFirst = true) override;
	virtual void UndoExcute() override;
	virtual void RedoExcute() override;
	~ChangeDrawClrAction();

	virtual bool CheckRecordability() const;
};

