#include "Score.h"

void Score::initializeScoreSprites() {
	scoreSprites.push_back(createSprite(SCORE_ZERO));
	scoreSprites.push_back(createSprite(SCORE_ONE));
	scoreSprites.push_back(createSprite(SCORE_TWO));
	scoreSprites.push_back(createSprite(SCORE_THREE));
	scoreSprites.push_back(createSprite(SCORE_FOUR));
	scoreSprites.push_back(createSprite(SCORE_FIVE));
	scoreSprites.push_back(createSprite(SCORE_SIX));
	scoreSprites.push_back(createSprite(SCORE_SEVEN));
	scoreSprites.push_back(createSprite(SCORE_EIGHT));
	scoreSprites.push_back(createSprite(SCORE_NINE));

	setSpriteSize(scoreSprites[0], 25, 30);
	setSpriteSize(scoreSprites[1], 15, 31);
	setSpriteSize(scoreSprites[2], 25, 31);
	setSpriteSize(scoreSprites[3], 25, 31);
	setSpriteSize(scoreSprites[4], 22, 31);
	setSpriteSize(scoreSprites[5], 25, 31);
	setSpriteSize(scoreSprites[6], 25, 31);
	setSpriteSize(scoreSprites[7], 25, 31);
	setSpriteSize(scoreSprites[8], 25, 31);
	setSpriteSize(scoreSprites[9], 23, 31);

}

void Score::drawScore() {
	int hundredThousands = (scorePoints / 100000) % 10;
	int tenThousands = (scorePoints / 10000) % 10;
	int thousands = (scorePoints / 1000) % 10;
	int hundreds = (scorePoints / 100) % 10;
	int tens = (scorePoints / 10) % 10;
	int ones = scorePoints % 10;

	int xPositionHundredThousand = WINDOW_WIDTH - 225;
	int xPositionTenThousand = WINDOW_WIDTH - 200;
	int xPositionThousand = WINDOW_WIDTH - 175;
	int xPositionHundred = WINDOW_WIDTH - 150;
	int xPositionTen = WINDOW_WIDTH - 125;
	int xPositionOne = WINDOW_WIDTH - 100;
	int yPosition = 50;


	drawDigitSprite(hundredThousands, xPositionHundredThousand, yPosition);
	drawDigitSprite(tenThousands, xPositionTenThousand, yPosition);
	drawDigitSprite(thousands, xPositionThousand, yPosition);
	drawDigitSprite(hundreds, xPositionHundred, yPosition);
	drawDigitSprite(tens, xPositionTen, yPosition);
	drawDigitSprite(ones, xPositionOne, yPosition);

}

void Score::drawDigitSprite(int& digit, int& x, int& y) {

	if (digit >= 0 && digit < scoreSprites.size()) {
		drawSprite(scoreSprites[digit], x, y);
	}
}

int Score::getScorePoint() {
	return scorePoints;
}

void Score::setScorePoints(int score) {
	scorePoints += score;
}

bool Score::scoreRemainder(int scorePoint) {
	return (scorePoints % scorePoint == 0);
}
