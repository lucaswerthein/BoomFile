
#include "ofxVectorMath.h"
#include "ofxBox2d.h"
#include "crossImage.h"
#include "platform.h"
#include "soundGears.h"

#ifndef _SCENETHREE
#define _SCENETHREE
#define NUMCIRCLES 11
#define JOINTS 11
#define RECT 11
class scenceThree : public ofBaseApp{
	
public:
	void setup(ofxBox2d* box2d);
	void update();
	void draw();
	void revolJoint(int ballArray, int ballPosX, int ballPosY, int radius, int rectArray, int rectPosX, int rectPosY, int jointArray, int motorSpeed, int rectW, int rectH);
	void worldRects(int posX, int posY, int w, int h, float ang, float spring);
	
	ofxBox2d*						box2d;
	ofxBox2dRevoluteJoint			revoluteJoint	[JOINTS];
	ofxBox2dCircle					ball			[NUMCIRCLES];	
	crossImage						rect			[RECT];
	//ofxBox2dCrissCross				rect			[RECT];
	//vector							<ofxBox2dRect>	lineRects;
	vector							<platform> lineRects;

	int width;
	int height;
	int leftPos;
	
	int boxW, boxH;
	int platformW, platformH;

};

#endif