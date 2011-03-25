/*
 *  ofxBox2dCrissCross.h
 *  ballRotate
 *
 *
 */


#pragma once
#include "ofMain.h"
#include "ofxBox2dBaseShape.h"

class ofxBox2dCompound : public ofxBox2dBaseShape {
	
public:
	
	
	b2PolygonDef shape1;
	b2PolygonDef shape2;	
	b2PolygonDef shape3;
	//------------------------------------------------
	
	ofxBox2dCompound() {
	}
	
	//------------------------------------------------
	void setup(b2World * b2dworld, float x, float y, float w, float h, bool isFixed=false) {
		
		if(b2dworld == NULL) {
			ofLog(OF_LOG_NOTICE, "- must have a valid world -");
			return;
		}
		
		world				= b2dworld;
		bIsFixed			= isFixed;
		
		//Rect Shape
		//w/=2; h/=2;
		shape1.SetAsBox(30.0f/OFX_BOX2D_SCALE, 10.0f/OFX_BOX2D_SCALE);
		
		// A little hacky, but just making a second one with inverse dimensions
		shape2.SetAsBox(10.0f/OFX_BOX2D_SCALE, 30.0f/OFX_BOX2D_SCALE, b2Vec2(-1.6f, -0.6f),0.75f * 3.1415f);
		
		shape3.SetAsBox(10.0f/OFX_BOX2D_SCALE, 30.0f/OFX_BOX2D_SCALE, b2Vec2(1.6f, -0.6f),0.25f * 3.1415f);
		//Build Body for shape
		b2BodyDef bodyDef;
		
		//set properties
		if(isFixed) {
			shape1.density	  = 1.0f;
			shape1.restitution = 0;
			shape1.friction	  = 1.0;
			shape2.density	  = 1.0f;
			shape2.restitution = 0;
			shape2.friction	  = 1.0;
			shape3.density	  = 1.0f;
			shape3.restitution = 0;
			shape3.friction	  = 1.0;
		}
		else {
			shape1.density	  = mass;
			shape1.restitution = bounce;
			shape1.friction	  = friction;
			shape2.density	  = mass;
			shape2.restitution = bounce;
			shape2.friction	  = friction;
			shape3.density	  = mass;
			shape3.restitution = bounce;
			shape3.friction	  = friction;
		}
		
		// need to check for rect mode
		x += w; y += h;
		bodyDef.position.Set(x/OFX_BOX2D_SCALE, y/OFX_BOX2D_SCALE);	
		
		body = world->CreateBody(&bodyDef);
		//body->SetLinearVelocity(b2Vec2(0.0, 0.0));
		body->CreateShape(&shape1);
		body->CreateShape(&shape2);
		body->CreateShape(&shape3);

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
			
			ofSetColor(255, 255, 255);
			ofNoFill();
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














