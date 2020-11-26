#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(80, 0);
    
    int numBalls = 80;
    
    // fill our vector
    for (int i = 0; i < numBalls; i++) {        // loop 30 times
        
        Ball tempBall;                    // create a temporary ball
        balls.push_back(tempBall);        // copy the temporary ball into the balls vector
        // (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
    }

    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.

    bAnimate = false;
    bAnimateMouse = false;
    animationPosition = 0;

    model.loadModel("winter7.dae", false);
    model.setPosition(ofGetWidth() * 0.5, (float)ofGetHeight() * 0.5 , 0);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();
    if(!bAnimate) {
        model.setPausedForAllAnimations(true);
    }

    bHelpText = true;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    model.update();

    if(bAnimateMouse) {
        model.setPositionForAllAnimations(animationPosition);
    }

    mesh = model.getCurrentAnimatedMesh(0);
    
    // update each ball in our vector
    for (int i = 0; i < balls.size(); i++) {    // one way to loop through a whole vector
        
        balls[i].update();    // we can access an individual ball by its "index" number in the vector
        // e.g. balls[0] is the first ball in the vector, balls[1] is the second ball, etc.
        // (note that vectors always start at 0, not 1!!)
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    
    
    for (int i = 0; i < balls.size(); i++) {
        
        balls[i].draw();
    }
    

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

	ofEnableDepthTest();
#ifndef TARGET_PROGRAMMABLE_GL
    glShadeModel(GL_SMOOTH); //some model / light stuff
#endif
    light.enable();
    ofEnableSeparateSpecularLight();

    ofPushMatrix();
    ofTranslate(model.getPosition().x+100, model.getPosition().y, 0);
    ofRotateDeg(-mouseX, 0, 1, 0);
    ofTranslate(-model.getPosition().x, -model.getPosition().y, 0);
    model.drawFaces();
    ofPopMatrix();
#ifndef TARGET_PROGRAMMABLE_GL
    glEnable(GL_NORMALIZE);
#endif
    ofPushMatrix();
    ofTranslate(model.getPosition().x-300, model.getPosition().y, 0);
    ofRotateDeg(-mouseX, 0, 1, 0);
    ofTranslate(-model.getPosition().x, -model.getPosition().y, 0);

    ofxAssimpMeshHelper & meshHelper = model.getMeshHelper(0);

    ofMultMatrix(model.getModelMatrix());
    ofMultMatrix(meshHelper.matrix);

    ofMaterial & material = meshHelper.material;
    
    
    
    ofPopMatrix();
    ofDisableDepthTest();
    light.disable();
    ofDisableLighting();
    ofDisableSeparateSpecularLight();
    
    if(bHelpText){
    ofSetColor(255, 255, 255 );
    stringstream ss;
    ss << "FPS: " << ofToString(ofGetFrameRate(),0) <<endl<<endl;
    ss <<"(keys 1-4): load heavier snow"<<endl;
    ss <<"(LEFT MOUSE BUTTON DRAG in y-axis): control animation."<<endl;
    ss <<"(h): toggle help."<<endl;
    ofDrawBitmapString(ss.str().c_str(), 20, 20);

    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    glm::vec3 modelPosition(ofGetWidth() * 0.5, (float)ofGetHeight() * 0.75, 0);
    switch (key) {
        case '1': {
            int numBalls = 90;
            
            // fill our vector
            for (int i = 0; i < numBalls; i++) {        // loop 30 times
                
                Ball tempBall;                    // create a temporary ball
                balls.push_back(tempBall);        // copy the temporary ball into the balls vector
                // (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
            }
            // update each ball in our vector
            for (int i = 0; i < balls.size(); i++) {    // one way to loop through a whole vector
                
                balls[i].update();    // we can access an individual ball by its "index" number in the vector
                // e.g. balls[0] is the first ball in the vector, balls[1] is the second ball, etc.
                // (note that vectors always start at 0, not 1!!)
            }
            break;
        }
        case '2':{
            float numBalls=100;
            
            // fill our vector
            for (int i = 0; i < numBalls; i++) {        // loop 30 times
                
                Ball tempBall;                    // create a temporary ball
                balls.push_back(tempBall);        // copy the temporary ball into the balls vector
                // (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
            }
            // update each ball in our vector
            for (int i = 0; i < balls.size(); i++) {    // one way to loop through a whole vector
                
                balls[i].update();    // we can access an individual ball by its "index" number in the vector
                // e.g. balls[0] is the first ball in the vector, balls[1] is the second ball, etc.
                // (note that vectors always start at 0, not 1!!)
            }
            break;
        }
        case '3':{
            float numBalls=110;
            
            // fill our vector
            for (int i = 0; i < numBalls; i++) {        // loop 30 times
                
                Ball tempBall;                    // create a temporary ball
                balls.push_back(tempBall);        // copy the temporary ball into the balls vector
                // (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
            }
            // update each ball in our vector
            for (int i = 0; i < balls.size(); i++) {    // one way to loop through a whole vector
                
                balls[i].update();    // we can access an individual ball by its "index" number in the vector
                // e.g. balls[0] is the first ball in the vector, balls[1] is the second ball, etc.
                // (note that vectors always start at 0, not 1!!)
            }
            break;
        }
        case '4':{
            float numBalls=120;
            
            // fill our vector
            for (int i = 0; i < numBalls; i++) {        // loop 30 times
                
                Ball tempBall;                    // create a temporary ball
                balls.push_back(tempBall);        // copy the temporary ball into the balls vector
                // (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
            }
            // update each ball in our vector
            for (int i = 0; i < balls.size(); i++) {    // one way to loop through a whole vector
                
                balls[i].update();    // we can access an individual ball by its "index" number in the vector
                // e.g. balls[0] is the first ball in the vector, balls[1] is the second ball, etc.
                // (note that vectors always start at 0, not 1!!)
            }
            break;
        }
    }
       

	mesh = model.getMesh(0);

    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();
    if(!bAnimate) {
        model.setPausedForAllAnimations(true);
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    // scrub through aninations manually.
	animationPosition = y / (float)ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // pause all animations, so we can scrub through them manually.
    model.setPausedForAllAnimations(true);
	animationPosition = y / (float)ofGetHeight();
    bAnimateMouse = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    // unpause animations when finished scrubbing.
    if(bAnimate) {
        model.setPausedForAllAnimations(false);
    }
    bAnimateMouse = false;
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

