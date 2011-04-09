#ifndef _IMAGEBALL
#define _IMAGEBALL

#include "ofMain.h"
#include "ofxVectorMath.h"
#include "ofxBox2d.h"

class imageBall: public ofxBox2dCircle{
public:
	void setupRedBall(ofxBox2d* box2d);
	static void loadImage();
	void draw();
	void dropRedball();
	void drawRedBall();
	void dropRedball2();
	void destroyRedBall();
	
	ofxBox2d*						box2d;
	vector		<imageBall>			redBall;
	vector				< ofPoint > points;
	static bool						loadedImage;
	static		ofImage				tball;	
};

#endif _IMAGEBALL