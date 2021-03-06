#include <iostream>
#include "PlayerObject.h"

using namespace std;

PlayerObject::PlayerObject(bool isTurnFirst)
{
	place.numberOfH = EMPTY_NUM;
	place.alphabetOfV = EMPTY_NUM;
	myColor = isTurnFirst ? Color::BLACK : Color::WHITE;
}

void PlayerObject :: update(Stone stone[VERTICAL][HORIZONTAL])
{
	return;
}

void PlayerObject::putStone(Stone stone[VERTICAL][HORIZONTAL])
{
	bool canPut = false;

	for (int i = 0; i < VECTOR_NUM ; i++)
	{
		canFlip[i] = false;
		if(checkCanPut(place.numberOfH, place.alphabetOfV,i,stone))
			canPut = true;
	}

	if (canPut)
	{
		for (int i = 0; i < VECTOR_NUM; i++)
		{
			if(canFlip[i])
				flip(place.numberOfH, place.alphabetOfV, i, stone);
		}
	
		if (stone[place.alphabetOfV][place.numberOfH].myColor == Color::GREEN)
		{
			stone[place.alphabetOfV][place.numberOfH].myColor = myColor;
			isPutStone = true;
		}
		else
		{
			if(isPlayer)
				cout << "そこにはおけません" << endl;
		}
	}
	else
	{
		if (isPlayer)
			cout << "そこにはおけません" << endl;
	}
}

bool PlayerObject :: checkCanPut(int x, int y, int vec, Stone stone[VERTICAL][HORIZONTAL])
{
	///<summary>
	///隣に相手の石があるか
	///</summary>
	bool hasEnemyColor = false;

	while(true)
	{
		x += VECTOR_HORIZONTAL[vec];
		y += VECTOR_VERTICAL[vec];

		//盤の範囲内にあるか
		if (x < 0 || x > HORIZONTAL - 1
		 || y < 0 || y > VERTICAL - 1)
			return false;

		//隣に石があるか
		if (stone[y][x].myColor == Color::GREEN)
		{
			return false;
		}
		
		if (stone[y][x].myColor != myColor)
		{
			hasEnemyColor = true;
			continue;
		}
			
		if (hasEnemyColor)
		{
			canFlip[vec] = true;
			break;
		}
		else
			return false;
	}
	return true;
}

void PlayerObject::flip(int x, int y, int vec, Stone stone[VERTICAL][HORIZONTAL])
{
	while (true)
	{
		x += VECTOR_HORIZONTAL[vec];
		y += VECTOR_VERTICAL[vec];

		if (stone[y][x].myColor != myColor)
		{
			stone[y][x].myColor = myColor;
			continue;
		}
		else
		{
			break;
		}
	}
}

bool PlayerObject::checkEnd(Stone stone[VERTICAL][HORIZONTAL])
{
	bool canPut = false;

	for (int i = 0; i < VERTICAL; i++)
	{
		for (int j = 0; j < HORIZONTAL;j++)
		{
			for (int k = 0; k < VECTOR_NUM; k++)
			{
				if (checkCanPut(j, i, k, stone))
					canPut = true;
			}
		}
	}

	return canPut;
}