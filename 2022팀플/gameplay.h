#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define WORDSTOPSIZE 6
#define MAPLOCATIONX 25
#define MAPLOCATIONY 8
#define ITEMCOUNT 7

//두칸짜리 애들 다 홀수자리에 출력

void map(int x, int map_array[][34]);
void printmap(int map_array[][34]);
void gotoxy(int x, int y);
void moving(int map[][34], int* x, int* y);
void item_location(int world_item[][30][2], int map_array[][34], int difficulty, int*, int*);
int item_get(int*, int*, int, int world_item[][30][2], int, int, int, int*, int*, int*, int*, int*);
void jaemin(int map[][34], int item[][30][2], struct jcoord*, int);
void deleteflag(int item[][30][2], int);
void timebar(int*, int);
void wordstop(char word[], int);
void start(void);
void respawn(int*, int*, int);
void stop(const char w[], char sword[], int*, int*, int*, int, int map_array[][34]);
void detector(int x, int y, int, int, int);
void printitem(int world_item[][30][2]);
void confuse(int map[][34], int* x, int* y);
void ingameui(int difficulty);
void loading(int map_array[][34], int item[][30][2], int);
void locatejp(int, int, struct jcoord*, int, int map_array[][34], int item[][30][2]);
void timechange(int* timelimit, int);
void changejfrequ(int* jfrequ, int difficulty);
int custom_menu(int*, int*, int*, int*, int*, int*);
int main_inter(int*, int, int, FILE*);;
int dif_menu(int*, int);
void description1(void);
void rankingread(FILE*);

struct jcoord {
	int x;
	int y;
};