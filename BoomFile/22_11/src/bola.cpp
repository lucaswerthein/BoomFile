#include "bola.h"


void bola::setupBola(ofxBox2d * box2d){
	this->box2d = box2d;
}
//--------------------------------------------------------------
void bola::draw(){
	
	ofSetCircleResolution(100);
	
	ofPoint temp;
	temp.x = getPosition().x;
	temp.y = getPosition().y;
	points.push_back(temp);
	if (points.size() > 6){
		points.erase(points.begin());
	}
	
	
	float radius = getRadius();
	glPushMatrix();
	glTranslatef(getPosition().x, getPosition().y, 0);
	ofNoFill();
	ofSetColor(60, 40, 200, 100);
	ofCircle(0, 0, radius);
	glPopMatrix();

	
	ofBeginShape();
	ofNoFill();
	ofSetColor(255,255,255);
	for (int i = 0; i < points.size(); i++){
		//ofVertex(points[i].x, points[i].y);
		ofCircle(points[i].x, points[i].y, (i));
		
	}
	ofEndShape();

}
//--------------------------------------------------------------
void bola::dropBola(){
	float r = 5;
	bola Bola;
	Bola.setPhysics(1, 0.4, 0.05);
	Bola.setup(box2d->getWorld(), 1360+30, -10, r);
	circles.push_back(Bola);
	
}
//--------------------------------------------------------------
void bola::destroyBola(){
	for(int i =circles.size()-1; i >= 0; i--){
		ofPoint cPos = circles[i].getPosition();
		if (cPos.y>370){
			bola c = circles[i];
			c.destroyShape();
			circles.erase(circles.begin()+i);
			free(&c);
		}
	}
	
}
//--------------------------------------------------------------
void bola::drawBola(){
	for(int i=0; i<circles.size(); i++) {
		circles[i].draw();
	}	
}
