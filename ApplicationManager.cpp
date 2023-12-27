#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddElipse.h"
#include "Actions/ActionAddHexa.h"
#include "Actions/ActionSelect.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;
	

	FigCount = 0;

	//initialise selectedCount to 0
	selectedCount = 0;
	selectedfigure = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface

		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			///create AddLineAction here
			newAct = new ActionAddElipse(this);
			break;

		case DRAW_HEX:
			newAct = new ActionAddHexa(this);
			break;

		case SELECT:
			newAct = new ActionSelect(this);

			break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	///Add your code here to search for a figure given a point x,y		for (int i = FigCount - 1; i >= 0; i--)
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->insideFigure(x, y)) {
			string shapeData = FigList[i]->GetFigureInfo();
			pGUI->PrintMessage(shapeData);
			return FigList[i];
		}

	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}

//==================================================================================//
//								Select Functions		     						//
//==================================================================================//


//Returns the number of selected figures
int ApplicationManager::GetSelectedCount() const {
	return selectedCount;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns a pointer to SelectedFigs array
CFigure* const* ApplicationManager::GetSelectedFigures() const {
	return SelectedFigures;
}

///////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::AddSelectedFigure(CFigure* sf) {

	SelectedFigures[selectedCount] = sf;
	selectedCount++;
}

void ApplicationManager::RemoveSelectedFigure(CFigure* sf) {

	for (int i = 0; i < selectedCount; i++) {
		if (SelectedFigures[i] == sf) {
			SelectedFigures[i] = SelectedFigures[selectedCount - 1];
			SelectedFigures[selectedCount - 1] = NULL;
			selectedCount--;

		}
	}
}
///  set selected figure For the select Action
void ApplicationManager::setselectedfigure(CFigure* pFig)
{
	selectedfigure = pFig;
}

CFigure* ApplicationManager::getselectedfigure() const
{
	return selectedfigure;
}

string ApplicationManager::getColorName(color c)
{
	if ((c.ucBlue == BLACK.ucBlue) && (c.ucGreen == BLACK.ucGreen) && (c.ucRed == BLACK.ucRed))
		return "BLACK";
	if ((c.ucBlue == PINK.ucBlue) && (c.ucGreen == PINK.ucGreen) && (c.ucRed == PINK.ucRed))
		return "PINK";
	if ((c.ucBlue == LIGHTBLUE.ucBlue) && (c.ucGreen == LIGHTBLUE.ucGreen) && (c.ucRed == LIGHTBLUE.ucRed))
		return "LIGHTBLUE";
	if ((c.ucBlue == MAROON.ucBlue) && (c.ucGreen == MAROON.ucGreen) && (c.ucRed == MAROON.ucRed))
		return "MAROON";
	if ((c.ucBlue == ORANGE.ucBlue) && (c.ucGreen == ORANGE.ucGreen) && (c.ucRed == ORANGE.ucRed))
		return "ORANGE";
	if ((c.ucBlue == BLUE.ucBlue) && (c.ucGreen == BLUE.ucGreen) && (c.ucRed == BLUE.ucRed))
		return "BLUE";
	if ((c.ucBlue == WHITE.ucBlue) && (c.ucGreen == WHITE.ucGreen) && (c.ucRed == WHITE.ucRed))
		return "WHITE";
	if ((c.ucBlue == RED.ucBlue) && (c.ucGreen == RED.ucGreen) && (c.ucRed == RED.ucRed))
		return "RED";
	if ((c.ucBlue == YELLOW.ucBlue) && (c.ucGreen == YELLOW.ucGreen) && (c.ucRed == YELLOW.ucRed))
		return "YELLOW";
	if ((c.ucBlue == GREEN.ucBlue) && (c.ucGreen == GREEN.ucGreen) && (c.ucRed == GREEN.ucRed))
		return "GREEN";
	return "NO-FILL";
}