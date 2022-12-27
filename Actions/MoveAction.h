#pragma once
#include "Action.h"
class MoveAction : public Action
{
	Point destination;
public:
	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
	virtual void UndoExcute() override;
	virtual void RedoExcute() override;
	~MoveAction();
};

