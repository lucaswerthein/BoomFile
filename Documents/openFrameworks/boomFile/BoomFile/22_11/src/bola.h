#include "ofxVectorMath.h"
#include "ofxBox2d.h"

class bola: public ofxBox2dCircle{
public:
	void setupBola(ofxBox2d* box2d);
	void draw();
	void dropBola();
	void destroyBola();
	void drawBola();
	ofxBox2d*						box2d;
	vector				< ofPoint > points;
	vector							<bola>			circles;

};