#include "box.h"

Box::Box() {
	SetWidth(DEFAULT_DIMENSION);
	SetHeight(DEFAULT_DIMENSION);
	SetDepth(DEFAULT_DIMENSION);
}

Box::Box(int newHeight, int newWidth, int newDepth) {
	SetWidth(newWidth);
	SetHeight(newHeight);
	SetDepth(newDepth);
}

int Box::GetWidth() {
	return width;
}

void Box::SetWidth(int newWidth) {
	if (newWidth>0) {
		width=newWidth;
	} else {
		width=DEFAULT_DIMENSION;
	}
}

int Box::GetHeight() {
	return height;
}

void Box::SetHeight(int newHeight) {
	if (newHeight>0) {
		height=newHeight;
	} else {
		height=DEFAULT_DIMENSION;
	}
}

int Box::GetDepth() {
	return depth;
}

void Box::SetDepth(int newDepth) {
	if (newDepth>0) {
		depth=newDepth;
	} else {
		depth=DEFAULT_DIMENSION;
	}
}

int Box::Volume() {
	return GetWidth() * GetHeight() * GetDepth();
}
