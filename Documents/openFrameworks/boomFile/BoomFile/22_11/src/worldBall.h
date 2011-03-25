#include "ofxVectorMath.h"
#include "ofxBox2d.h"

#ifndef _DOMINANTBALL
#define _DOMINANTBALL

class worldBall : public ofBaseApp{
	
public:
	void setup(ofxBox2d* box2d);
	//void update();
	void draw();
	void dropOne();
	void dropTwo();
	void dropThree();
	void destroyBalls();
	
	ofxBox2d*						box2d;
	vector							<ofxBox2dCircle> flyingBall;	
	
	
};

#endif _DOMINANTBALL