#include "CElipse.h"

CElipse::CElipse(Point P1, Point p2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = P1;
	P2 = p2;
}


	

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