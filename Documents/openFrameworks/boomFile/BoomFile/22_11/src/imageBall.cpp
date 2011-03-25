#include "imageBall.h"

bool imageBall::loadedImage = false;
ofImage imageBall::tball;
//--------------------------------------------------------------
void imageBall::setupRedBall(ofxBox2d * box2d){
	this->box2d = box2d;
}

//--------------------------------------------------------------
void imageBall::loadImage(){
	if(!loadedImage) {
		//printf("here \n");
		ofSetRectMode(OF_RECTMODE_CENTER);
		tball.setImageType(OF_IMAGE_COLOR_ALPHA);
		tball.loadImage("bball.png");
		
		cout << "just loaded bball.png" << endl;
		
		//printf("%i %i \n", tball.width, tball.height);
		
		loadedImage = true;
	}
}
//--------------------------------------------------------------

void imageBall::draw(){
	
	ofPoint temp;
	temp.x = getPosition().x;
	temp.y = getPosition().y;
	points.push_back(temp);
	if (points.size() > 6){
		points.erase(points.begin());
	}
	float radius = getRadius();
	float rotation = getRotation() * 2;
	glPushMatrix();
	glTranslatef(getPosition().x, getPosition().y, 0);
	glRotated(rotation, 0, 0, 1);
	ofNoFill();
	ofSetColor(255,255,255);
	ofEnableAlphaBlending();
	tball.draw(0,0, radius*2, radius*2);
	glPopMatrix();
	ofFill();
	ofSetColor(20,20,20,150);
	for (int i = 0; i < points.size(); i++){
		ofRect(points[i].x, points[i].y, (i), (i));

		
	}
	
}
//--------------------------------------------------------------
void imageBall::dropRedball(){
	float r = 7;		// a random radius 4px - 20px
	imageBall ourBall;
	ourBall.setPhysics(0.1, 0.0 ,0.00);	
	ourBall.loadImage();
	ourBall.setup("imageBall", box2d->getWorld(),  50, 10, r);
	redBall.push_back(ourBall);
}

//--------------------------------------------------------------
void imageBall::dropRedball2(){
	float r = 7;		// a random radius 4px - 20px
	imageBall ourBall;
	ourBall.setPhysics(0.1, 0.0 ,0.00);	
	ourBall.loadImage();
	ourBall.setup("imageBall", box2d->getWorld(),  2130, 10, r);
	redBall.push_back(ourBall);
}

//--------------------------------------------------------------
void imageBall::drawRedBall(){
	for(int i = 0; i < redBall.size(); i++){
		redBall[i].draw();
	}
}

//--------------------------------------------------------------
void imageBall::destroyRedBall(){
	for(int i =redBall.size()-1; i >= 0; i--){
		ofPoint cPos = redBall[i].getPosition();
		if (cPos.y>384){
			imageBall c = redBall[i];
			c.destroyShape();
			redBall.erase(redBall.begin()+i);
			//free(&c);
		}
	}
	
}