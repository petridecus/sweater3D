#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "ofMain.h"

struct Particle
{
	ofVec3f pos;
	float rad;

	float rand = 128 + ofRandom(0, 127);
	ofVec3f color{rand, rand, 255};

	Particle() = default;
	Particle(ofVec3f _pos, float _rad) {
		this->pos = _pos;
		this->rad = _rad;
	}

	void update() {
		this->pos.x -=3;
		this->pos.y += ofRandom(-10.f,10.f);
	}

	void draw() {
		ofSetColor(color.x,color.y,color.z);
		ofDrawSphere(this->pos, rad);
		// ofDrawCircle(this->pos,rad);
	}

	bool finished() {
		return this->pos.x < 0.f;
	}

	bool intersects(std::vector<Particle>& others) {
		for(auto & p :others)
		{
			auto d = ofDist(p.pos.x,p.pos.y,p.pos.z,
							this->pos.x,this->pos.y,this->pos.z);
			if(d < this->rad * 4)
			{
				return true;
			}
		}
		return false;
	}
};

#endif // PARTICLE_H_
