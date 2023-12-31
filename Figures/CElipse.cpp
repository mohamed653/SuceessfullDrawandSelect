#include "CElipse.h"
#include <fstream>
#include <iostream>


CElipse::CElipse(Point p1, Point p2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	ID = newID++;
}

CElipse::CElipse() {}
	

void CElipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawEllipse(P1, P2,FigGfxInfo, Selected);
	

}

bool CElipse::insideFigure(int x, int y)
{
	Point center;
	center.x = 0.5 * (P2.x + P1.x);
	center.y = 0.5 * (P2.y + P1.y);
	float a = abs(P2.x - P1.x) / 2;
	float b = abs(P2.y - P1.y) / 2;
	float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
	if (check <= 1)
		return true;

	return false;


	/*	if ((P1.x <= x && P2.x >= x) && (P1.y <= y && P2.y >= y)) {
			return true;
		}
		return false;  */
}


/////
void CElipse::Resize(GUI* pGUI, float size) {
	Point test1 = P1, test2 = P2;
	if (size == .5) size = -0.5;
	else if (size == .25) size = -(4.0 / 3);
	else if (size == 2) size = 1;
	else size = 3;

	// half radius (horizontal x && vertical y)
	float deltaX, deltaY;
	deltaX = 0.5 * (P2.x - P1.x);
	deltaY = 0.5 * (P2.y - P1.y);



	test1.x -= deltaX * size;
	test2.x += deltaX * size;
	test1.y -= deltaY * size;
	test2.y += deltaY * size;

	if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
		|| test2.x > UI.width || test1.x < 1)
	{
		pGUI->PrintMessage("Ellips size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (((test2.x - test1.x) / 2) < 15 || ((test2.y - test1.y) / 2) < 10)
	{
		pGUI->PrintMessage("Ellips size will be very small");
		Sleep(1000);
	}

	P1 = test1;
	P2 = test2;

}


string CElipse::GetFigureInfo()
{
	string DrawColor = pManager->getColorName(FigGfxInfo.DrawClr);
	string shapeInfo = "ID: " + to_string(ID) + " || Shape: Ellipse || First Point: (" + to_string(P1.x) + ", " + to_string(P1.y) + ")" + " || Second Point: (" + to_string(P2.x) + ", " + to_string(P2.y) + ")" + " || Draw Color: " + DrawColor;
	if (FigGfxInfo.isFilled)
	{
		string fillColor = pManager->getColorName(FigGfxInfo.FillClr);
		shapeInfo += " || Filled || Fill Color: " + fillColor;
	}
	else {
		shapeInfo += " || NO FILL";
	}
	return shapeInfo;
}