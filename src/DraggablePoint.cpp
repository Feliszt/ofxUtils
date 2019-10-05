#include "DraggablePoint.h"

DraggablePoint::DraggablePoint()
{
}

void DraggablePoint::setup(ofVec2f _pos, float _sz) {
	setup(_pos.x, _pos.y, _sz);
}

void DraggablePoint::setup(float _posX, float _posY, float _sz) {
	x = _posX;
	y = _posY;
	sz = _sz;
}

void DraggablePoint::draw() {
	// check if hovered
	hovered = (ofGetMouseX() - x) * (ofGetMouseX() - x) + (ofGetMouseY() - y) * (ofGetMouseY() - y) < sz * sz;

	// check if point is clicked
	if (hovered && ofGetMousePressed() && !mousePressedPrev) {
		dragged = true;
	}

	// this registers when we unclick
	dragged &= ofGetMousePressed();

	// store mouse posString and value when dragging starts
	if (dragged && !draggedPrev) {
		diffDrag = ofVec2f(x, y) - ofVec2f(ofGetMouseX(), ofGetMouseY());
	}

	// move point
	if (dragged) {
		x = ofGetMouseX() + diffDrag.x;
		y = ofGetMouseY() + diffDrag.y;
	}

	// draw point
	float offsetSz = ((hovered || dragged)? 0.2 : 0.0) * sz;
	ofDrawCircle(x, y, sz + offsetSz);

	// update states
	draggedPrev = dragged;
	mousePressedPrev = ofGetMousePressed();
}

ofVec2f DraggablePoint::getPos() {
	return ofVec2f(x, y);
}
