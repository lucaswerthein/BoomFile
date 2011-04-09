#include "scenceTwo.h"

//--------------------------------------------------------------
void scenceTwo::setup(ofxBox2d* box2d){
	this->box2d = box2d;
	swingBall::loadImage();
	crossImage::loadImage();
	platform::loadImage();
	ofSetRectMode(OF_RECTMODE_CENTER);
	bucket.setImageType(OF_IMAGE_COLOR);
	bucket.loadImage("bucket.png");
	
	bigBallCenter		= 2390;
	bigBallTop			= 20;
	mediumBallCenter	= 1910;
	mediumBallTop		= 80;
	smallBallCenter		= 2600;
	smallBallTop		= 261;
	reachedHeight		= false;
}

//--------------------------------------------------------------
void scenceTwo::update(){
	rightPos			= 1360;
	int length			= rightPos+40;
	int height			= 28;
	int bigRadius		= 50;
	int smallRadius		= 10;
	int massBigCircle	= 20;
	
	//////////FIRST 3 JOINTS///////////
	ballJointFunction(0, 1, length+500, height+100, length+350, height+50, 0.0, 0.53, 0.0, smallRadius, 10, 0.53, 0.0, bigRadius);
	ballJointFunction(2, 3, length+1200, height+260, length+1130, height+230, 0.0, 0.53, 0.0, smallRadius-5, 10, 0.53, 0.0, bigRadius-35);
	ballJointFunction(4, 5, length+1000, height-20, length+800, height-26, 0.0, 0.53, 0.0, smallRadius-7, 10, 0.53, 0.0, bigRadius+10);
	
	worldRects(rightPos+20, 0, 1, 20, 0.0, 0);
	worldRects(rightPos+40, 0, 1, 20, 0.0, 0);
	worldRects(rightPos+110, 120, 60, 1, 1.2, 0.0);
	worldRects(rightPos+210, 120, 60, 1, -1.2, 0.0);
	ballHolder();
	worldRects(rightPos+10, 45, 100, 1, 0.2, 0.0);
	worldRects(rightPos+140, 300, 100, 1, .6, 2.5);
	worldRects(2115, 300, 20, 1, .5, 1.4);
	revolJoint3(0, rightPos+135, 62, 5, 0, rightPos+135, 62, 0, -9);	
	
}

//--------------------------------------------------------------
void scenceTwo::draw(){

	//////////////DRAW CIRCLES AND JOINTS//////////////
	for(int i=0; i<NUMJOINTS; i++) joints3[i].draw();
	for(int i=0; i<NUMBALLS; i++) ballJoints3[i].draw();
	
	//////////////DRAW BALL HOLDER//////////////
	for(int i=0; i<rects3.size(); i++) {
		rects3[i].draw();
	}
	
	//////////////DRAW BOXES//////////////
	for(int i=4; i<lineRects.size(); i++) {
		lineRects[i].draw();

	}
	
	//////////////DRAW CROSS//////////////
	for(int i=0; i<CROSS; i++) {
		rect3[i]->draw();
	}
	
	bucket.draw(rightPos+200,150, bucket.getWidth()/3, bucket.getHeight()/3);
	
	/////////////Get Postion to figure out where to play sound
	ofPoint pos = ballJoints3[1].getPosition();;
	if(pos.x >= 1950 && pos.x <= 1970) soundSwoosh::loadSwoosh();
	//cout << "posx is: " << pos.x<< endl;
	
	ofPoint pos2 = ballJoints3[5].getPosition();
	if(pos2.x >= 2360 && pos2.x <= bigBallCenter) soundWoosh::loadWoosh();
	
	ofPoint pos3 = ballJoints3[3].getPosition();

	
	////////////GET Y Position to input force on ball2
	ofPoint forceBigBall;
	forceBigBall.x = 10000;
	forceBigBall.y = 0;
	ofPoint forceMediumBall;
	forceMediumBall.x = 400;
	forceMediumBall.y = 0;
	
	ofPoint futurePos5;
	futurePos5.x = pos2.x;
	futurePos5.y = 2.2;
	if(pos2.y <= 3 && pos2.x <= bigBallCenter){
		//cout << "posY is: " << pos2.y << endl;
		ballJoints3[5].setPosition(futurePos5);
		
	}
	
	
	ofPoint futurePos1;
	futurePos1.x = pos.x;
	futurePos1.y = 79;
	if(pos.y <= mediumBallTop && pos.x <= mediumBallCenter){
		//cout << "posY is: " << pos.y << endl;
		ballJoints3[1].setPosition(futurePos1);
		
	}
	
	ofPoint futurePos3;
	futurePos3.x = pos3.x;
	futurePos3.y = 260;
	if(pos3.y <= smallBallTop && pos3.x <= smallBallCenter){
		cout << "posY is: " << pos3.y << endl;
		ballJoints3[3].setPosition(futurePos3);
		
	}
	
	
	if(pos2.x <= bigBallCenter && pos2.y <= bigBallTop){
		//ballJoints3[3].addForce(forceBigBall, pos2);
		ballJoints3[5].addForce(forceBigBall, pos2);

		//cout << "posY is: " << pos2.y << endl;
	}
	/*
	ofPoint posMed;
	posMed.x = 1745;
	posMed.y = 60;
	if(pos.x <= mediumBallCenter && pos.y <= mediumBallTop){
		ballJoints3[1].addForce(forceMediumBall, pos);
		//ballJoints3[1].addRepulsionForce(posMed, 30, 2000);

	}*/
	
	
	////////TESTS///////
	ballJoints3[1].body->ApplyForce(b2Vec2(400,-100), ballJoints3[1].body->GetWorldCenter());
	//ballJoints3[3].body->ApplyForce(b2Vec2(100,0), ballJoints3[3].body->GetWorldCenter());
	ballJoints3[5].body->ApplyForce(b2Vec2(900,-100), ballJoints3[5].body->GetWorldCenter());
	
	///////////DEBUG////////////
	if(pos.y<10)reachedHeight = true;
	else{reachedHeight = false;}
	//cout << reachedHeight << endl;
}

//--------------------------------------------------------------
void scenceTwo::destroyBallHolder(){

	for(int i =rects3.size()-1; i >= 0; i--){
			ofxBox2dRect b = rects3[i];
			b.destroyShape();
			rects3.erase(rects3.begin()+i);
			//free(&b);
		}
	soundSlot::loadSlot();
}
//--------------------------------------------------------------

void scenceTwo::ballJointFunction(int arrayNum1, int arrayNum2, float x, float y, float x2, float y2, float mass, float bounce, float friction, float radius, float mass2, float bounce2, float friction2, float radius2){
	
	ballJoints3[arrayNum1].setPhysics(mass, bounce, friction);
	ballJoints3[arrayNum1].setup("swingBall", box2d->getWorld(), x, y, radius);		
	
	ballJoints3[arrayNum2].setPhysics(mass2, bounce2, friction2);
	ballJoints3[arrayNum2].setup("swingBall",box2d->getWorld(), x2, y2, radius2);		
	
	//joints3[arrayNum1] = new ofxBox2dJoint;
	joints3[arrayNum1].setWorld(box2d->getWorld());
	joints3[arrayNum1].addJoint(ballJoints3[arrayNum2].body, ballJoints3[arrayNum1].body, 10.0, 0.0);
	
}
//--------------------------------------------------------------
void scenceTwo::revolJoint3(int ballArray, int ballPosX, int ballPosY, int radius, int rectArray, int rectPosX, int rectPosY, int jointArray, int motorSpeed){
	
	int w = 50;
	int h = 2;  // What size do you want??
	
	/////////////////////////JOINT FUNCTION I CREATED//////////////////////////
	ball3[ballArray] = new ofxBox2dCircle;
	ball3[ballArray]->setPhysics(0, 0.0, 0.0);
	ball3[ballArray]->setup("revolBall", box2d->getWorld(), ballPosX, ballPosY, radius);		
	
	rect3[rectArray] = new crossImage();
	rect3[rectArray]->setPhysics(1, 0.0, 0.0);
	rect3[rectArray]->setup(box2d->getWorld(), rectPosX, rectPosY, w,h,0);	
	
	revoluteJoint3[jointArray] = new ofxBox2dRevoluteJoint;
	revoluteJoint3[jointArray]->setWorld(box2d->getWorld());
	revoluteJoint3[jointArray]->addJoint(rect3[rectArray]->body, ball3[ballArray]->body, 3.0, 0.6,0,0,motorSpeed);
	
}
//--------------------------------------------------------------
void scenceTwo::ballHolder(){
	ofxBox2dRect rectHolder;
	rectHolder.setPhysics(0, 0.53, 0.1);
	rectHolder.setup("bucket", box2d->getWorld(), rightPos+150 , 150, 80, 2, 0.0, 0.0);
	rects3.push_back(rectHolder);

}
//--------------------------------------------------------------
void scenceTwo::worldRects(int posX, int posY, int w, int h, float ang, float spring){
	platformW = w;
	platformH = h;
	
	platform lineReplacer;
	lineReplacer.setPhysics(0, spring, 0.1);
	lineReplacer.setup("lineBox2",box2d->getWorld(), posX , posY, w, h, ang);
	lineRects.push_back(lineReplacer);
	
}