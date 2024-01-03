#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"
#include "..\ApplicationManager.h"

class CCircle :public CFigure
{
private:
	Point center;
	int radius;
public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job

	CCircle(Point, int, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	CFigure* Clone();
	string getShapeType();
	virtual void Resize(GUI* pGUI, float size);

	string GetFigureInfo();
};

#endif

