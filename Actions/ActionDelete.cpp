#include "ActionDelete.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

void ActionDelete::Execute() {
	//Get a Pointer to the GUI 
	GUI* pGUI = pManager->GetGUI();

	//Initialise local SelectedFigs and selectedCount 
	SelectedFigures = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();


	//Check if a figure is selected
	if (SelectedFigures[0] == NULL)
		pGUI->PrintMessage("Select figure first");


	else {
		int msgboxID = MessageBoxW(
			NULL,
			(LPCWSTR)L"Confirm Delete?!\n",
			(LPCWSTR)L"Confirm Delete",
			MB_ICONWARNING | MB_YESNOCANCEL | MB_DEFBUTTON2
		);
		switch (msgboxID)
		{
		case IDYES://case of confirmation

			for (int i = 0; i < selectedCount; i++)
			{

				DeletedID = pManager->GetSelectedFigureIndex();
				pManager->RemoveFig(DeletedID);
				delete SelectedFigures[i];
				pManager->ClearSelectedFigs();
				pGUI->ClearDrawArea();
				pGUI->PrintMessage("Figure(s) Deleted");

			}
			break;
		case IDCANCEL://case of cnacel or deny the deletion
		case IDNO:
			pGUI->PrintMessage("Deletion canceled!");
			break;

		}


	}
}