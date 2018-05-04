#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(270);

	vector<ofPoint> points;
	for (int i = 0; i < 512; i++) {

		int radius = ofRandom(100, 300);
		float z_speed = ofRandom(1, 3);
		float deg_speed = ofRandom(1, 2);

		float deg = ofRandom(360) + ofGetFrameNum() * deg_speed;
		float z = ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2);
		z += (int)(z + ofGetFrameNum() * z_speed) % ofGetWidth() - ofGetWidth() / 2;
		ofPoint point(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);

		points.push_back(point);
	}
	
	for (int i = 0; i < points.size(); i++) {

		for (int j = i + 1; j < points.size(); j++) {

			float distance = points[i].distance(points[j]);
			if (distance < 40) {

				ofSetColor(239, ofMap(distance, 0, 40, 255, 128));

				ofDrawLine(points[i], points[j]);
				ofDrawSphere(points[i], 3);
				ofDrawSphere(points[j], 3);
			}
			else if(distance < 50){

				ofSetColor(239, ofMap(distance, 40, 50, 128, 0));

				ofDrawLine(points[i], points[j]);
				ofDrawSphere(points[i], 3);
				ofDrawSphere(points[j], 3);
			}
		}
	}
	

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}