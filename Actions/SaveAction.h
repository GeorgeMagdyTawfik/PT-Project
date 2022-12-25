#pragma once
#include "Action.h"

class SaveAction :
    public Action
{
    Input* pIn;
    Output* pOut;
    string filename;
    ofstream OutFile;

    color Draw, Fill;

public:
    SaveAction(ApplicationManager* pApp);
    virtual void ReadActionParameters() override;
    virtual void Execute() override;
    ~SaveAction();
};
