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
	pos.set(x, y);
}

void DraggablePoint::draw(bool _actualDraw) {
	// update ofVec2f
	pos.set(x, y);

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

	// update released
	released = !dragged && draggedPrev;

	// draw point
	float offsetSz = ((hovered || dragged)? 0.2 : 0.0) * sz;
	if (_actualDraw) ofDrawCircle(x, y, sz + offsetSz);

	// update states
	draggedPrev = dragged;
	mousePressedPrev = ofGetMousePressed();
}

void DraggablePoint::draw(ofVec2f _pos) {
	draw(_pos.x, _pos.y);
}

void DraggablePoint::draw(float _posX, float _posY) {
	this->pos = ofVec2f(_posX, _posY);
	ofDrawCircle(_posX, _posY, sz);
}

//-------------------------------------------------------------------
void DraggablePoint::setPos(ofVec2f _pos) {
	pos = _pos;
}

//-------------------------------------------------------------------
void DraggablePoint::setSz(float _sz) {
	sz = _sz;
}
