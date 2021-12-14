#pragma once

#include "ofMain.h"
#include "ofxFBX.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	private:
		ofEasyCam cam;
		vector<ofxFBX> fbxs;

		size_t counter;
		size_t sweaterIndex;
};
