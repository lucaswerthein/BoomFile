#ifndef _TEST_APP
#define _TEST_APP
#include "ofxVectorMath.h"
#include "ofxBox2d.h"
#include "ofMain.h"
#include "dominos.h"
#include "scenceThree.h"
#include "scenceOne.h"
#include "scenceTwo.h"
#include "imageBall.h"
#include "soundContact.h"
#include "soundBall.h"
#include "soundRect.h"
#include "soundRect2.h"
#include "soundBucket.h"
#include "ofxAlphaVideoPlayer.h"
#include "bkgImage.h"
#include "animations.h"
#include "soundMiro.h"
#include "soundBridge.h"
//-----------------------CONTACT LISTENER------------------------//
class MyContactListener : public b2ContactListener
	{
	public:
		void Add(const b2ContactPoint* point);		
		void Remove(const b2ContactPoint* point);
		
	};

//-----------------------CONTACT LISTENER------------------------//

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void worldRects(int posX, int posY, int w, int h, float ang, float spring);
	
	ofxBox2d						box2d;								//	the box2d world
	dominos							bigDominos;
	scenceOne						sceneone;
	scenceTwo						scenetwo;
	scenceThree						scenethree;
	imageBall						pngBall;
	ofSoundPlayer					machine;
	ofSoundPlayer					crash;
	ofSoundPlayer					balloon;
	ofSoundPlayer					slurp;
	animations						movies;

		
	static int						worldCounter;
	static int						dominoeTime;
	static int						staticTimer;
	int								crazyTime;
	int								counter;
	int								width;
	int								height;
	int								counter3;
	
	MyContactListener				contacts;
	bool  soundStarted;

};

#endif
