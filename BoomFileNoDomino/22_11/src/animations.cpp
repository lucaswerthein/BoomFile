#include "animations.h"

//--------------------------------------------------------------
void animations::loadMovie(){
	loadedMovie = false;
	if(!loadedMovie) {
		swirl.loadMovie("swirl.mov");
		swirl.play();
		pickery.loadMovie("picker.mov");
		pickery.play();
		plaid.loadMovie("plaid.mov");
		plaid.play();
		gears.loadMovie("gears.mov");
		gears.play();
		layer.loadMovie("layer.mov");
		layer.play();
		loadedMovie = true;
	}
}
//--------------------------------------------------------------
void animations::updateMovie(){

}
//--------------------------------------------------------------
void animations::drawMovie(){
	ofNoFill();
	ofSetColor(255,255,255);
	ofEnableAlphaBlending();
	swirl.draw(1080,100, swirl.getWidth()/1.5, swirl.getHeight()/1.5);
	pickery.draw(1420,230, pickery.getWidth()/3, pickery.getHeight()/3);
	plaid.draw(2990,150, plaid.getWidth()/1.5, plaid.getHeight()/1.5);
	gears.draw(7880/2,200, gears.getWidth()/2, gears.getHeight()/2);
	layer.draw(2500,120, layer.getWidth(), layer.getHeight());

}
