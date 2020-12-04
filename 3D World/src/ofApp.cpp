#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	/* define a triangle mesh
	 
			0--1
			| /
			|/
			2
	 */
	
	
	
	
	
	// sphere
	
	sphere = ofSpherePrimitive(300, 250);	// radius, resolution
    icoSphere = ofSpherePrimitive(50, 50);
    Sphere = ofSpherePrimitive(320, 50);
	sphere.setPosition(0, -500, 0);
    icoSphere.setPosition(300, 0, 0);
    Sphere.setPosition(300,0,0);
    
    //circle
    ofVec3f pt0 = ofVec3f(0, 0, 0);
    ofVec3f pt1 = ofVec3f(10, 0, 0);
    ofVec3f pt2 = ofVec3f(0, -10, 0);
    
    // circle is an ofMesh which can make triangle geometry:
    
    circle.addVertex(pt0);
    circle.addColor(ofColor::orange);
    
    circle.addVertex(pt2);
    circle.addColor(ofColor::white);
    
    circle.addVertex(pt1);
    circle.addColor(ofColor::darkorange);
    
    // add 3 vertex indices in a row to connect the triangle:
    
    circle.addIndex(0);
    circle.addIndex(1);
    circle.addIndex(2);
    
	// box / plane
	
	box = ofBoxPrimitive(100, 100, 100);	// width, height, depth
    plane = ofPlanePrimitive(300,100,200,200); //width, height,int columns, int rows,
	box.setPosition(0, 300, 0);
    plane.setPosition(0,300,0);
	
	
	// setup lights
	
	ofSetSmoothLighting(true);		// nicer lighting rendering

	
	// setup point light
	
	light.setPointLight();
	
	light.setPosition(0, 0, 200);
	light.setDiffuseColor( ofColor::blue );

	light.setAttenuation(.5);	// adjust the light throw
	
	
	// setup spot light
	
	spotlight.setSpotlight();
	
	spotlight.setPosition(300, 0, 0);
	spotlight.lookAt(sphere);
	spotlight.setDiffuseColor( ofColor::yellow );
	light.setSpecularColor( ofColor::fuchsia );
    
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	float time = ofGetElapsedTimef();

	
	// animate the point light to oscillate in Z direction
	
	ofVec3f pointPos = light.getPosition();
	pointPos.z = sin( time ) * 300.;
	light.setPosition( pointPos );
	
    cam.begin();
    ofEnableDepthTest();
    
    // draw background sphere, in wireframe
    
    ofSetColor(ofColor::purple);
    Sphere.drawWireframe();
    
    circle.draw();
    
    ofDisableDepthTest();
    cam.end();
    
	// animate spotlight to orbit around sphere
	
	ofVec3f spotPos = sphere.getPosition();
	spotPos.x += cos( time ) * sphere.getRadius() * 1.5;
	spotPos.y += sin( time ) * sphere.getRadius() * 1.5;
	spotPos.z += sin( time * 2. ) * sphere.getRadius() * 1.5;
	
	spotlight.setPosition(spotPos);
    icoSphere.setPosition(spotPos);
	
	spotlight.lookAt(sphere);	// point at sphere center
	
	
	// rotate our box 1 degree in a noisy direction
	
	box.rotate(1, ofNoise(time), ofNoise(time+1000), ofNoise(time+2000));
    plane.rotate(1, ofNoise(time), ofNoise(time+1000), ofNoise(time+2000));
    Sphere.rotateDeg( .05, glm::vec3(1,-1,0) );
    if (ofGetMousePressed()){
        circle.clear();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	cam.begin();		// begin viewing our scene from the camera
	
	ofEnableLighting();		// turn on lighting globally
	ofEnableDepthTest();	// render objects in order of depth
	
	light.enable();			// enable our lights
	spotlight.enable();
	
	
	//image.bind();					// map image to triangle mesh
	triangle.disableColors();		// turn off mesh color tint
	//triangle.draw();
	//image.unbind();
	
	sphere.draw();
	box.draw();
    plane.draw();
    icoSphere.draw();

	
	light.disable();			// disable our scene lights
	spotlight.disable();
	
	ofDisableLighting();		// disable global lighting
	
	
	//ofDrawAxis(100);			// draws our scene origin axes

	//spotlight.draw();			// visualize our lights
	//light.draw();
	
	// visualize the 3d wireframes
	ofSetColor(255, 100);		// add some alpha
	sphere.drawWireframe();		// visualize the sphere mesh
	box.drawWireframe();
    plane.drawWireframe();
    icoSphere.drawWireframe();
	ofSetColor(255);
	
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
