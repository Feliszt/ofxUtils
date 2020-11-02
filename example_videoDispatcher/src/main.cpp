#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main() {
	ofGLFWWindowSettings settings;

	// main window
	settings.setGLVersion(4, 5);
	settings.decorated = false;
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	// create and run app
	ofApp *app = new ofApp();

	// run the app
	shared_ptr<ofApp> mainApp(app);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}
