#include "ofMain.h"
#include "ofApp.h"
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

//========================================================================
int main(){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    ofSetFrameRate(60.0f);

	//ofWindowSettings settings;
 //   glm::vec2 const &p = glm::vec2(500.0f, 500.0f);
 //   settings.setPosition(p);
 //   settings.setSize(1024, 768);
 //   shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings);
 //   shared_ptr<ofApp> app(new ofApp);
 //   ofRunApp(window, app);
 //   ofRunMainLoop();
	ofRunApp(new ofApp());


	return 0;
}
