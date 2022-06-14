#include "gameplay.h"

int main_inter(int* difficulty, int extreme, int clearnum, FILE* ranking)
{
    char x, s[200];
    int i, b;

    while (1)
    {
        i = 10;
        if (extreme > 0)
        {
            printf(" ######            ###                                                   ##   ##                      ##\n");
            printf("  ##  ##            ##                                                   ##   ##                      ##\n");
            printf("  ##  ##   ####     ##  ##   ####    ##  ##    ####    #####             ##   ##  ##  ##   #####     #####    ####    ######\n");
            printf("  #####   ##  ##    ## ##   ##  ##   #######  ##  ##   ##  ##            #######  ##  ##   ##  ##     ##     ##  ##    ##  ##\n");
            printf("  ##      ##  ##    ####    ######   ## # ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ##     ######    ##\n");
            printf("  ##      ##  ##    ## ##   ##       ##   ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ## ##  ##        ##\n");
            printf(" ####      ####     ##  ##   #####   ##   ##   ####    ##  ##            ##   ##   ####    ##  ##      ###    #####   ####\n");
            gotoxy(40, i);
            printf("┌─────────────────────────────┐");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│        1. Game Start        │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│        2. RANKING           │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│        3. Quit              │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("└─────────────────────────────┘");
        }
        else
        {
            printf(" ######            ###                                                   ##   ##                      ##\n");
            printf("  ##  ##            ##                                                   ##   ##                      ##\n");
            printf("  ##  ##   ####     ##  ##   ####    ##  ##    ####    #####             ##   ##  ##  ##   #####     #####    ####    ######\n");
            printf("  #####   ##  ##    ## ##   ##  ##   #######  ##  ##   ##  ##            #######  ##  ##   ##  ##     ##     ##  ##    ##  ##\n");
            printf("  ##      ##  ##    ####    ######   ## # ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ##     ######    ##\n");
            printf("  ##      ##  ##    ## ##   ##       ##   ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ## ##  ##        ##\n");
            printf(" ####      ####     ##  ##   #####   ##   ##   ####    ##  ##            ##   ##   ####    ##  ##      ###    #####   ####\n");
            gotoxy(40, i);
            printf("┌─────────────────────────────┐");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│        1. Game Start        │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│        2. Quit              │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("│                             │");
            i++;
            gotoxy(40, i);
            printf("└─────────────────────────────┘");
        }

        while (1) {
            x = _getch();

            if (extreme > 0)
            {
                if (x == '1')
                {
                    system("cls");
                    if (dif_menu(difficulty, clearnum) == 0)
                    {
                        system("cls");
                        break;
                    }
                    else
                        return 1;
                }

                else if (x == '2')
                {
                    system("cls");
                    b = 10;

                    printf(" ######            ###                                                   ##   ##                      ##\n");
                    printf("  ##  ##            ##                                                   ##   ##                      ##\n");
                    printf("  ##  ##   ####     ##  ##   ####    ##  ##    ####    #####             ##   ##  ##  ##   #####     #####    ####    ######\n");
                    printf("  #####   ##  ##    ## ##   ##  ##   #######  ##  ##   ##  ##            #######  ##  ##   ##  ##     ##     ##  ##    ##  ##\n");
                    printf("  ##      ##  ##    ####    ######   ## # ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ##     ######    ##\n");
                    printf("  ##      ##  ##    ## ##   ##       ##   ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ## ##  ##        ##\n");
                    printf(" ####      ####     ##  ##   #####   ##   ##   ####    ##  ##            ##   ##   ####    ##  ##      ###    #####   ####\n");
                    gotoxy(10, b);
                    printf("┌─────────────────────────────────────────────────────────────────────────────────────────┐\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("│                                                                                         │\n");
                    b++;
                    gotoxy(10, b);
                    printf("└─────────────────────────────────────────────────────────────────────────────────────────┘\n");

                    b = 13;
                    gotoxy(30, b);
                    rankingread(ranking);
                    return 3;
                }

                else if (x == '3')
                {
                    return 0;
                }
            }
            else
            {
                if (x == '1')
                {
                    system("cls");
                    if (dif_menu(difficulty, clearnum) == 0)
                    {
                        system("cls");
                        break;
                    }
                    else
                        return 1;
                }
                //else if (x == '2')
                //{
                //   system("cls");
                //   if (custom_menu(difficulty, custommap, customitem, jfrequ, customwall, jnum) == 0)
                //   {
                //      system("cls");
                //      break;
                //   }
                //   else
                //      return 2;
                //}
                else if (x == '2')
                {
                    return 0;
                }
            }

        }
    }
}

int dif_menu(int* difficulty, int clearnum)
{
    char x = '\0';

    if (clearnum == 0)
    {
        printf(" ######            ###                                                   ##   ##                      ##\n");
        printf("  ##  ##            ##                                                   ##   ##                      ##\n");
        printf("  ##  ##   ####     ##  ##   ####    ##  ##    ####    #####             ##   ##  ##  ##   #####     #####    ####    ######\n");
        printf("  #####   ##  ##    ## ##   ##  ##   #######  ##  ##   ##  ##            #######  ##  ##   ##  ##     ##     ##  ##    ##  ##\n");
        printf("  ##      ##  ##    ####    ######   ## # ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ##     ######    ##\n");
        printf("  ##      ##  ##    ## ##   ##       ##   ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ## ##  ##        ##\n");
        printf(" ####      ####     ##  ##   #####   ##   ##   ####    ##  ##            ##   ##   ####    ##  ##      ###    #####   ####\n");

        gotoxy(40, 10);
        printf("┌─────────────────────────────┐");
        gotoxy(40, 11);
        printf("│                             │");
        gotoxy(40, 12);
        printf("│           1. EASY           │");
        gotoxy(40, 13);
        printf("│                             │");
        gotoxy(40, 14);
        printf("│           2. NORMAL         │");
        gotoxy(40, 15);
        printf("│                             │");
        gotoxy(40, 16);
        printf("│           3. HARD           │");
        gotoxy(40, 17);
        printf("│                             │");
        gotoxy(40, 18);
        printf("│           4. Back           │");
        gotoxy(40, 19);
        printf("│                             │");
        gotoxy(40, 20);
        printf("└─────────────────────────────┘");
    }
    else
    {
        printf(" ######            ###                                                   ##   ##                      ##\n");
        printf("  ##  ##            ##                                                   ##   ##                      ##\n");
        printf("  ##  ##   ####     ##  ##   ####    ##  ##    ####    #####             ##   ##  ##  ##   #####     #####    ####    ######\n");
        printf("  #####   ##  ##    ## ##   ##  ##   #######  ##  ##   ##  ##            #######  ##  ##   ##  ##     ##     ##  ##    ##  ##\n");
        printf("  ##      ##  ##    ####    ######   ## # ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ##     ######    ##\n");
        printf("  ##      ##  ##    ## ##   ##       ##   ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ## ##  ##        ##\n");
        printf(" ####      ####     ##  ##   #####   ##   ##   ####    ##  ##            ##   ##   ####    ##  ##      ###    #####   ####\n");

        gotoxy(40, 10);
        printf("┌─────────────────────────────┐");
        gotoxy(40, 11);
        printf("│                             │");
        gotoxy(40, 12);
        printf("│           1. EASY           │");
        gotoxy(40, 13);
        printf("│                             │");
        gotoxy(40, 14);
        printf("│           2. NORMAL         │");
        gotoxy(40, 15);
        printf("│                             │");
        gotoxy(40, 16);
        printf("│           3. HARD           │");
        gotoxy(40, 17);
        printf("│                             │");
        gotoxy(40, 18);
        printf("│           4. EXTREME        │");
        gotoxy(40, 19);
        printf("│                             │");
        gotoxy(40, 20);
        printf("│           5. Back           │");
        gotoxy(40, 21);
        printf("│                             │");
        gotoxy(40, 22);
        printf("└─────────────────────────────┘");
    }

    while (1) {
        x = _getch();

        if (clearnum == 0)
        {
            if (x == '4')
            {
                system("cls");
                return 0;
            }

            else if (x == '1' || x == '2' || x == '3')
            {
                system("cls");
                *difficulty = x - 47; //47은 난이도 식따라 조절 일단 2, 3, 4로 해놔서 47으로 설정 5는 커스텀
                return 1;
            }
        }

        else
        {
            if (x == '5')
            {
                system("cls");
                return 0;
            }

            else if (x == '1' || x == '2' || x == '3' || x == '4')
            {
                system("cls");
                *difficulty = x - 47; //47은 난이도 식따라 조절 일단 2, 3, 4로 해놔서 47으로 설정 5는 커스텀
                return 1;
            }
        }
    }
}

int custom_menu(int* difficulty, int* custommap, int* customitem, int* jfrequ, int* customwall, int* jnum)
{
    int y = 13;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    char cusmap[3] = { '\0' }, cusitem[3] = { '\0' }, jnumber[3] = { '\0' }, freqarray[4] = { '\0' }, cuswall[4] = { '\0' }, ch;

    *difficulty = 5;
    *custommap = 4;
    *customitem = 16;
    *jfrequ = 1000;
    *customwall = 10;
    *jnum = 1;

    printf(" ######            ###                                                   ##   ##                      ##\n");
    printf("  ##  ##            ##                                                   ##   ##                      ##\n");
    printf("  ##  ##   ####     ##  ##   ####    ##  ##    ####    #####             ##   ##  ##  ##   #####     #####    ####    ######\n");
    printf("  #####   ##  ##    ## ##   ##  ##   #######  ##  ##   ##  ##            #######  ##  ##   ##  ##     ##     ##  ##    ##  ##\n");
    printf("  ##      ##  ##    ####    ######   ## # ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ##     ######    ##\n");
    printf("  ##      ##  ##    ## ##   ##       ##   ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ## ##  ##        ##\n");
    printf(" ####      ####     ##  ##   #####   ##   ##   ####    ##  ##            ##   ##   ####    ##  ##      ###    #####   ####\n");

    gotoxy(40, 10);
    printf("┌─────────────────────────────────────────────┐");
    gotoxy(40, 11);
    printf("│                                             │");
    gotoxy(40, 12);
    printf("│                                             │");
    gotoxy(40, 13);
    printf("│    1. 맵 크기:                              │");//쓰는거 x 62에
    gotoxy(40, 14);
    printf("│                                             │");
    gotoxy(40, 15);
    printf("│  최소 4, 최대 30 - 숫자 클수록 넓어짐       │");
    gotoxy(40, 16);
    printf("│                                             │");
    gotoxy(40, 17);
    printf("│    2. 아이템 빈도수:                        │");
    gotoxy(40, 18);
    printf("│                                             │");
    gotoxy(40, 19);
    printf("│  최소 1, 최대 16 - 숫자 낮을수록 자주 나옴  │");
    gotoxy(40, 20);
    printf("│                                             │");
    gotoxy(40, 21);
    printf("│    3. 잼민이 속도:                          │");
    gotoxy(40, 22);
    printf("│                                             │");
    gotoxy(40, 23);
    printf("│  최소 0, 최대 950 - 숫자 높을수록 빨라짐    │");
    gotoxy(40, 24);
    printf("│                                             │");
    gotoxy(40, 25);
    printf("│    4. 벽의 개수:                            │");
    gotoxy(40, 26);
    printf("│                                             │");
    gotoxy(40, 27);
    printf("│  최소 10, 최대 200 - 숫자 수만큼 벽 개수임  │");
    gotoxy(40, 28);
    printf("│                                             │");
    gotoxy(40, 29);
    printf("│    5. 잼민이 수:                            │");
    gotoxy(40, 30);
    printf("│                                             │");
    gotoxy(40, 31);
    printf("│  최소 1, 최대 10 - 숫자 수만큼 잼민이 나옴  │");
    gotoxy(40, 32);
    printf("│                                             │");
    gotoxy(40, 33);
    printf("│             Press ESC to go back            │");
    gotoxy(40, 34);
    printf("│                                             │");
    gotoxy(40, 35);
    printf("│            Press Enter to finish            │");
    gotoxy(40, 36);
    printf("└─────────────────────────────────────────────┘");

    while (1)
    {
        gotoxy(63, y);

        if (_kbhit())
        {
            ch = _getch();

            if (ch == -32)
            {
                ch = _getch();

                switch (ch)
                {
                case 72:
                    if (y != 13)
                        y -= 4;
                    break;

                case 80:
                    if (y != 29)
                        y += 4;
                    break;
                }
            }

            else if (ch == 27)
                return 0;

            else if (ch == '\r')
            {
                if (cusmap[0] == '0')
                {
                    if (!(cusmap[1] == '\0'))
                        *custommap = cusmap[1] - 48;
                }
                else if (!(cusmap[0] == '\0'))
                {
                    if (cusmap[1] == '\0')
                        *custommap = cusmap[0] - 48;
                    else
                        *custommap = (cusmap[0] - 48) * 10 + cusmap[1] - 48;
                }

                if (cusitem[0] == '0')
                {
                    if (!(cusitem[1] == '\0'))
                        *customitem = cusitem[1] - 48;
                }
                else if (!(cusitem[0] == '\0'))
                {
                    if (cusitem[1] == '\0')
                        *customitem = cusitem[0] - 48;
                    else
                        *customitem = (cusitem[0] - 48) * 10 + cusitem[1] - 48;
                }

                if (jnumber[0] == '0')
                {
                    if (!(jnumber[1] == '\0'))
                        *jnum = jnumber[1] - 48;
                }
                else if (!(jnumber[0] == '\0'))
                {
                    if (jnumber[1] == '\0')
                        *jnum = jnumber[0] - 48;
                    else
                        *jnum = (jnumber[0] - 48) * 10 + jnumber[1] - 48;
                }

                if (freqarray[0] == '0')
                {
                    if (freqarray[1] == '0')
                    {
                        if (!(freqarray[2] == '\0'))
                            *jfrequ = freqarray[2] - 48;
                    }
                    else if (!(freqarray[1] == '\0'))
                    {
                        if (freqarray[2] == '\0')
                            *jfrequ = freqarray[1] - 48;
                        else
                            *jfrequ = (freqarray[1] - 48) * 10 + freqarray[2] - 48;
                    }
                }
                else if (!(freqarray[0] == '\0'))
                {
                    if (freqarray[1] == '\0')
                        *jfrequ = freqarray[0] - 48;
                    else
                    {
                        if (freqarray[2] == '\0')
                            *jfrequ = (freqarray[0] - 48) * 10 + freqarray[1] - 48;
                        else
                            *jfrequ = (freqarray[0] - 48) * 100 + (freqarray[1] - 48) * 10 + freqarray[2] - 48;
                    }
                }

                if (cuswall[0] == '0')
                {
                    if (cuswall[1] == '0')
                    {
                        if (!(cuswall[2] == '\0'))
                            *customwall = cuswall[2] - 48;
                    }
                    else if (!(cuswall[1] == '\0'))
                    {
                        if (cuswall[2] == '\0')
                            *customwall = cuswall[1] - 48;
                        else
                            *customwall = (cuswall[1] - 48) * 10 + cuswall[2] - 48;
                    }
                }
                else if (!(cuswall[0] == '\0'))
                {
                    if (cuswall[1] == '\0')
                        *customwall = cuswall[0] - 48;
                    else
                    {
                        if (cuswall[2] == '\0')
                            *customwall = (cuswall[0] - 48) * 10 + cuswall[1] - 48;
                        else
                            *customwall = (cuswall[0] - 48) * 100 + (cuswall[1] - 48) * 10 + cuswall[2] - 48;
                    }
                }

                if (*custommap < 4)
                    *custommap = 4;
                else if (*custommap > 30)
                    *custommap = 30;

                if (*customitem < 1)
                    *customitem = 1;
                else if (*customitem > 16)
                    *customitem = 16;

                if (*jnum < 1)
                    *jnum = 1;
                else if (*jnum > 10)
                    *jnum = 10;

                if (*jfrequ < 0)
                    *jfrequ = 0;
                else if (*jfrequ > 950)
                    *jfrequ = 950;

                if (*customwall < 10)
                    *customwall = 10;
                else if (*customwall > 450)
                    *customwall = 450;

                if ((*custommap) * (*custommap) - 2 - (*jnum) < (*customwall))
                    *customwall = (*custommap) * (*custommap) - 1 - (*jnum);

                return 1;
            }

            else if (ch >= '0' && ch <= '9')
            {
                if (y == 13)
                {
                    if (i < 2)
                    {
                        cusmap[i] = ch;
                        gotoxy(63 + i, y);
                        printf("%c", ch);
                        i++;
                    }
                }
                else if (y == 17)
                {
                    if (j < 2)
                    {
                        cusitem[j] = ch;
                        gotoxy(63 + j, y);
                        printf("%c", ch);
                        j++;
                    }
                }
                else if (y == 21)
                {
                    if (k < 3)
                    {
                        freqarray[k] = ch;
                        gotoxy(63 + k, y);
                        printf("%c", ch);
                        k++;
                    }
                }
                else if (y == 25)
                {
                    if (l < 3)
                    {
                        cuswall[l] = ch;
                        gotoxy(63 + l, y);
                        printf("%c", ch);
                        l++;
                    }
                }
                else if (y == 29)
                {
                    if (m < 2)
                    {
                        jnumber[m] = ch;
                        gotoxy(63 + m, y);
                        printf("%c", ch);
                        m++;
                    }
                }
            }

            else if (ch == '\b')
            {
                if (y == 13 && i > 0)
                {
                    cusmap[i] = '\0';
                    gotoxy(63 + i - 1, y);
                    printf(" ");
                    i--;
                }
                else if (y == 17 && j > 0)
                {
                    cusitem[j] = '\0';
                    gotoxy(63 + j - 1, y);
                    printf(" ");
                    j--;
                }
                else if (y == 21 && k > 0)
                {
                    freqarray[k] = '\0';
                    gotoxy(63 + k - 1, y);
                    printf(" ");
                    k--;
                }
                else if (y == 25 && l > 0)
                {
                    cuswall[l] = '\0';
                    gotoxy(63 + l - 1, y);
                    printf(" ");
                    l--;
                }
                else if (y == 29 && m > 0)
                {
                    jnumber[m] = '\0';
                    gotoxy(63 + m - 1, y);
                    printf(" ");
                    m--;
                }
            }
        }
    }
}