#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/ui/GeodeUI.hpp>

#include <Geode/modify/HardStreak.hpp>
#include <Geode/modify/PauseLayer.hpp>
using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>


class $modify(HardStreak)
{
	
	void updateStroke(float dt)
	{

		auto R = Mod::get()->getSettingValue<int64_t>("R");
		auto G = Mod::get()->getSettingValue<int64_t>("G");
		auto B = Mod::get()->getSettingValue<int64_t>("B");




			this->setColor({
				(byte)(R),
				(byte)(G),
				(byte)(B)}
			);

		HardStreak::updateStroke(dt);
	}
};


class $modify(MyPauseLayer, PauseLayer)
{



	void onGUIBtn(CCObject*){
		openSettingsPopup(Mod::get());

};

	void customSetup() {




		PauseLayer::customSetup();

		
		auto RightSide = this->getChildByID("right-button-menu");
		auto spr = CCSprite::create("wavespr.png"_spr);
		spr->setScale(0.8);
	
		auto WaveTrailGuiBtn = CCMenuItemSpriteExtra::create(
			spr,
			this,
			menu_selector(MyPauseLayer::onGUIBtn)
		);
	


		RightSide->addChild(WaveTrailGuiBtn);
		WaveTrailGuiBtn->setID("wavebtn");
		RightSide->updateLayout();


	
	};





};








		
	


