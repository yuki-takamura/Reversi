#ifndef ___Class_Stone
#define ___Class_Stone

#include "DrawObject.h"
#include "ConstantMacro.h"

enum Color
{
	GREEN,//盤の色(空として扱う)
	BLACK,
	WHITE
};

class Stone : public DrawObject
{
public:
	Color myColor;

	void initialize(int colorNumber);
	void update();
	void draw();
};

#endif