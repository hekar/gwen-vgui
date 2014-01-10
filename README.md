GWEN VGUI

This is a fork of [GWEN](http://www.facepunch.com/threads/888841) that comes with a [VGUI](https://developer.valvesoftware.com/wiki/VGUI_Documentation) Renderer. 
There is also come code to integration [GWEN](http://www.facepunch.com/threads/888841) with [Valve's GUI framework](https://developer.valvesoftware.com/wiki/VGUI_Documentation).

It is encouraged to use the mainline of GWEN and implement this renderer yourself, 
but if you wish to get up and running as soon as possible, then simply doing this project
and setting it will make it easy to get into your Source engine modification.


Also comes with some widgets to help you get setup and create a GWEN frame in game.

Add the widgets to the Client.dll of your modification.


Setup Instructions:
	- Add the Gwen project to game_scratch solution
	- Add the mod folder to your client.dll project
	- Add the following lines in vgui_int.cpp
		+ add the following include:
			#include "BaseGUI.h"
		+ at the end of void VGui_CreateGlobalPanels():
			g_pGUIManager = new CGUILoader();
			g_pGUIManager->InitPanels();
		+ before the `if ( g_ClientMode )` in void VGui_Shutdown():
			g_pGUIManager->DestroyPanels();
			delete g_pGUIManager;

Limitations:
	- Key input does not work in this release, because I simply have not added it
	- Only works with vgui::Frame, but there is no reason that you cannot
	  implement GWEN frames on their own (I just chose an easier route)

Good luck!