#pragma once

//file paths
extern const char* DOODLE_RIGHT_PATH;
extern const char* DOODLE_LEFT_PATH;
extern const char* DOODLE_TOP_PATH;
extern const char* DOODLE_TRUNK_PATH;
extern const char* PLATFORM_BASIC_PATH;
extern const char* BACKGROUND_PATH;
extern const char* MONSTER_PATH;
extern const char* PROJECTILE_PATH;
extern const char* SPRING_BOOTS_PATH;
extern const char* SPRING_BOOTS_LEFT_PATH;
extern const char* JUMP_PAD_PATH;
extern const char* SCORE_ZERO;
extern const char* SCORE_ONE;
extern const char* SCORE_TWO;
extern const char* SCORE_THREE;
extern const char* SCORE_FOUR;
extern const char* SCORE_FIVE;
extern const char* SCORE_SIX;
extern const char* SCORE_SEVEN;
extern const char* SCORE_EIGHT;
extern const char* SCORE_NINE;

//window constants
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

//doodler
enum DoodleStatus { Right, Left, Top, Trunk };
extern const int DOODLER_WIDTH;
extern const int DOODLER_HEIGHT;
extern float DOODLE_VY;
extern float DOODLE_VX;
extern float G;

//monster
extern const int MONSTER_WIDTH;
extern const int MONSTER_HEIGHT;
extern const int PROJECTILE_WIDTH;
extern const int PROJECTILE_HEIGHT;

//platform
extern const int PLATFORM_WIDTH;
extern const int PLATFORM_HEIGHT;
extern const int PLATFORM_COLLISION_DISTANCE_WIDTH;
extern const int PLATFORM_COLLISION_DISTANCE_HEIGHT;

//Boosters
extern const int JUMP_PAD_WIDTH;
extern const int JUMP_PAD_HEIGHT;
extern const int SPRING_BOOTS_WIDTH;
extern const int SPRING_BOOTS_HEIGHT;

enum SpringBootsStatus { RightBoots = 7, LeftBoots = 8 };