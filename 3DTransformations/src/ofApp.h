#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Triangle {
public:
    int i, j, k;
    
    Triangle(int one, int two, int three) {
        i = one;
        j = two;
        k = three;
    };
};

class Pyramid {
    public:
        vector<Triangle> triangles;
        vector<glm::vec3> pyramidPoints;
    
    Pyramid() {
        pyramidPoints.push_back(glm::vec3(1, 0, 1)); // 0
        pyramidPoints.push_back(glm::vec3(-1, 0, 1)); // 1
        pyramidPoints.push_back(glm::vec3(-1, 0, -1)); // 2
        pyramidPoints.push_back(glm::vec3(1, 0, -1)); // 3
        pyramidPoints.push_back(glm::vec3(0, 2, 0)); // top point or 4
        
        triangles.push_back(Triangle(0, 1, 2));
        triangles.push_back(Triangle(0, 2, 3));
        triangles.push_back(Triangle(1, 0, 4));
        triangles.push_back(Triangle(0, 4, 3));
        triangles.push_back(Triangle(4, 2, 3));
        triangles.push_back(Triangle(4, 2, 1));
        triangles.push_back(Triangle(0, 1, 2));
        triangles.push_back(Triangle(0, 2, 3));
    }
    
    void draw() {
        for(int tri = 0; tri < triangles.size(); tri++) {
            ofSetColor(ofColor::red);
            ofFill();
            ofDrawLine(pyramidPoints[triangles[tri].i], pyramidPoints[triangles[tri].j]);
            ofDrawLine(pyramidPoints[triangles[tri].j], pyramidPoints[triangles[tri].k]);
            ofDrawLine(pyramidPoints[triangles[tri].k], pyramidPoints[triangles[tri].i]);
        }
    }
    
    void transform(glm::mat4 matrix) {
        for(int i = 0; i < pyramidPoints.size(); i++) {
            glm::vec4 v = glm::vec4(pyramidPoints[i], 1);
            pyramidPoints[i] = glm::vec3(matrix * v);
        }
    }
};

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
        void applyMatrix(glm::mat4 matrix);
        void drawAxis();
        glm::mat4 getTranslationMatrix(glm::mat4 matrix, glm::vec3 translate);
        glm::mat4 getRotationMatrix(glm::mat4 matrix, float angle, string axis);
        glm::mat4 rotateRandom(glm::vec3 p, float angle);
        glm::mat4 m = glm::mat4(1.0);
        ofCamera *theCam;
        ofEasyCam easyCam;
        ofxPanel gui;
        ofxFloatSlider sliderX;
        ofxFloatSlider sliderY;
        ofxFloatSlider sliderZ;
        float degrotateX;
        float degrotateY;
        float degrotateZ;
};
