#include "ofxVectorMath.h"
#include "ofxBox2d.h"
#include "swingBall.h"
#include "crossImage.h"
#include "platform.h"
#include "soundSwoosh.h"
#include "soundWoosh.h"
#include "soundSlot.h"

#ifndef _SCENETWO
#define _SCENETWO

#define NUMBALLS 6
#define NUMJOINTS 5
#define JOINTS 01
#define CROSS 01
#define CROSSCIRCLES 01

class scenceTwo : public ofBaseApp{
	
public:
	void setup(ofxBox2d* box2d);
	void update();
	void draw();
	void ballHolder();
	void ballJointFunction(int arrayNum1, int arrayNum2, float x, float y, float x2, float y2, float mass, float bounce, float friction, float radius, float mass2, float bounce2, float friction2, float radius2);
	void revolJoint3(int ballArray, int ballPosX, int ballPosY, int radius, int rectArray, int rectPosX, int rectPosY, int jointArray, int motorSpeed);
	void worldRects(int posX, int posY, int w, int h, float ang, float spring);
	void destroyBallHolder();

	ofxBox2d*						box2d;	
	swingBall						ballJoints3		[NUMBALLS];
	ofxBox2dJoint					joints3			[NUMJOINTS];			//	box2d joints
	ofxBox2dRevoluteJoint*			revoluteJoint3	[JOINTS];
	ofxBox2dCircle*					ball3			[CROSSCIRCLES];	
	crossImage*						rect3			[CROSS];
	
	vector							<ofxBox2dRect>	rects3;	
	//vector							<ofxBox2dRect>	lineRects;
	vector							<platform> lineRects;

	ofImage							bucket;
	int counter;
	int rightPos;
	int boxW, boxH;
	int platformW, platformH;
	int bigBallCenter, bigBallTop, mediumBallCenter, mediumBallTop, smallBallCenter, smallBallTop;
	ofSoundPlayer swoosh;
	bool reachedHeight;



	
	
	
};

#endif