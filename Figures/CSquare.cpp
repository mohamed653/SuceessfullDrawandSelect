#include "CSquare.h"

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	ID = newID++;
}

CSquare::CSquare() {}

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}
bool CSquare::insideFigure(int x, int y)
{
	if (x >= TopLeftCorner.x && x <= (TopLeftCorner.x + length) && y >= TopLeftCorner.y && y <= (TopLeftCorner.y + length))
	{
		return true;
	}
	return false;
}

string CSquare::GetFigureInfo()

{
	string DrawColor = pManager->getColorName(FigGfxInfo.DrawClr);
	string shapeInfo = "ID: " + to_string(ID) + " || Shape: Square || First Point: (" + to_string(TopLeftCorner.x) + ", " + to_string(TopLeftCorner.y) + ")" + " || Side Length: " + to_string(length) + " || Area: " + to_string(length * length) + " Draw Color: " + DrawColor;
	if (FigGfxInfo.isFilled)
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

/////
void CSquare::Resize(GUI* pGUI, float size) {
	Point test1 = TopLeftCorner;

	if (test1.y < UI.ToolBarHeight || test1.x > UI.width)
	{
		pGUI->PrintMessage("square size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (((test1.x - length) / 2) < 15 || ((test1.y - length) / 2) < 10)
	{
		pGUI->PrintMessage("square size will be very small");
		Sleep(1000);
	}

	this->length = this->length * size;



}
