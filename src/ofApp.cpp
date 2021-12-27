#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 32);
    ofSetFrameRate(30);

    cam.lookAt(ofVec3f(0, 0, 0));
    cam.setDistance(500);

    counter = 0;
    sweaterIndex = 0;

    vector<string> files = {
        "sweater1.fbx", "sweater2.fbx", "sweater3.fbx",
        "sweater4.fbx", "sweater5.fbx", "sweater6.fbx",
        "sweater7.fbx", "sweater8.fbx", "sweater9.fbx"
    };

    for (size_t ii = 0; ii < files.size(); ++ii) {
        ofxFBX new_fbx;
        ofxFBXSource::Scene::Settings fbxSettings;
        fbxSettings.filePath = files[ii];

        if (new_fbx.load(fbxSettings)) {
            cout << "loaded the scene" << endl;
            new_fbx.setPosition(0, 0, 0);
            new_fbx.setScale(2.f);
            fbxs.push_back(new_fbx);
        } else {
            cout << "error loading the scene" << endl;
        }
    }

    //Snowflake snowflake = Snowflake(ofRandom(ofGetWidth()) - ofGetWidth() / 2.f,
    //                                ofRandom(ofGetHeight()) - ofGetHeight() / 2.f,
    //                                ofGetHeight() / 50.f);
    //snowflakes.push_back(snowflake);
}

//--------------------------------------------------------------
void ofApp::update(){
    ++counter;

    if (counter > 360) {
        counter = 0;
        ++sweaterIndex;
        sweaterIndex %= fbxs.size();
    }

    if (snowflakes.size() == 0 || snowflakes[snowflakes.size() - 1].is_complete()) {
        float h, w;
        while (true) {
            w = ofRandom(ofGetWidth());
            h = ofRandom(ofGetHeight());

            if ((w < ofGetWidth() / 4 || w > 3 * ofGetWidth() / 4)
                || h < ofGetHeight() / 4 || h > 3 * ofGetHeight() / 4) {
                w -= ofGetWidth() / 2.f;
                w /= 2;

                h -= ofGetHeight() / 2.f;
                h /= 2;
                break;
            }
        }

        Snowflake snowflake = Snowflake(w, h, ofGetHeight() / 100.f);
        snowflakes.push_back(snowflake);

        if (snowflakes.size() >= 20) {
            snowflakes.erase(snowflakes.begin(), snowflakes.begin() + 1);
        }
    }

    for (size_t ii = 0; ii < snowflakes.size(); ++ii) {
        snowflakes[ii].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();

    // cam.setDistance(500 + 20.0 * sin(counter / 10.0));
    ofRotateYDeg(counter);

    ofSetColor(255, 255, 255);
    fbxs[sweaterIndex].draw();

    ofRotateYDeg(-counter);
    cam.end();

    // cam.setDistance(500);

    cam.begin();
    for (size_t ii = 0; ii < snowflakes.size(); ++ii) {
        snowflakes[ii].draw();
    }

    cam.end();
}
