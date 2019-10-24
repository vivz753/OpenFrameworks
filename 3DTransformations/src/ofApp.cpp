#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    theCam = &easyCam;
    easyCam.setDistance(15);
    easyCam.setNearClip(.1);
    degrotateX = 0;
    degrotateY = 0;
    degrotateZ = 0;
    gui.setup();
    gui.add(sliderX.setup("X axis", degrotateX, 0, 360));
    gui.add(sliderY.setup("Y axis", degrotateY, 0, 360));
    gui.add(sliderZ.setup("Z axis", degrotateZ, 0, 360));
}

glm::mat4 ofApp::getRotationMatrix(glm::mat4 matrix, float angle, string axis) {
    if (axis == "X")
        return glm::rotate(matrix, glm::radians(angle), glm::vec3(1,0,0));
    else if (axis == "Y")
        return glm::rotate(matrix, glm::radians(angle), glm::vec3(0,1,0));
    else if (axis == "Z")
        return glm::rotate(matrix, glm::radians(angle), glm::vec3(0,0,1));
}

glm::mat4 ofApp::getTranslationMatrix(glm::mat4 matrix, glm::vec3 translate) {
    return glm::translate(matrix, translate);
}

// To rotate an object at a random point, you need to translate it to the origin, perform the rotation, and then translate back to the point it was at.

void ofApp::drawAxis() {
    ofSetColor(255, 0, 0);
    ofDrawLine(glm::vec3(0,0,0), glm::vec3(0,10,0));
    ofSetColor(0, 255, 0);
    ofDrawLine(glm::vec3(0,0,0), glm::vec3(10,0,0));
    ofSetColor(0, 0, 255);
    ofDrawLine(glm::vec3(0,0,0), glm::vec3(0,0,10));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();

    theCam -> begin();
    
    drawAxis();
    
    Pyramid p = Pyramid();
    
    glm::vec3 translate = glm::vec3(5, 3, 0);
    glm::mat4 translateToPoint = getTranslationMatrix(m, translate);
    
    p.transform(translateToPoint);
    
    glm::mat4 rotationMatrixX = getRotationMatrix(m, sliderX, "X");
    glm::mat4 rotationMatrixY = getRotationMatrix(m, sliderY, "Y");
    glm::mat4 rotationMatrixZ = getRotationMatrix(m, sliderZ, "Z");
    
    glm::mat4 translateToOriginMatrix = getTranslationMatrix(m, glm::vec3(-translate.x, -translate.y, -translate.z));
    
    p.transform(translateToOriginMatrix);
    p.transform(rotationMatrixX * rotationMatrixY * rotationMatrixZ);
    p.transform(translateToPoint);
    
    
    p.draw();
    
    theCam->end();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
