#include "ActionAddElipse.h"
#include "..\Figures\CElipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddElipse::ActionAddElipse(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionAddElipse::Execute() 
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Square: Click at first point");	
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Square: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare elipse data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point first ,second;
	first.x = P1.x;
	first.y= P1.y;
	second.x = P2.x;
	second.y = P2.y;

	

		
	//Step 3 - Create a elipse with the parameters read from the user
	CElipse *R=new CElipse(first, second, SqrGfxInfo);

	//Step 4 - Add the elipse to the list of figures
	pManager->AddFigure(R);
}
