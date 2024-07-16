#pragma once
#include <iostream>
#include <vector>
#include "Framework.h"
#include "Const.h"
class Score {
private:
	std::vector<Sprite*> scoreSprites;
	int scorePoints = 0;
public:

	void initializeScoreSprites();

	void drawScore();

	void drawDigitSprite(int& digit, int& x, int& y);

	int getScorePoint();

	void setScorePoints(int score);

	bool scoreRemainder(int scorePoint);
};