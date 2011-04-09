#include "testApp.h"
int testApp::worldCounter = 1;
//--------------------------------------------------------------

vector<b2Body*> collisions;

void MyContactListener::Add(const b2ContactPoint* point){
	
	b2Body* body1 = point->shape1->GetBody();
	b2Body* body2 = point->shape2->GetBody();
	
	char *s1 = (char *) body1->GetUserData();
	char *s2 = (char *) body2->GetUserData();
	
	///////////////BALL SOUND////////////////////
	if (s1 == "imageBall" && s2 == "domino") {
		soundBall::loadBall();
	} else if (s1 == "domino" && s2 == "imageBall") {
		soundBall::loadBall();
	}
	
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
	//ofSetVerticalSync(true);
	ofBackground(4, 4, 4);
	ofSetLogLevel(OF_LOG_NOTICE);
	ofEnableSmoothing();
	ofSetCircleResolution(100);
	ofSetBackgroundAuto(false);
	ofSetRectMode(OF_RECTMODE_CENTER);
	client.setup("settings.xml", this);
	ofSeedRandom(1);
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
	client.start();
	
	soundStarted = true;

}

//--------------------------------------------------------------
void testApp::frameEvent(){
	ofScale(2, 2, 1);
	ofNoFill();
	ofBackground(0, 0, 0);
	ofSetColor(255, 255, 255);	
	box2d.update();
	box2d.draw();
	bkgImage::drawImage();

	//------------------------SET UP APP------------------------//
	if(soundStarted)testApp::worldCounter++;
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
	
	//------------------------DRAW TO SCREEN------------------------//
	if(testApp::worldCounter>=crazyTime){
		counter++;
		movies.drawMovie();
		scenethree.draw();
		pngBall.drawRedBall();
		sceneone.draw();
		scenetwo.draw();
		if(counter == 40)				pngBall.dropRedball();
		if (counter >= 1000){
			if(counter %160 == 0)		pngBall.dropRedball();
			counter = 0;
			testApp::worldCounter = 10;
		}
		pngBall.destroyRedBall();
	}
	//------------------------MESSAGES------------------------//
	if (client.messageAvailable()) {
		
		
		//cout << "SUCCESS!" << msg[0];  //optional
		string msg = client.getDataMessageString();
		if (msg.at(0) == 'c') {
			scenetwo.ballHolder();							
		}
		
		/*if (msg.at(0) == 'p') {
			soundStarted = true;
			bigDominos.pushDominoForce();
		}*/
		if (msg.at(0) == 'b') {
			pngBall.dropRedball();
			
		}
		if (msg.at(0) == 'd') {
			scenetwo.destroyBallHolder();
		}
		if (msg.at(0) == 'z') {
			pngBall.dropRedball2();
		}
		
		
		/*vector<string> msg0 = client.getDataMessage();
		if (msg0[0].at(0) == 'c') {
			scenetwo.ballHolder();							
		}
		
		vector<string> msg2 = client.getDataMessage();
		if (msg2[0].at(0) == 'p') {
			soundStarted = true;
			bigDominos.pushDominoForce();
		}
		vector<string> msg3 = client.getDataMessage();
		if (msg3[0].at(0) == 'b') {
			pngBall.dropRedball();
		
		}
		vector<string> msg1 = client.getDataMessage();
		if (msg1[0].at(0) == 'd') {
			scenetwo.destroyBallHolder();
		}
		vector<string> msg4 = client.getDataMessage();
		if (msg4[0].at(0) == 'z') {
			pngBall.dropRedball2();
		}*/
		
	}
	//--------------------------------------------------------//

	
}
//--------------------------------------------------------------
void testApp::update(){

}
//--------------------------------------------------------------
void testApp::draw(){

}
//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
