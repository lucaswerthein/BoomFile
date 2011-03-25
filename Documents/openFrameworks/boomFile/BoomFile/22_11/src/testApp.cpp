#include "testApp.h"
int testApp::worldCounter = 1;
//int testApp::dominoeTime  = 20; //20
int testApp::dominoeTime  = 430;

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
	
	///////////////DOMINO SOUND////////////////////
	if (s1 == "domino" && s2 == "domino") {
		
		bool body1Found = false;
		bool body2Found = false;
		for (int i = 0; i < collisions.size(); i++) {
			if (body1 == collisions[i]) body1Found = true;
			if (body2 == collisions[i]) body2Found = true;
		}
		
		if (!body1Found || !body2Found) {
			soundContact::loadSoundDomino();

		}
		
		collisions.push_back(body1);
		collisions.push_back(body2);
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
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	soundStarted = false;
	
	//------------------------COUNTERS------------------------//
	width				= 1360*3;
	height			= 384;
	counter			= 0;
	counter3			= 0;
	crazyTime		= 440; 
	//crazyTime		= 50;
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
	
	//------------------------DOMINOS-------------------------//
	bigDominos.setup(&box2d);
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

	//------------------------LOAD SOUND-----------------//
	crash.loadSound("crash.wav");
	//balloon.loadSound("balloon.wav");
	slurp.loadSound("slurp.wav");
	//--------------------------------------------------------//


}
//--------------------------------------------------------------
void testApp::update(){
	box2d.update();
	//------------------------PLAY SOUND------------------------//

	if(soundStarted){
		testApp::worldCounter++;
		if(testApp::worldCounter == 371){
			crash.play();
		}
		if(testApp::worldCounter == 243){
			//balloon.play();
		}
		if(testApp::worldCounter == 280){
			slurp.play();
		}
	}
	//-------------------------------------------------------//

	//------------------------DOMINOS------------------------//
	bigDominos.update();
	//-------------------------------------------------------//
		
	if(testApp::worldCounter==crazyTime){
		machine.loadSound("motorLong.mp3");
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
		counter3++;
		//if(counter %40 == 0)			pngBall.dropRedball();
		//if(counter ==15 )				pngBall.dropRedball();
		if(counter == 40)				pngBall.dropRedball();
		if (counter >= 1000){
			if(counter %160 == 0)		pngBall.dropRedball();
		 }

										pngBall.destroyRedBall();
	//--------------------------------------------------------//

	//------------------------BALL HOLDER 3-------------------//
		/*if(counter3%450 == 0){
			counter3 = 0;
			scenetwo.destroyBallHolder();
		}else if(counter3 >= 15){
			scenetwo.ballHolder();							
		}*/
		//scenetwo.destroyBallHolder();

	//--------------------------------------------------------//
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofScale(0.8, 0.8, 1);
	box2d.draw();
	bkgImage::drawImage();
	if(testApp::worldCounter<=crazyTime){

	//------------------------DOMINOS------------------------//
	bigDominos.draw();
	}
	//-------------------------------------------------------//
	
	if(testApp::worldCounter>=crazyTime){
		//------------------------DRAW BACKGROUND------------------------//
		//bkgImage::drawImage();
		//--------------------------------------------------------//
		
		//------------------------DRAW AIMATIONS-------------//
		movies.drawMovie();
		//--------------------------------------------------------//
	
		//------------------------SKETCH01------------------------//
		scenethree.draw();
		pngBall.drawRedBall();
		//--------------------------------------------------------//
		
		//------------------------SKETCH02------------------------//
		//if (ID == 0) {
		  sceneone.draw();
		//}
		//--------------------------------------------------------//
		
		//------------------------SKETCH03------------------------//
		scenetwo.draw();
		//--------------------------------------------------------//
		
	
	//------------------------FRAME RATE------------------------//
	string info = "";
	info += "FPS: "+ofToString(ofGetFrameRate())+"\n";
	info += "Total Bodies: "+ofToString(box2d.getBodyCount())+"\n";
	info += "Press z to load ball on right side""\n";
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
	
	if(key == 'p'){
		soundStarted = true;
		bigDominos.pushDominoForce();
		//scenetwo.ballHolder();		
		//soundContact::loadBall();

	}
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
