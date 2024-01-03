#include "ActionSelect.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <math.h>

ActionSelect::ActionSelect(ApplicationManager * pApp):Action(pApp)
{}

void ActionSelect::Execute()
{
	Point P1;

	GUI* pGUI = pManager->GetGUI();
	ApplicationManager* pAPP = pManager;

	pGUI->PrintMessage("Click at any point");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	CFigure* pFig = pManager->GetFigure(P1.x, P1.y);
	if (pFig) {
		pFig->SetSelected(!pFig->IsSelected());
		if (pFig->IsSelected())
		{
			pManager->AddSelectedFigure(pFig); //Add the figure to ApplicationManager's SelectedFigures array
		}
		else
		{  
			pManager->RemoveSelectedFigure(pFig); // to remove the unselected from SelectedFigures array
		}
	}
}

