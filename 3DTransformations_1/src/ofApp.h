#pragma once
//Lab 2 by Alora Clem for CS116A
#include "ofMain.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void drawAxis();
    
    ofEasyCam cam;
    ofxFloatSlider xAxisAngle;
    ofxFloatSlider yAxisAngle;
    ofxFloatSlider zAxisAngle;
    ofxPanel gui;
    
};
class Pyramid {
public:
    vector<glm::vec3> pyramid;
    
    void setup(){
        pyramid.clear();
        pyramid.push_back(glm::vec3(0, 0, 1));
        pyramid.push_back(glm::vec3(1, 0, -1));
        pyramid.push_back(glm::vec3(-1, 0, -1));
        pyramid.push_back(glm::vec3(0, 1, -1));
        pyramid.push_back(glm::vec3(0, -1, -1));
    }
    
    void draw(){
        ofDrawLine(pyramid[0], pyramid[1]);
        ofDrawLine(pyramid[0], pyramid[2]);
        ofDrawLine(pyramid[0], pyramid[3]);
        ofDrawLine(pyramid[0], pyramid[4]);
        ofDrawLine(pyramid[0], pyramid[1]);
        ofDrawLine(pyramid[1], pyramid[4]);
        ofDrawLine(pyramid[2], pyramid[3]);
        ofDrawLine(pyramid[3], pyramid[1]);
        ofDrawLine(pyramid[4], pyramid[2]);
    }
    
    void transform(glm::mat4 matrix){
        for(int i = 0; i < pyramid.size(); i ++){
            glm::vec3 point = pyramid[i];
            pyramid[i] = glm::vec3(matrix * glm::vec4(point.x, point.y, point.z, 1));
        }
    }
};
