#include "ofxVectorMath.h"
#include "ofxBox2d.h"
#include "testApp.h"
#include "imageBall.h"

#ifndef _DOMINOS
#define _DOMINOS
class dominos : public ofBaseApp{
	
public:
	void setup(ofxBox2d* box2d);
	void update();
	void draw();
	void dominoesFunction(int posX, float posY, int w, int h);
	void giantDominoFunction();
	void pushDominoForce();
	
	static void loadImage();
	static void drawImage();
	
	
	static bool loadedImage;
	static		ofImage pipeDomino;

	ofxBox2d*						box2d;
	vector							<ofxBox2dRect>		dominoes;
	imageBall						startBall;
};

#endif