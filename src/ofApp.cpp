#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 32);
    ofSetFrameRate(30);
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
            fbxs.push_back(new_fbx);
        } else {
            cout << "error loading the scene" << endl;
        }
    }

    cam.lookAt(ofVec3f(0, 0, 0));
    cam.setDistance(500);
}

//--------------------------------------------------------------
void ofApp::update(){
    ++counter;

    if (counter > 1080) {
        counter = 0;
        ++sweaterIndex;
        sweaterIndex %= fbxs.size();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.setDistance(500 + 20.0 * sin(counter / 10.0));
    ofRotateYDeg(counter);
    fbxs[sweaterIndex].draw();
    cam.end();
}
