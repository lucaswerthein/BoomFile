#pragma once


class ofxBox2dPulleyJoint {
	
public:
	
	b2World * world;
	b2Joint * joint;
	bool alive;
	
	ofxBox2dPulleyJoint() {
		world = NULL;
		alive = false;
	}
	
	void setWorld(b2World * w) {
		if(w == NULL) {
			ofLog(OF_LOG_NOTICE, "- box2d world needed -");	
			return;
		}
		world = w;
		alive = true;
	}
	
	void destroyJoint() {
		world->DestroyJoint(joint);
		joint = NULL;
	}
	
	void addJoint(b2Body * a, b2Body * b, float rt = 1.0f, float ground1 = 0, float ground2 = 0, float max1 = 0.0f, float max2 = 0.0f ) {
		
		if(world == NULL) {
			ofLog(OF_LOG_NOTICE, "- no joint added - box2d world needed -");	
			return;
		}
		
		b2PulleyJointDef jd;
		b2Vec2 p1, p2;
		
		
		jd.body1 = a;
		jd.body2 = b;
		
		
		p1 = jd.body1->GetWorldPoint(jd.localAnchor1);
		p2 = jd.body2->GetWorldPoint(jd.localAnchor2);

		
		b2Vec2 anchor1 = a->GetWorldCenter();
		
		b2Vec2 anchor2 = b->GetWorldCenter();
		
		b2Vec2 groundAnchor1(p1.x, p1.y + ground1);
		
		b2Vec2 groundAnchor2(p2.x, p2.y + ground2);
		
		jd.Initialize(a, b, groundAnchor1, groundAnchor2, anchor1, anchor2, rt);
		
		jd.maxLength1 = max1;
		
		jd.maxLength2 = max2;
		
		joint = world->CreateJoint(&jd);
	}
	
	void draw(int alpha=200) {
		
		if(!alive) return;
		
		ofEnableAlphaBlending();
		ofSetColor(255, 0, 255, alpha);
		
		
		
		b2Vec2 p1 = ((b2PulleyJoint*)joint)->GetAnchor1();
		b2Vec2 p2 = ((b2PulleyJoint*)joint)->GetAnchor2();
		b2Vec2 g1 = ((b2PulleyJoint*)joint)->GetGroundAnchor1();
		b2Vec2 g2 = ((b2PulleyJoint*)joint)->GetGroundAnchor2();
	
		p1 *= OFX_BOX2D_SCALE;
		p2 *= OFX_BOX2D_SCALE;
		g1 *= OFX_BOX2D_SCALE;
		g2 *= OFX_BOX2D_SCALE;
		ofLine(p1.x, p1.y, g1.x, g1.y);	
		ofLine(p2.x, p2.y, g2.x, g2.y);
		ofDisableAlphaBlending();
	}
};












