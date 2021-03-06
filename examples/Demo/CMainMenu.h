// This is a Demo of the Irrlicht Engine (c) 2005 by N.Gebhardt.
// This file is not documentated.

#ifndef __C_MAIN_MENU_H_INCLUDED__
#define __C_MAIN_MENU_H_INCLUDED__

#include <irrlicht.h>

using namespace ue;

class CMainMenu : public IEventReceiver
{
public:

	CMainMenu();

	bool run(bool& outFullscreen, bool& outMusic, bool& outShadows,
		bool& outAdditive, bool &outVSync, bool& outAA,
		video::E_DRIVER_TYPE& outDriver);

	virtual bool OnEvent(const SEvent& event);

private:

	void setTransparency();

	gui::IGUIButton* startButton;
	IrrlichtDevice *MenuDevice;
	s32 selected;
	bool start;
	bool fullscreen;
	bool music;
	bool shadows;
	bool additive;
	bool transparent;
	bool vsync;
	bool aa;

	scene::IAnimatedMesh* quakeLevel;
	scene::ISceneNode* lightMapNode;
	scene::ISceneNode* dynamicNode;

	video::SColor SkinColor [ gui::EGDC_COUNT ];
	void getOriginalSkinColor();
};

#endif

