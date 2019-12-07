#include "ofMain.h"
#include "ofApp.h"

using namespace std;

//========================================================================
int main(){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    ofSetFrameRate(60.0f);

	ofRunApp(new ofApp());
	return 0;
}
