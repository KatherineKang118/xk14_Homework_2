#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 320;  // try to grab at this size.
    camHeight = 240;
    // setup webcam
    vid.setup(640,480);
    
    // allocate the fbo memory
    fbo.allocate(640,480,GL_RGBA);
    
    // clear the fbo's pixels (removes junk data):
    //    fbo.begin();
    //    ofClear(0,0,0,0);
    //    fbo.end();
    
    fboTime = ofGetElapsedTimef();
    
    
    blendmode = OF_BLENDMODE_ADD;
    //get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();

    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }

    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);

    videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    videoTexture.allocate(videoInverted);
   
}


//--------------------------------------------------------------
void ofApp::update(){
    //ofBackground(100, 100, 100);
    vidGrabber.update();

    if(vidGrabber.isFrameNew()){
        ofPixels & pixels = vidGrabber.getPixels();
        for(size_t i = 0; i < pixels.size(); i++){
            //invert the color of the pixel
            videoInverted[i] = 255 - pixels[i];
        }
        //load the inverted pixels
        videoTexture.loadData(videoInverted);
    }
    vid.update();
    if (ofGetElapsedTimef() - fboTime >= 5)
    {
        fbo.begin();
        vid.draw(0,0,640,480);
        fbo.end();
        
        fboTime = ofGetElapsedTimef();    // reset timer
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.draw(0,0);    // draw captured webcam frame
    
    
    
    ofEnableBlendMode(blendmode);            // SET TO CUSTOM BLENDMODE
    
    vid.draw(0,0);    // draw current webcam frame on top, with alpha blending
    
    ofSetHexColor(0xa16bca);
    //ofSetColor(255,255,255,500);
    vidGrabber.draw(400, 200);
    vidGrabber.draw(500, 100);
    vidGrabber.draw(300, 350);
    ofSetHexColor(5980);
    vidGrabber.draw(200, 400);
    vidGrabber.draw(400, 600);
    vidGrabber.draw(600, 300);
    ofSetHexColor(1765);
    //float spr=ofRandom(-50,50);
    vidGrabber.draw(800, 500);
    vidGrabber.draw(50, 500);
    vidGrabber.draw(100, 100);
    vidGrabber.draw(800, 150);
    vidGrabber.draw(150, 550);
    //videoTexture.draw(40 + camWidth, 40, camWidth, camHeight);
    ofPixelsRef pixelsRef = vidGrabber.getPixels();
    
    ofSetHexColor(0xffffff);
    //ofSetHexColor(0x000000);
    ofDrawBitmapString("change mode:press 1-5",20,20);
    }

    


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // in fullscreen mode, on a pc at least, the 
    // first time video settings the come up
    // they come up *under* the fullscreen window
    // use alt-tab to navigate to the settings
    // window. we are working on a fix for this...

    // Video settings no longer works in 10.7
    // You'll need to compile with the 10.6 SDK for this
    // For Xcode 4.4 and greater, see this forum post on instructions on installing the SDK
    // http://forum.openframeworks.cc/index.php?topic=10343
    switch (key) {
        case '1':
            blendmode = OF_BLENDMODE_ADD;
            break;
        case '2':
            blendmode = OF_BLENDMODE_SUBTRACT;
            break;
        case '3':
            blendmode = OF_BLENDMODE_MULTIPLY;
            break;
        case '4':
            blendmode = OF_BLENDMODE_SCREEN;
            break;
        case '5':
            blendmode = OF_BLENDMODE_ALPHA;
            // change background video alpha value based on the cursor's x-position
             break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
