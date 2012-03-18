/* ***** BEGIN LICENSE BLOCK *****
Version: MPL 1.1/LGPL 2.1/GPL 2.0

The contents of this file are subject to the Mozilla Public License Version 
1.1 (the "License"); you may not use this file except in compliance with
...
for the specific language governing rights and limitations under the
License.

The Original Code is for LuminousForts.

The Initial Developer of the Original Code is Hekar Khani.
Portions created by the Hekar Khani are Copyright (C) 2010
Hekar Khani. All Rights Reserved.

Contributor(s):
  Hekar Khani <hekark@gmail.com>

Alternatively, the contents of this file may be used under the terms of
either of the GNU General Public License Version 2 or later (the "GPL"),
...
the terms of any one of the MPL, the GPL or the LGPL.

***** END LICENSE BLOCK ***** */


// To clean up the way GUI panels are created
#include "cbase.h"
#include "BaseGUI.h"

#include <vgui/IVGui.h>
#include "ienginevgui.h"

// Initialize these panels
#include "Gwen.h"

CGUILoader *g_pGUIManager = NULL;

CGUILoader::CGUILoader()
{
	m_GameUI = enginevgui->GetPanel( PANEL_GAMEUIDLL );
}

CGUILoader::~CGUILoader()
{
}

void CGUILoader::InitPanels()
{
	// Main menu parents CBaseGamePanel
	const int BasePanelIndex = 1; // Bit of debugging to figure this out :/
	VPANEL BaseGamePanel = ipanel()->GetChild( m_GameUI, BasePanelIndex );

	// Bootstrap Gwen
	gwenbootstrap->Create( m_GameUI );
}

void CGUILoader::DestroyPanels()
{
	gwenbootstrap->Destroy();
}
