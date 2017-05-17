#ifndef ___Class_Stone
#define ___Class_Stone

#include <Windows.h>

enum Color
{
	Green,//盤の色
	White,
	Black
};

class Stone
{
private:
	HANDLE hStdout;
	WORD wAttributes;
	CONSOLE_SCREEN_BUFFER_INFO csbi;//構造体です

public:
	Color myColor;

	void Initialize(int colorNumber);
	void Update();
	void Draw();
};

#endif