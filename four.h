#pragma once
struct FOUR
{
	int pc[8][8];;
};
void initialize(FOUR gaming);
void mainmenu(int bas[8][8], FOUR gaming);
void printmap(int bas[8][8], FOUR gaming);
int turn(FOUR gaming);
void printbackground(int bas[8][8], int i, int j);
void printchequer(FOUR gaming, int i, int j);
int battle(int bas[8][8], FOUR gaming);
int legit(int x, int y, FOUR gaming);
int victory(FOUR gaming, int x, int y, int mark);
int aboutauthor();
int exit();
int AIScript(FOUR gaming, int x, int y, int AIpost[2]);
int vicsimulator(FOUR gaming, int x, int y, int mark);
int score(FOUR gaming, int x, int y);
int vsAI(int bas[8][8], FOUR gaming);
int vsAIvictory(FOUR gaming, int x, int y, int mark);