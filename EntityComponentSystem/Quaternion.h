#pragma once
struct Quaternion {
	float x;
	float y;
	float z;
	float w;
	Quaternion() : x(0), y(0), z(0), w(0) {}
	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};