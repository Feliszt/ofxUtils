#ifndef DraggablePoint_H
#define DraggablePoint_H

#include "ofMain.h"

class DraggablePoint
{
public:
	DraggablePoint();

	void setup(ofVec2f _pos, float _sz);
	void setup(float _posX, float _posY, float _sz);
	void draw();
	void draw(ofVec2f _pos);
	void draw(float _posX, float _posY);
	void setPos(ofVec2f _pos);

	// design
	float		x, y;
	ofVec2f		pos;

	// state
	bool dragged;
	
private:
	// design
	float		sz;
	
	// states
	ofVec2f		diffDrag;
	bool        hovered, draggedPrev, mousePressedPrev;
};

#endif // DraggablePoint_H
