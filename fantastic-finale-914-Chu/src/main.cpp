#include "ofMain.h"
#include "ofApp.h"
#include <chrono>
#include <Windows.h>
#include <mmsystem.h>
#include <SFML/Graphics.hpp>

using namespace std;

//========================================================================
int main(){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	//// this kicks off the running of my app
	//// can be OF_WINDOW or OF_FULLSCREEN
	//// pass in width and height too:
	ofRunApp(new ofApp());
	
	//for (int i = 0; i < 10; i++) {
 //           PlaySound(TEXT("Bass-Drum-1.wav"), NULL, SND_FILENAME);
 //       }

	//sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
 //   sf::CircleShape shape(100.f);
 //   shape.setFillColor(sf::Color::Green);

 //    while (window.isOpen()) {
	//	sf::Event event;
 //       while (window.pollEvent(event)) {
	//		if (event.type == sf::Event::Closed) window.close();
 //       }

 //       window.clear();
	//	window.draw(shape);
 //       window.display();
 //    }

	return 0;
}
