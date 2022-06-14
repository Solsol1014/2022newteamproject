#include "gameplay.h"

void moving(int map[][34], int* x, int* y)
{
    int ch;

    if (_kbhit())
    {
        ch = _getch();

        if (ch == 224)
        {
            ch = _getch();
            switch (ch)
            {
            case 72:
                if (map[(*x) - MAPLOCATIONX][(*y) - 1 - MAPLOCATIONY] == 0)
                {
                    gotoxy(*x, *y);
                    printf("  ");
                    (*y)--;
                    gotoxy(*x, *y);
                    printf("¡ß\b\b");
                    //printf("¡ß\b");
                }
                break;

            case 80:
                if (map[(*x) - MAPLOCATIONX][(*y) + 1 - MAPLOCATIONY] == 0)
                {
                    gotoxy(*x, *y);
                    printf("  ");
                    (*y)++;
                    gotoxy(*x, *y);
                    printf("¡ß\b\b");
                    //printf("¡ß\b");
                }
                break;

            case 75:
                if (map[(*x) - 2 - MAPLOCATIONX][(*y) - MAPLOCATIONY] == 0)
                {
                    gotoxy(*x, *y);
                    printf("  ");
                    (*x)--;
                    (*x)--;
                    gotoxy(*x, *y);
                    printf("¡ß\b\b");
                    //printf("¡ß\b");
                }
                break;

            case 77:
                if (map[(*x) + 2 - MAPLOCATIONX][(*y) - MAPLOCATIONY] == 0)
                {
                    gotoxy(*x, *y);
                    printf("  ");
                    (*x)++;
                    (*x)++;
                    gotoxy(*x, *y);
                    printf("¡ß\b\b");
                    //printf("¡ß\b"); 
                }
                break;
            }
        }
    }
}

void jaemin(int map[][34], int item[][30][2], struct jcoord* jm, int difficulty)
{
    int ch, k;
    static int i = 1, j = 1;

    if (difficulty == 9)
    {
        for (k = 0; k < difficulty - 1; k++)
        {
            if (jm[k].y - MAPLOCATIONY == 4 * 8 - 1)
                i = 0;
            else if (jm[k].y - MAPLOCATIONY == 2)
                i = 1;

            if (jm[k].x - MAPLOCATIONX == 4 * 16 - 2)
                j = 0;
            else if (jm[k].x - MAPLOCATIONX == 4)
                j = 1;

            while (1)
            {
                ch = rand() % 6;

                if (ch == 0)
                {
                    if (map[jm[k].x - MAPLOCATIONX][jm[k].y - 1 - MAPLOCATIONY] == 0 && item[jm[k].x - MAPLOCATIONX - 4][jm[k].y - 1 - MAPLOCATIONY - 2][0] == 0)
                    {
                        gotoxy(jm[k].x, jm[k].y);
                        printf("  ");
                        jm[k].y--;
                        gotoxy(jm[k].x, jm[k].y);
                        printf("¡Ü\b\b");
                        break;
                    }
                    else
                        continue;
                }
                else if (ch == 1)
                {
                    if (map[jm[k].x - MAPLOCATIONX][jm[k].y + 1 - MAPLOCATIONY] == 0 && item[jm[k].x - MAPLOCATIONX - 4][jm[k].y + 1 - MAPLOCATIONY - 2][0] == 0)
                    {
                        gotoxy(jm[k].x, jm[k].y);
                        printf("  ");
                        jm[k].y++;
                        gotoxy(jm[k].x, jm[k].y);
                        printf("¡Ü\b\b");
                        break;
                    }
                    else
                        continue;
                }
                else if (ch == 2)
                {
                    if (map[jm[k].x - 2 - MAPLOCATIONX][jm[k].y - MAPLOCATIONY] == 0 && item[jm[k].x - 2 - MAPLOCATIONX - 4][jm[k].y - MAPLOCATIONY - 2][0] == 0)
                    {
                        gotoxy(jm[k].x, jm[k].y);
                        printf("  ");
                        jm[k].x--;
                        jm[k].x--;
                        gotoxy(jm[k].x, jm[k].y);
                        printf("¡Ü\b\b");
                        break;
                    }
                    else
                        continue;
                }
                else if (ch == 3)
                {
                    if (map[jm[k].x + 2 - MAPLOCATIONX][jm[k].y - MAPLOCATIONY] == 0 && item[jm[k].x + 2 - MAPLOCATIONX - 4][jm[k].y - MAPLOCATIONY - 2][0] == 0)
                    {
                        gotoxy(jm[k].x, jm[k].y);
                        printf("  ");
                        jm[k].x++;
                        jm[k].x++;
                        gotoxy(jm[k].x, jm[k].y);
                        printf("¡Ü\b\b");
                        break;
                    }
                    else
                        continue;
                }
                else if (ch == 4)
                {
                    if (i == 0)
                    {
                        if (map[jm[k].x - MAPLOCATIONX][jm[k].y - 1 - MAPLOCATIONY] == 0 && item[jm[k].x - MAPLOCATIONX - 4][jm[k].y - 1 - MAPLOCATIONY - 2][0] == 0)
                        {
                            gotoxy(jm[k].x, jm[k].y);
                            printf("  ");
                            jm[k].y--;
                            gotoxy(jm[k].x, jm[k].y);
                            printf("¡Ü\b\b");
                            break;
                        }
                        else
                            continue;
                    }
                    else if (i == 1)
                    {
                        if (map[jm[k].x - MAPLOCATIONX][jm[k].y + 1 - MAPLOCATIONY] == 0 && item[jm[k].x - MAPLOCATIONX - 4][jm[k].y + 1 - MAPLOCATIONY - 2][0] == 0)
                        {
                            gotoxy(jm[k].x, jm[k].y);
                            printf("  ");
                            jm[k].y++;
                            gotoxy(jm[k].x, jm[k].y);
                            printf("¡Ü\b\b");
                            break;
                        }
                        else
                            continue;
                    }
                }
                else if (ch == 5)
                {
                    if (j == 0)
                    {
                        if (map[jm[k].x - 2 - MAPLOCATIONX][jm[k].y - MAPLOCATIONY] == 0 && item[jm[k].x - 2 - MAPLOCATIONX - 4][jm[k].y - MAPLOCATIONY - 2][0] == 0)
                        {
                            gotoxy(jm[k].x, jm[k].y);
                            printf("  ");
                            jm[k].x--;
                            jm[k].x--;
                            gotoxy(jm[k].x, jm[k].y);
                            printf("¡Ü\b\b");
                            break;
                        }
                        else
                            continue;
                    }
                    else if (j == 1)
                    {
                        if (map[jm[k].x + 2 - MAPLOCATIONX][jm[k].y - MAPLOCATIONY] == 0 && item[jm[k].x + 2 - MAPLOCATIONX - 4][jm[k].y - MAPLOCATIONY - 2][0] == 0)
                        {
                            gotoxy(jm[k].x, jm[k].y);
                            printf("  ");
                            jm[k].x++;
                            jm[k].x++;
                            gotoxy(jm[k].x, jm[k].y);
                            printf("¡Ü\b\b");
                            break;
                        }
                        else
                            continue;
                    }
                }
            }
        }
    }
    else
    {
        for (k = 0; k < difficulty - 1; k++)
        {
            if (jm[k].y - MAPLOCATIONY == difficulty * 8 - 1)
                i = 0;
            else if (jm[k].y - MAPLOCATIONY == 2)
                i = 1;

            if (jm[k].x - MAPLOCATIONX == difficulty * 16 - 2)
                j = 0;
            else if (jm[k].x - MAPLOCATIONX == 4)
                j = 1;

            while (1)
            {
                ch = rand() % 6;

                if (ch == 0)
                {
                    if (map[jm[k].x - MAPLOCATIONX][jm[k].y - 1 - MAPLOCATIONY] == 0 && item[jm[k].x - MAPLOCATIONX - 4][jm[k].y - 1 - MAPLOCATIONY - 2][0] == 0)
                    {
                        gotoxy(jm[k].x, jm[k].y);
                        printf("  ");
                        jm[k].y--;
                        gotoxy(jm[k].x, jm[k].y);
                        printf("¡Ü\b\b");
                        break;
                    }
                    else
                        continue;
                }
                else if (ch == 1)
                {
                    if (map[jm[k].x - MAPLOCATIONX][jm[k].y + 1 - MAPLOCATIONY] == 0 && item[jm[k].x - MAPLOCATIONX - 4][jm[k].y + 1 - MAPLOCATIONY - 2][0] == 0)
                    {
                        gotoxy(jm[k].x, jm[k].y);
                        printf("  ");
                        jm[k].y++;
                        gotoxy(jm[k].x, jm[k].y);
                        printf("¡Ü\b\b");
                        break;
                    }
                    else
                        continue;
                }
                else if (ch == 2)
                {
                    if (map[jm[k].x - 2 - MAPLOCATIONX][jm[k].y - MAPLOCATIONY] == 0 && item[jm[k].x - 2 - MAPLOCATIONX - 4][jm[k].y - MAPLOCATIONY - 2][0] == 0)
                    {
                        gotoxy(jm[k].x, jm[k].y);
                        printf("  ");
                        jm[k].x--;
                        jm[k].x--;
                        gotoxy(jm[k].x, jm[k].y);
                        printf("¡Ü\b\b");
                        break;
                    }
                    else
                        continue;
                }
                else if (ch == 3)
                {
                    if (map[jm[k].x + 2 - MAPLOCATIONX][jm[k].y - MAPLOCATIONY] == 0 && item[jm[k].x + 2 - MAPLOCATIONX - 4][jm[k].y - MAPLOCATIONY - 2][0] == 0)
                    {
                        gotoxy(jm[k].x, jm[k].y);
                        printf("  ");
                        jm[k].x++;
                        jm[k].x++;
                        gotoxy(jm[k].x, jm[k].y);
                        printf("¡Ü\b\b");
                        break;
                    }
                    else
                        continue;
                }
                else if (ch == 4)
                {
                    if (i == 0)
                    {
                        if (map[jm[k].x - MAPLOCATIONX][jm[k].y - 1 - MAPLOCATIONY] == 0 && item[jm[k].x - MAPLOCATIONX - 4][jm[k].y - 1 - MAPLOCATIONY - 2][0] == 0)
                        {
                            gotoxy(jm[k].x, jm[k].y);
                            printf("  ");
                            jm[k].y--;
                            gotoxy(jm[k].x, jm[k].y);
                            printf("¡Ü\b\b");
                            break;
                        }
                        else
                            continue;
                    }
                    else if (i == 1)
                    {
                        if (map[jm[k].x - MAPLOCATIONX][jm[k].y + 1 - MAPLOCATIONY] == 0 && item[jm[k].x - MAPLOCATIONX - 4][jm[k].y + 1 - MAPLOCATIONY - 2][0] == 0)
                        {
                            gotoxy(jm[k].x, jm[k].y);
                            printf("  ");
                            jm[k].y++;
                            gotoxy(jm[k].x, jm[k].y);
                            printf("¡Ü\b\b");
                            break;
                        }
                        else
                            continue;
                    }
                }
                else if (ch == 5)
                {
                    if (j == 0)
                    {
                        if (map[jm[k].x - 2 - MAPLOCATIONX][jm[k].y - MAPLOCATIONY] == 0 && item[jm[k].x - 2 - MAPLOCATIONX - 4][jm[k].y - MAPLOCATIONY - 2][0] == 0)
                        {
                            gotoxy(jm[k].x, jm[k].y);
                            printf("  ");
                            jm[k].x--;
                            jm[k].x--;
                            gotoxy(jm[k].x, jm[k].y);
                            printf("¡Ü\b\b");
                            break;
                        }
                        else
                            continue;
                    }
                    else if (j == 1)
                    {
                        if (map[jm[k].x + 2 - MAPLOCATIONX][jm[k].y - MAPLOCATIONY] == 0 && item[jm[k].x + 2 - MAPLOCATIONX - 4][jm[k].y - MAPLOCATIONY - 2][0] == 0)
                        {
                            gotoxy(jm[k].x, jm[k].y);
                            printf("  ");
                            jm[k].x++;
                            jm[k].x++;
                            gotoxy(jm[k].x, jm[k].y);
                            printf("¡Ü\b\b");
                            break;
                        }
                        else
                            continue;
                    }
                }
            }
        }
    }
}