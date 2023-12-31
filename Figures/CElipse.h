#ifndef CELIPSE_H
#define CELIPSE_H

#include "CFigure.h"
#include "..\ApplicationManager.h"
class CElipse : public CFigure
{
private:
	Point P1;	
	Point P2;
public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job
	CElipse(Point , Point, GfxInfo FigureGfxInfo );

	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);

	virtual void Resize(GUI* pGUI, float size);

	string GetFigureInfo();
};

#endif