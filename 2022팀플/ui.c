#include "gameplay.h"

void timebar(int* i, int difficulty)
{
    gotoxy(difficulty * 16 + 4 + MAPLOCATIONX + 8, (difficulty * 8 + 2) / 2 - 2 + MAPLOCATIONY);
    if ((*i) < 10)
        printf("0%d", *i);
    else
        printf("%d", *i);
    (*i)--;
}

void ingameui(int diffi)
{
    int a, b, difficulty;

    difficulty = diffi;

    if (difficulty == 5)
    {
        difficulty = 4;
        a = difficulty * 16 + 4 + MAPLOCATIONX;
        b = (difficulty * 8 + 2) / 2 - 5 + MAPLOCATIONY;
        gotoxy(a, b);
        printf("┌──────────────┐\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│ TIME:        │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│ LEVEL:       │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("└──────────────┘\n");

        gotoxy(difficulty * 16 + 4 + MAPLOCATIONX + 8, (difficulty * 8 + 2) / 2 + 1 + MAPLOCATIONY);
        printf("EXTREME");

        a = (difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX;
        b = difficulty * 8 + 2 + MAPLOCATIONY;
        gotoxy(a, b);
        printf("┌──────────────────────────────────────────────────────────────┐"); b++; gotoxy(a, b);
        printf("│ STATE:                                                       │"); b++;  gotoxy(a, b);
        printf("│                                                              │"); b++; gotoxy(a, b);
        printf("└──────────────────────────────────────────────────────────────┘\n"); b++; gotoxy(a, b);

        gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
        printf("GAME START");
    }
    else
    {
        a = difficulty * 16 + 4 + MAPLOCATIONX;
        b = (difficulty * 8 + 2) / 2 - 5 + MAPLOCATIONY;
        gotoxy(a, b);
        printf("┌──────────────┐\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│ TIME:        │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│ LEVEL:       │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("│              │\n"); b++; gotoxy(a, b);
        printf("└──────────────┘\n");

        gotoxy(difficulty * 16 + 4 + MAPLOCATIONX + 8, (difficulty * 8 + 2) / 2 + 1 + MAPLOCATIONY);
        if (difficulty == 2)
            printf("EASY");
        else if (difficulty == 3)
            printf("NORMAL");
        else if (difficulty == 4)
            printf("HARD");

        a = (difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX;
        b = difficulty * 8 + 2 + MAPLOCATIONY;
        gotoxy(a, b);
        printf("┌──────────────────────────────────────────────────────────────┐"); b++; gotoxy(a, b);
        printf("│ STATE:                                                       │"); b++;  gotoxy(a, b);
        printf("│                                                              │"); b++; gotoxy(a, b);
        printf("└──────────────────────────────────────────────────────────────┘\n"); b++; gotoxy(a, b);

        gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
        printf("GAME START");
    }
}

void loading(int map_array[][34], int item[][30][2], int difficulty)
{
    int ix, iy; //단계로딩중입니다만 하면 난이도, 맵, 아이템 다 안받아도댐 ㅋㅎㅋㅎㅋㅋㅋㅋ

    system("cls");

    ix = (difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX;
    iy = difficulty * 8 + 2 + MAPLOCATIONY;
    gotoxy(ix, iy);
    printf("┌──────────────────────────────────────────────────────────────┐"); iy++; gotoxy(ix, iy);
    printf("│ STATE:                                                       │"); iy++;  gotoxy(ix, iy);
    printf("│                                                              │"); iy++; gotoxy(ix, iy);
    printf("└──────────────────────────────────────────────────────────────┘\n"); iy++; gotoxy(ix, iy);

    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    printf("단계 로딩중입니다 잠시만 기다려주세요");

    for (ix = 0; ix < 68; ix = ix + 2)
    {
        for (iy = 0; iy < 34; iy++)
        {
            if (map_array[ix][iy] == 1)
            {
                gotoxy(ix + MAPLOCATIONX, iy + MAPLOCATIONY);
                printf("▩");
            }
        }
        Sleep(100);
    }

    for (ix = 0; ix < 60; ix++)
    {
        for (iy = 0; iy < 30; iy++)
        {
            if ((item[ix][iy][0] == 1) || (item[ix][iy][0] == 2)) //보물
            {
                gotoxy(ix + 4 + MAPLOCATIONX, iy + 2 + MAPLOCATIONY);
                printf("▶");
            }

            //if (world_item[x][y][0] == 2) //꽝
            //{
            //    gotoxy(x + 4 + MAPLOCATIONX, y + 2 + MAPLOCATIONY);
            //    printf("■");
            //}
        }
        Sleep(20);
    }

    //for (ix = 18; ix > 0; ix--)
    //{
    //    for (iy = 0; iy < i; iy++)
    //    {
    //        gotoxy(MAPLOCATIONX + iy * 2, MAPLOCATIONY + 5);
    //        printf("▒");
    //    }
    //    printf("  \b\b");
    //    Sleep(200);
    //}
}