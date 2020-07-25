#include "ThreadedScreenSave.h"

void ThreadedScreenSave::threadedFunction() {
	ofSaveFrame();
}
