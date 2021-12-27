#pragma once

#include "ofMain.h"
#include "ofxFBX.h"
#include "Snowflake.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	private:
		ofEasyCam cam;
		vector<ofxFBX> fbxs;
		vector<Snowflake> snowflakes;

		size_t counter;
		size_t sweaterIndex;
};
