//----------------------------------------------------------------------------
//
// Project      : Call To Power 2
// File type    : C++ header file
// Description  : Behaviour of the National Management dialog
//
//----------------------------------------------------------------------------
//
// Disclaimer
//
// THIS FILE IS NOT GENERATED OR SUPPORTED BY ACTIVISION.
//
// This material has been developed at apolyton.net by the Apolyton CtP2 
// Source Code Project. Contact the authors at ctp2source@apolyton.net.
//
//----------------------------------------------------------------------------
//
// Compiler flags
// 
// ACTIVISION_ORIGINAL		
// - When defined, generates the original Activision code.
// - When not defined, generates the modified Apolyton code.
//
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
// - #01 Added a third tab to the dialog that shows the nuber of experts and 
//   military units in each city.
//   (L. Hirth 6/2004)    
//----------------------------------------------------------------------------






#pragma once
#ifndef ___BMH_NATIONAL_MANAGEMENT_DIALOG_HEADER
#define ___BMH_NATIONAL_MANAGEMENT_DIALOG_HEADER


#include "Unit.h"


class aui_Control;
class ctp2_Button;
class ctp2_DropDown;
class ctp2_ListBox;
class ctp2_ListItem;
class ctp2_Static;
class ctp2_Window;
class ctp2_Tab;


class NationalManagementDialog {
public:
	
	static void Open();

	
	static void Close();

	
	static void Cleanup();

#if !defined (ACTIVISION_ORIGINAL)
	static bool IsShown();
#endif
	
	NationalManagementDialog();

	
	void Update();


private:
	
	void Show();

	
	void Hide();

	
	void UpdateResourceList();

	
	void UpdateStatusList();

#ifndef ACTIVISION_ORIGINAL // #01 Added a third tab to the dialog
	void UpdateSpecialistList();
#endif	

	void UpdateGovernor();

	
	void UpdateBuildQueue();

	
	void UpdateRushBuy();

	
	static ctp2_Static *GetListItemColumn(ctp2_ListItem *item, sint32 column);

	
	ctp2_ListItem *CreateResourceItem(const Unit &city);

	
	void UpdateResourceItem(ctp2_ListItem *item,
		const Unit &city);

	
	ctp2_ListItem *CreateStatusItem(const Unit &city);

	
	void UpdateStatusItem(ctp2_ListItem *item,
		const Unit &city);

#ifndef ACTIVISION_ORIGINAL // #01 Added a third tab to the dialog
	ctp2_ListItem *CreateSpecialistItem(const Unit &city);

	
	void UpdateSpecialistItem(ctp2_ListItem *item,
		const Unit &city);
#endif
	
	bool CanBuild(uint32 category, sint32 type);

	
	ctp2_ListItem *CreateBuildQueueItem(uint32 category, sint32 type);

	
	static sint32 CompareResources(ctp2_ListItem *item1, ctp2_ListItem *item2,
		sint32 column);

	
	static sint32 CompareStatus(ctp2_ListItem *item1, ctp2_ListItem *item2,
		sint32 column);

#ifndef ACTIVISION_ORIGINAL // #01 Added a third tab to the dialog
	static sint32 CompareSpecialists(ctp2_ListItem *item1, ctp2_ListItem *item2,
		sint32 column);
#endif
	
	static void StatusListSelectActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);

	
	static void CloseButtonActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);

	
	static void BuildQueueButtonActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);

	
	static void DisbandButtonActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);

	
	static void DisbandCallback(bool response, void *userData);

	
	static void ToggleGovernorButtonActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);

	
	static void SelectGovernorActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);

	
	static void SelectBuildItemActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);

	
	static void RushBuyButtonActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);

	
	static void ResourceListSelectActionCallback(aui_Control *control,
												 uint32 action, uint32 data, void *cookie);

#ifndef ACTIVISION_ORIGINAL // #01 Added a third tab to the dialog
	static void SpecialistListSelectActionCallback(aui_Control *control,
		uint32 action, uint32 data, void *cookie);
#endif
	

	void UpdateMainButtons(ctp2_ListBox *box);

	
	static void TabActionCallback(aui_Control *control,
								  uint32 action, uint32 data, void *cookie);

	void MirrorSelectedCities();
	static Unit GetSelectedCity();
	static void GotoSelectedCity();

	
	ctp2_Window		*m_window;

	
	ctp2_Button		*m_closeButton;

	
	ctp2_ListBox	*m_resourceList;	
	ctp2_ListBox	*m_statusList;		
#ifndef ACTIVISION_ORIGINAL // #01 Added a third tab to the dialog
	ctp2_ListBox    *m_specialistList;         
#endif

	
	ctp2_Button		*m_governorToggle;		
	ctp2_DropDown	*m_governorDropDown;	
	
	ctp2_Button		*m_rushBuyButton;		
	ctp2_Static		*m_rushBuyValue;		

	
	ctp2_Button		*m_buildQueueButton;	
	ctp2_Button		*m_disbandButton;		

	
	ctp2_Tab        *m_statusTab;           
	ctp2_Tab        *m_resourceTab;         
#ifndef ACTIVISION_ORIGINAL // #01 Added a third tab to the dialog
	ctp2_Tab        *m_specialistTab;         
#endif

	bool m_mirroring; 
};


extern NationalManagementDialog *g_nationalManagementDialog;

#endif 