#include "bkgImage.h"

bool bkgImage::loadedImage = false;
ofImage bkgImage::bkg;
ofImage bkgImage::bkgDomino;
//--------------------------------------------------------------
void bkgImage::loadImage(){
	if(!loadedImage) {
		ofSetRectMode(OF_RECTMODE_CENTER);
		bkg.setImageType(OF_IMAGE_COLOR_ALPHA);
		bkg.loadImage("bg.jpg");
		bkg.resize(8160/2, 768/2);

		bkgDomino.setImageType(OF_IMAGE_COLOR_ALPHA);
		bkgDomino.loadImage("bg.jpg");
		bkgDomino.resize(8160/2, 768/2);
		
		cout << "just loaded BKG.png" << endl;
		loadedImage = true;

	}
}
//--------------------------------------------------------------
void bkgImage::drawImage(){
	ofNoFill();
	ofSetColor(255,255,255);
	bkg.draw(4080/2,384/2);
	bkgDomino.draw(4080/2,384/2);
}
