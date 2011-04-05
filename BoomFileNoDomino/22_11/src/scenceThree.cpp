
#include "scenceThree.h"

//--------------------------------------------------------------
void scenceThree::setup(ofxBox2d* box2d){
	this->box2d = box2d;
	leftPos = 2720;
	//crossImage::loadImage();
	//platform::loadImage();

}
//--------------------------------------------------------------	
void scenceThree::update(){
	
	revolJoint(0, leftPos+120, 80, 10, 0, leftPos+120, 80, 0, 3,100,5);
	revolJoint(1, leftPos+70, 170, 10, 1, leftPos+70, 170, 1, -3,100,5);
	revolJoint(2, leftPos+120, 250, 10, 2, leftPos+120, 250, 2, 3,100,5);
	
	revolJoint(3,leftPos+ 520, 160, 60, 3, leftPos+520, 160, 3, -8, 310,30);
	revolJoint(4, leftPos+332, 340, 10, 4, leftPos+332, 340, 4, -18, 100, 5);
	revolJoint(5, leftPos+695, 340, 10, 5, leftPos+695, 340, 5, -18, 60, 20);
	
	revolJoint(6, leftPos+860, 340, 5, 6, leftPos+860, 340, 6, -38,35,4);
	revolJoint(7, leftPos+900, 340, 2, 7, leftPos+900, 340, 7, -48,25,7);
	revolJoint(8, leftPos+935, 340, 4, 8, leftPos+935, 340, 8, -78,20,5);
	revolJoint(9, leftPos+960, 340, 3, 9, leftPos+960, 340, 9, 98,15,3);
	revolJoint(10, leftPos+985, 340, 1, 10, leftPos+985, 340, 10, 200,10,2);

	
	/////////////////////////DRAW LINES//////////////////////////
	worldRects(leftPos+10, 320, 1, 12, 0, 1.23);
	worldRects(leftPos+10,335,270,1,0.03, .23);
	worldRects(leftPos+405,340,235,1,0, .23);
	worldRects(leftPos+750,340,90,1,0, 2.53);
	
	soundGears::loadGears();

}

//--------------------------------------------------------------	
void scenceThree::draw(){

	/////////////////////////DRAWING CIRCLES//////////////////////////
	//for(int i = 0; i < NUMCIRCLES; i++)	ball[i].draw();
	
	/////////////////////////DRAWING RECTANGLES//////////////////////////
	for(int i = 0; i < RECT; i++) {
		//cout << i << ": " << "boxW is: "<< boxW << " / " << "boxH is: "<< boxH << endl;
		rect[i].draw();
	}
	//for(int i = 0; i < RECT; i++) rect[i].draw();
	

	/////////////////////////DRAWING RECTANGLE LINES/////////
	for(int i = 0; i < lineRects.size(); i++)lineRects[i].draw();
	//for(int i = 0; i < lineRects.size(); i++)lineRects[i].draw(platformW, platformH);

	
}
//--------------------------------------------------------------
void scenceThree::revolJoint(int ballArray, int ballPosX, int ballPosY, int radius, int rectArray, int rectPosX, int rectPosY, int jointArray, int motorSpeed, int rectW, int rectH){

/////////////////////////JOINT FUNCTION I CREATED//////////////////////////
	
	ball[ballArray].setPhysics(0, 0.0, 0.0);
	ball[ballArray].setup("revolBall", box2d->getWorld(), ballPosX, ballPosY, radius);		

	rect[rectArray].setPhysics(.1, 0.0, 0.0);
	rect[rectArray].setup(box2d->getWorld(), rectPosX, rectPosY, rectW, rectH,0);		
	
	revoluteJoint[jointArray].setWorld(box2d->getWorld());
	revoluteJoint[jointArray].addJoint(rect[rectArray].body, ball[ballArray].body, 3.0, 0.6,0,0,motorSpeed);
	
}
//--------------------------------------------------------------
void scenceThree::worldRects(int posX, int posY, int w, int h, float ang, float spring){
	
	//ofxBox2dRect lineReplacer;
	platform lineReplacer;
	lineReplacer.setPhysics(0, spring, 0.1);
	lineReplacer.setup("lineBox",box2d->getWorld(), posX , posY, w, h, ang);
	lineRects.push_back(lineReplacer);
	
}
