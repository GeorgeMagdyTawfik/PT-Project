#pragma once
#include "Action.h"
class SwitchToPlayMode : public Action
{
public:
	SwitchToPlayMode(ApplicationManager* pApp);

	// I do not need a real implementation (just to make this class not abstract)
	virtual void ReadActionParameters();

	virtual void Execute();

	void UndoExcute();
	void RedoExcute();
};

