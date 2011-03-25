#include "dominos.h"
bool dominos::loadedImage = false;
ofImage dominos::pipeDomino;

//--------------------------------------------------------------
void dominos::setup(ofxBox2d* box2d){
	this->box2d = box2d;
	dominoesFunction(10, 140, 20, 250);
	dominos::loadImage();
	
	float r = 20;		// a random radius 4px - 20px
	startBall.setPhysics(200.1, 0.5 ,0.5);	
	startBall.loadImage();
	startBall.setup("imageBall", box2d->getWorld(),  60, 10, r);
	
	
}
//--------------------------------------------------------------	
void dominos::update(){
	//testApp::worldCounter++;
	if(testApp::worldCounter%testApp::dominoeTime==0){
		for(int i =dominoes.size()-1; i >= 0; i--){
			ofxBox2dRect b = dominoes[i];
			b.destroyShape();
			dominoes.erase(dominoes.begin()+i);
			//free(&b);
		}
	}	
	
}

//--------------------------------------------------------------
void dominos::draw(){
	
	if(testApp::worldCounter <= testApp::dominoeTime){
		for(int i	=0; i<dominoes.size(); i++) {
			dominoes[i].draw();
		}
		startBall.draw();
		dominos::drawImage();
	}
	
	
	
}
//--------------------------------------------------------------
void dominos::dominoesFunction(int posX, float posY, int w, int h){
	
	ofxBox2dRect mrDominoe;
	mrDominoe.setPhysics(50.0, 0.53, 0.1);
	for(int i = 100; i < 2600+1420; i+=120){
		mrDominoe.setup("domino",box2d->getWorld(), (posX+i) , posY, w, h, 0);
		dominoes.push_back(mrDominoe);
		
	}
	ofxBox2dRect floor;
	floor.setPhysics(0.0, 0.53, 0.1);
	floor.setup("floor",box2d->getWorld(), 0 , 384, 4100, 1, 0);
	dominoes.push_back(floor);
	
	ofxBox2dRect holder;
	holder.setPhysics(0.0, 0.53, 0.1);
	holder.setup("floor",box2d->getWorld(), 50 , 150, 20, 5, 0);
	dominoes.push_back(holder);
	
	ofxBox2dRect barrier;
	barrier.setPhysics(0.0, 0.53, 0.1);
	barrier.setup("floor",box2d->getWorld(), 80 , 320, 5, 60, 0);
	dominoes.push_back(barrier);
	
}
//--------------------------------------------------------------
/*void dominos::giantDominoFunction(){
 
 ofxBox2dRect giantDomino;
 giantDomino.setPhysics(50.0, 0.53, 0.1);
 giantDomino.setup(box2d->getWorld(), 30 , 140, 20, 250, 0);
 dominoes.push_back(giantDomino);	
 }*/
//--------------------------------------------------------------
void dominos::pushDominoForce(){
	
	//for(int i = 65; i < 66; i++){
	for(int i = 32; i < 33; i++){
		
		ofPoint pos = dominoes[i].getPosition();
		ofPoint amount;
		amount.x = -10000;
		amount.y = 0;
		dominoes[i].addForce(pos, amount);
	}
	
}
//--------------------------------------------------------------
void dominos::loadImage(){
	if(!loadedImage) {
		ofSetRectMode(OF_RECTMODE_CENTER);
		pipeDomino.setImageType(OF_IMAGE_COLOR_ALPHA);
		pipeDomino.loadImage("pipeDomino.png");
		pipeDomino.resize(pipeDomino.getWidth()/1.5, pipeDomino.getHeight()/1.5);
		loadedImage = true;
	}
}
//--------------------------------------------------------------
void dominos::drawImage(){
	//ofEnableAlphaBlending();
	ofNoFill();
	ofSetColor(255,255,255);
	pipeDomino.draw(45,330);
	
}

