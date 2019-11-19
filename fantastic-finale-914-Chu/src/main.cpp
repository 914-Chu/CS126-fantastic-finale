#include "ofMain.h"
#include "ofApp.h"
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

//========================================================================
int main(){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	//// this kicks off the running of my app
	//// can be OF_WINDOW or OF_FULLSCREEN
	//// pass in width and height too:
	ofRunApp(new ofApp());
	
	/*for (int i = 0; i < 10; i++) {
            PlaySound(TEXT("Bass-Drum-1.wav"), NULL, SND_FILENAME);
        }*/


	return 0;
}
