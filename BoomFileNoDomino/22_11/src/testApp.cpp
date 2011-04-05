#include "testApp.h"
int testApp::worldCounter = 1;
//--------------------------------------------------------------

vector<b2Body*> collisions;

void MyContactListener::Add(const b2ContactPoint* point){
	
	b2Body* body1 = point->shape1->GetBody();
	b2Body* body2 = point->shape2->GetBody();
	
	char *s1 = (char *) body1->GetUserData();
	char *s2 = (char *) body2->GetUserData();
	
	
	///////////////RECT SOUND////////////////////
	if (s1 == "imageBall" && s2 == "lineBox") {
		soundRect::loadRect();
	} else if (s1 == "lineBox" && s2 == "imageBall") {
		soundRect::loadRect();
	}
	
	///////////////RECT SOUND 2////////////////////
	if (s1 == "imageBall" && s2 == "lineBox2") {
		soundRect2::loadRect2();
	} else if (s1 == "lineBox2" && s2 == "imageBall") {
		soundRect2::loadRect2();
	}
	///////////////BUCKET SOUND////////////////////
	if (s1 == "imageBall" && s2 == "bucket") {
		soundBucket::loadBucket();
	} else if (s1 == "bucket" && s2 == "imageBall") {
		soundBucket::loadBucket();
	}
	
	///////////////MIRO SOUND////////////////////
	if (s1 == "imageBall" && s2 == "swingBall") {
		soundBucket::loadBucket();
	} else if (s1 == "swingBall" && s2 == "imageBall") {
		soundMiro::loadMiro();
	}
	
	///////////////BRIDGE SOUND////////////////////
	if (s1 == "imageBall" && s2 == "bridgeBall") {
		soundBucket::loadBucket();
	} else if (s1 == "bridgeBall" && s2 == "imageBall") {
		soundBridge::loadBridge();
	}
	
		
}	
//--------------------------------------------------------------
void MyContactListener::Remove(const b2ContactPoint* point){
	
}
//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
	ofBackground(4, 4, 4);
	ofSetLogLevel(OF_LOG_NOTICE);
	ofEnableSmoothing();
	ofSetCircleResolution(100);
	ofSetRectMode(OF_RECTMODE_CENTER);
	soundStarted = false;
	
	//------------------------COUNTERS------------------------//
	width				= 1360*3;
	height				= 384;
	counter				= 0;
	crazyTime			= 2; 
	//--------------------------------------------------------//

	//------------------------BOX2D WORLD---------------------//
	box2d.init();
	box2d.setGravity(0, 20);
	box2d.createBounds(0, 0, width, height);	
	box2d.setFPS(30.0);
	box2d.getWorld() -> SetContactListener(&contacts);
	//--------------------------------------------------------//

	//------------------------LOAD BACKGROUND-----------------//
	bkgImage::loadImage();
	//--------------------------------------------------------//
	 
	//------------------------SKETCH01------------------------//
	scenethree.setup(&box2d);
	//--------------------------------------------------------//
	
	//------------------------SKETCH02------------------------//
	sceneone.setup(&box2d);
	//--------------------------------------------------------//
	
	//------------------------SKETCH03------------------------//
	scenetwo.setup(&box2d);
	//--------------------------------------------------------//
	
	//------------------------IMAGEBALL-----------------------//
	pngBall.setupRedBall(&box2d);
	//--------------------------------------------------------//
	
	//------------------------LOAD AIMATIONS-----------------//
	movies.loadMovie();
	//--------------------------------------------------------//

	//--------------------------------------------------------//
	soundStarted = true;


}
//--------------------------------------------------------------
void testApp::update(){
		
	box2d.update();
	if(soundStarted){
		testApp::worldCounter++;
	}
	//-------------------------------------------------------//
		
	if(testApp::worldCounter==crazyTime){
		machine.loadSound("motorLong.mp3");
		machine.setLoop(true);
		machine.play();
		//------------------------SKETCH01------------------------//
		scenethree.update();
		//--------------------------------------------------------//
		
		//------------------------SKETCH02------------------------//
		sceneone.update();
		//--------------------------------------------------------//
		
		//------------------------SKETCH03------------------------//
		scenetwo.update();
		//--------------------------------------------------------//
	}
	
	//------------------------BALLS------------------------//
	if(testApp::worldCounter>=crazyTime){
		counter++;
		if(counter == 40)				pngBall.dropRedball();
		if (counter >= 1000){
			if(counter %160 == 0)		pngBall.dropRedball();
			counter = 0;
			testApp::worldCounter = 10;
		 }

		pngBall.destroyRedBall();
	//--------------------------------------------------------//

	}
}

//--------------------------------------------------------------
void testApp::draw(){
	box2d.draw();
	bkgImage::drawImage();
	//-------------------------------------------------------//
	
	if(testApp::worldCounter>=crazyTime){
		
		//------------------------DRAW AIMATIONS-------------//
		movies.drawMovie();
		//--------------------------------------------------------//
	
		//------------------------SKETCH01------------------------//
		scenethree.draw();
		pngBall.drawRedBall();
		//--------------------------------------------------------//
		
		//------------------------SKETCH02------------------------//
		sceneone.draw();
		//--------------------------------------------------------//
		
		//------------------------SKETCH03------------------------//
		scenetwo.draw();
		//--------------------------------------------------------//
	
	//------------------------FRAME RATE------------------------//
	string info = "";
	info += "FPS: "+ofToString(ofGetFrameRate())+"\n";
	info += "Total Bodies: "+ofToString(box2d.getBodyCount())+"\n";
	info += "Press b to load ball""\n";
	info += "Press c to create BallHolder""\n";
	info += "Press d to destroy BallHolder""\n";
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(info, 900, 30);
	//--------------------------------------------------------//

	}
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
	

	if(key == 'b'){
		pngBall.dropRedball();
	}
	if(key == 'z'){
		pngBall.dropRedball2();
	}	
	if(key == 'c'){
		scenetwo.ballHolder();							
	}
	if(key == 'd'){
		scenetwo.destroyBallHolder();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}
