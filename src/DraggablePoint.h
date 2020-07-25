#ifndef DraggablePoint_H
#define DraggablePoint_H

#include "ofMain.h"

class DraggablePoint
{
public:
	DraggablePoint();

	void setup(ofVec2f _pos, float _sz);
	void setup(float _posX, float _posY, float _sz);
	void draw(bool _actualDraw);
	void draw(ofVec2f _pos);
	void draw(float _posX, float _posY);
	void setPos(ofVec2f _pos);
	void setSz(float _sz);

	// design
	float		x, y;
	ofVec2f		pos;

	// state
	bool dragged, hovered, released;
	
private:
	// design
	float		sz;
	
	// states
	ofVec2f		diffDrag;
	bool        draggedPrev, mousePressedPrev;
};

#endif // DraggablePoint_H
