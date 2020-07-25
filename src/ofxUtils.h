/*==============================================================================

==============================================================================*/
#pragma once

#include "DraggablePoint.h"
#include "Rope.h"
#include "Particle.h"
#include "Bubble.h"
#include "Drop.h"
#include "Point.h"
#include "Thread.h"
#include "ThreadedScreenSave.h"
#include "Walker.h"

// methods
ofVec2f		bezier(float t_, vector<ofVec2f> cp_);
int			factorial(int n_);
float		bernstein(float t_, int ind_, int deg_);
float		angleBetweenPoints(ofVec2f _p1, ofVec2f _p2);