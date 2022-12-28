#pragma once
#include "Action.h"
class DeleteAction : public Action
{
public:
	DeleteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute(bool ReadParamsFirst = true) override;
	~DeleteAction();
	virtual void UndoExcute();
	virtual void RedoExcute();

	virtual bool CheckRecordability() const;
};

