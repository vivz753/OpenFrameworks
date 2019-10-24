#include "ofApp.h"
//Lab 2 by Alora Clem for CS116A

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(xAxisAngle.setup("Angle for X-axis", 0, 360, 0));
    gui.add(yAxisAngle.setup("Angle for Y-axis", 0, 360, 0));
    gui.add(zAxisAngle.setup("Angle for Z-axis", 0, 360, 0));
    cam.setDistance(10);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::drawAxis(){
    ofSetColor(ofColor::red);
    ofDrawLine(glm::vec3(0,0,0),  glm::vec3 (10,0,0));
    ofSetColor(ofColor::green);
    ofDrawLine(glm::vec3(0,0,0),  glm::vec3 (0,10,0));
    ofSetColor(ofColor::blue);
    ofDrawLine(glm::vec3(0,0,0),  glm::vec3 (0,0,10));
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    cam.begin();
    drawAxis();
    Pyramid p = Pyramid();
    p.setup();
    ofSetColor(ofColor::black);
    glm::mat4 m(1.0);//identity matrix
    
    /*
     //rotate 45 degrees on z axis
     float fourtyFiveDegrees= PI/4;
     glm::mat4 rotationMatrixZby45 = glm::rotate(m, fourtyFiveDegrees, glm::vec3(0, 0, 1));
     p.transform(rotationMatrixZby45);
     ofSetColor(ofColor::white);
     p.draw();
     p.setup();
     glm::vec3 translate = glm::vec3(-1, 2, 2);
     glm::mat4 translateMatrixArbitrary = glm::translate(m, translate);
     p.transform(translateMatrixArbitrary * rotationMatrixZby45);
     ofSetColor(ofColor::violet);
     p.draw();
     p.setup();
     ofSetColor(ofColor::orange);
     p.transform(rotationMatrixZby45 * translateMatrixArbitrary);
     p.draw();
     */
    
    //translate to arbitrary positon
    glm::vec3 translate = glm::vec3(-1, 2, 2);
    
    glm::mat4 translateMatrixArbitrary = glm::translate(m, translate);
    cout << translateMatrixArbitrary << endl;
    p.transform(translateMatrixArbitrary);
    
    glm::mat4 translateMatrixBackToOrigin = glm::translate(m, glm::vec3(-translate.x, -translate.y, -translate.z));
    cout << translateMatrixBackToOrigin << endl;
    
    //angles to rotate based on sliders
    float xRotation = (xAxisAngle * PI)/180.0;
    float yRotation = (yAxisAngle * PI)/180.0;
    float zRotation = (zAxisAngle * PI)/180.0;
    glm::mat4 rotationMatrixOnX = glm::rotate(m, xRotation, glm::vec3(1, 0, 0));
    glm::mat4 rotationMatrixOnY = glm::rotate(m, yRotation, glm::vec3(0, 1, 0));
    glm::mat4 rotationMatrixOnZ = glm::rotate(m, zRotation, glm::vec3(0, 0, 1));
    //all rotation matrix's applied together
    glm::mat4 resultingRotationMatrix = rotationMatrixOnX * rotationMatrixOnY * rotationMatrixOnZ;
    
    p.transform(translateMatrixBackToOrigin);//translate back to origin
    p.transform(resultingRotationMatrix);//translate by rotating
    p.transform(translateMatrixArbitrary);//translate back to arbitrary position
    
    p.draw();
    cam.end();
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
