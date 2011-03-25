/*
 *  ofxBox2dCrissCross.h
 *  ballRotate
 *
 *
 */


#pragma once
#include "ofMain.h"
#include "ofxBox2dBaseShape.h"

class ofxBox2dCrissCross : public ofxBox2dBaseShape {
	
public:
	
	
	b2PolygonDef shape1;
	b2PolygonDef shape2;	
	
	int drawW;
	int drawH;
	//------------------------------------------------
	
	ofxBox2dCrissCross() {
	}
	
	//------------------------------------------------
	void setup(b2World * b2dworld, float x, float y, float w, float h, bool isFixed=false) {
		
		if(b2dworld == NULL) {
			ofLog(OF_LOG_NOTICE, "- must have a valid world -");
			return;
		}
		
		world				= b2dworld;
		bIsFixed			= isFixed;
		
		drawW = w;
		drawH = h;
		
		//Rect Shape
		w/=2; h/=2;
		shape1.SetAsBox(w/OFX_BOX2D_SCALE, h/OFX_BOX2D_SCALE);
		
		// A little hacky, but just making a second one with inverse dimensions
		shape2.SetAsBox(h/OFX_BOX2D_SCALE, w/OFX_BOX2D_SCALE);
		
		//Build Body for shape
		b2BodyDef bodyDef;
		
		//set properties
		if(isFixed) {
			shape1.density	  = 0;
			shape1.restitution = 0;
			shape1.friction	  = 0;
			shape2.density	  = 0;
			shape2.restitution = 0;
			shape2.friction	  = 0;
		}
		else {
			shape1.density	  = mass;
			shape1.restitution = bounce;
			shape1.friction	  = friction;
			shape2.density	  = mass;
			shape2.restitution = bounce;
			shape2.friction	  = friction;
		}
		
		// need to check for rect mode
		x += w; y += h;
		bodyDef.position.Set(x/OFX_BOX2D_SCALE, y/OFX_BOX2D_SCALE);	
		
		body = world->CreateBody(&bodyDef);
		body->SetLinearVelocity(b2Vec2(0.0, 0.0));
		body->CreateShape(&shape1);
		body->CreateShape(&shape2);
		body->SetMassFromShapes();
		
		// anything that you need called
		init();
	}
	
	
	
	//------------------------------------------------
	/* float getRadius() {
	 b2Shape* shape		= body->GetShapeList();
	 b2CircleShape *data = (b2CircleShape*)shape;
	 
     return data->GetRadius() * OFX_BOX2D_SCALE;
	 }*/
	
	//------------------------------------------------
	float getRotation() {
		return ofRadToDeg(body->GetAngle());
	}
	
	
	//------------------------------------------------
	void draw() {
		
		if(dead) return;
		
		//wow this is a pain
		b2Shape* s = body->GetShapeList();
		const b2XForm& xf = body->GetXForm();
		
		while (s != NULL) {
			
			b2PolygonShape* poly = (b2PolygonShape*)s;
			int count = poly->GetVertexCount();
			const b2Vec2* localVertices = poly->GetVertices();
			b2Assert(count <= b2_maxPolygonVertices);
			b2Vec2 verts[b2_maxPolygonVertices];
			for(int32 i=0; i<count; ++i) {
				verts[i] = b2Mul(xf, localVertices[i]);
			}
			
			
			ofEnableAlphaBlending();
			//ofSetColor(10, 10, 10, 100);
			ofSetColor(0, 0, 0, 0);
			ofFill();
			ofBeginShape();
			for (int32 i = 0; i <count; i++) {
				ofVertex(verts[i].x*OFX_BOX2D_SCALE, verts[i].y*OFX_BOX2D_SCALE);
			}
			ofEndShape();
			
			ofSetColor(0, 0, 0,180);
			//ofNoFill();
			ofBeginShape();
			for (int32 i = 0; i <count; i++) {
				ofVertex(verts[i].x*OFX_BOX2D_SCALE, verts[i].y*OFX_BOX2D_SCALE);
			}
			ofEndShape(true);	
			ofDisableAlphaBlending();
			
			s = s->GetNext();
			
		}
	}
	
};














