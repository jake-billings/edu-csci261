#pragma once

class Box {
private:
	int width;
	int height;
	int depth;

public:
	static const int DEFAULT_DIMENSION = 1;

	Box();
	Box(int newWidth, int newHeight, int newDepth);

	int GetWidth();
	int GetHeight();
	int GetDepth();

	void SetWidth(int newWidth);
	void SetHeight(int newHeight);
	void SetDepth(int newDepth);

	int Volume();
};
