#ifndef DraggablePoint_H
#define DraggablePoint_H

//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
#include "ofMain.h"

class DraggablePoint
{
public:
	DraggablePoint();

	void setup(ofVec2f _pos, float _sz);
	void setup(float _posX, float _posY, float _sz);
	void draw();
	ofVec2f getPos();

	// design
	float		x, y;
	
private:
	// design
	float		sz;
	
	// states
	ofVec2f		diffDrag;
	bool        hovered, dragged, draggedPrev, mousePressedPrev;
};

#endif // DraggablePoint_H
