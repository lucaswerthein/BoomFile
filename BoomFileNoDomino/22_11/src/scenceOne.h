
#include "ofxVectorMath.h"
#include "ofxBox2d.h"
#include "rectImage.h"
#include "pipes.h"

#ifndef _SCENEONE
#define _SCENEONE

#define NUMBALLS 16
#define NUMJOINTS 15

class scenceOne : public ofBaseApp{
	
public:
	void setup(ofxBox2d* box2d);
	void update();
	void draw();
	void bridge();
	void worldRects(int posX, int posY, int w, int h, float ang, float spring);
	
	ofxBox2d*						box2d;
	ofxBox2dCircle					ballJoints		[NUMBALLS];				//	ball joints
	ofxBox2dJoint					joints			[NUMJOINTS];
	vector							<rectImage>			lineRects;
	int width;
	int height;
	int middlePos;
	int boxW, boxH;
	
};

#endif