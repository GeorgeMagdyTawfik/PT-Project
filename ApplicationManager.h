#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
class Action;

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

	enum { MaxUndoCount = 5 };	//Max no of figures
	enum { MaxRecord = 20 }; // Maximum number of recorded actions
private:
	int FigCount;		//Actual number of figures

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure

	Action** RecordingList = new Action * [MaxRecord]; /// all the currently recorded actions
	int RecordedActionsCount;
	bool RecordingState;
	bool PlayRecordingState;

	bool playsound;

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;


	Action* undolist[MaxUndoCount];
	int undocount;
	int redocount;
	CFigure* deletedlist[5];
	int deletecount;
	
	Action* LastAction;

	int SquareCount;
	int CircleCount;
	int HexaCount;
	int TriangleCount;
	int RectCount;

	int NoFillFigs;
	int RedFigs;
	int BlackFigs;
	int BlueFigs;
	int Greenfigs;
	int YellowFigs;
	int OrangeFigs;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure


	void SetSelectedFigure(CFigure*);
	CFigure* GetSelectedFig() const;

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	// -- Functions which Loop on FigList
	void SaveGraph(ofstream& OutFile);
	void DeleteAll();

	// -- Setters and Getters
	int GetFigCount() const;
	void SetFigcount(int x);

	int getredocount();
	int getundocount();

	void SetRecordingState(bool b);
	bool GetRecordingState() const;

	void SetPlayRecordingState(bool b);
	bool GetPlayRecordingState();

	int GetRecordedActionsCount() const;
	void PreviewRecordedActs();

	void RemovePastRecording();				 // This is called when Starting a new Recording or Clear ALL
	void AddToRecordingList(Action*);

	void DeleteFigure(CFigure* pFig);

	void addtoundolist(Action*);
	void Undo();
	void Redo();
	void EmptyUndoList();

	void CountTypes();
	void CountFillColors();

	FillColors GetRandomFillColor(int index);
	char GetRandomType(int index);

	int GetCircleCount() const;
	int GetRectCount() const;
	int GetHexaCount() const;
	int GetSquareCount() const;
	int GetTriangleCount() const;

	int GetBlackFigs();
	int GetRedFigs();
	int GetOrangeFigs();
	int GetYellowFigs();
	int GetGreenFigs();
	int GetBlueFigs();
	int GetNoFillFigs();

	void ResetCounts();
	void ResetFillColors();

	int GetCountForTypeAndColor(char type, FillColors clr);

	void ChangeStateOfSound();
	void SetStateOfSound(bool b);							//this is used when clearing all
	bool GetStateOfSound();
};

#endif
