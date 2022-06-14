//아이템 관련 함수들

#include "gameplay.h"

void item_location(int world_item[][30][2], int map_array[][34], int di, int* b_x, int* b_y)
{
    int i, j = 0, x, y, z, guang, flag, difficulty;
    guang = 1;
    difficulty = di;

    if (difficulty == 2)
        flag = 7;
    else if (difficulty == 5)
        flag = 40;
    else
        flag = (difficulty - 1) * 7;

    if (difficulty == 5)
        difficulty = 4;
    //flag = 0;//개발용

    for (x = 0; x < 60; x++)
    {
        for (y = 0; y < 30; y++)
        {
            for (z = 0; z < 2; z++)
                world_item[x][y][z] = 0;
        }
    }

    for (i = 0; i < flag; i++)
    {
        x = (rand() % (difficulty * 16 - 4) / 2) * 2;//아이템이 서로 겹치지 않게 최소 2칸에 하나씩 나오게
        y = rand() % (difficulty * 8 - 2);

        if ((world_item[x][y][0] == 1) || (world_item[x][y][0] == 2) || (x == 0 && y == 0) || (map_array[x + 4][y + 2] == 1))
            i--;
        else
        {
            if (guang < flag) //1: 보물 2: 꽝
            {
                world_item[x][y][0] = 2;
                guang++;
                world_item[x][y][1] = j;
                j++;
            }
            else
            {
                world_item[x][y][0] = 1;
                *b_x = x;
                *b_y = y;
            }
        }
    }
}

void printitem(int world_item[][30][2])
{
    int x, y;

    for (x = 0; x < 60; x++)
    {
        for (y = 0; y < 30; y++)
        {
            if ((world_item[x][y][0] == 1) || (world_item[x][y][0] == 2)) //보물
            {
                gotoxy(x + 4 + MAPLOCATIONX, y + 2 + MAPLOCATIONY);
                printf("▶");
            }

            //if (world_item[x][y][0] == 2) //꽝
            //{
            //    gotoxy(x + 4 + MAPLOCATIONX, y + 2 + MAPLOCATIONY);
            //    printf("■");
            //}
        }
    }
}

int item_get(int* x, int* y, int difficulty, int world_item[][30][2], int startcode, int b_x, int b_y, int* ctime, int* j, int* timelimit, int* jfrequ, int* flagget)
{
    //1부터 n까지 3차원배열에 넣으니까 1부터 차례대로 아이템 종류 순서를 정해서 넣는거지
    //아이템 순서 바뀌게 해서 넣을려면 1~n중에 숫자 하나 랜덤으로 튀어나오게 해서 해당 숫자가 배정된 아이템부터 넣어지게
    static int i = 25; //개발용 표시기
    int itemcode;

    if (world_item[(*x) - 4 - MAPLOCATIONX][(*y) - 2 - MAPLOCATIONY][0] == 2)
    {
        gotoxy(0, i); //개발
        printf("itemitemitem"); //용 표
        //i++; //시기

        itemcode = (world_item[(*x) - 4 - MAPLOCATIONX][(*y) - 2 - MAPLOCATIONY][1] % ITEMCOUNT + startcode) % ITEMCOUNT;
        //itemcode = 6; //개발용
        world_item[(*x) - 4 - MAPLOCATIONX][(*y) - 2 - MAPLOCATIONY][0] = 0;

        if (itemcode == 0)
        {
            gotoxy(*x, *y);

            return 0;
        }
        else if (itemcode == 1)
            detector(*x, *y, b_x, b_y, difficulty);
        else if (itemcode == 2)
            respawn(x, y, difficulty);
        else if (itemcode == 3)
        {
            *ctime = time(NULL);
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
            printf("                                                ");
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY + 1);
            printf("                                                ");
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
            printf("%d초까지 거꾸로 움직입니다.", *timelimit - difficulty * 2);
            *j = 1;
        }
        else if (itemcode == 4)
            timechange(timelimit, difficulty);
        else if (itemcode == 5)
            deleteflag(world_item, difficulty);
        else if (itemcode == 6)
            changejfrequ(jfrequ, difficulty);

        gotoxy(*x, *y);
        (*flagget)++;

        return -1;
    }

    return -1;
}

void deleteflag(int item[][30][2], int difficulty)
{
    int i, j, x, z, noflag, randomy;

    noflag = 0;

    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    printf("                                                ");
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    printf("꽝이 2개 없어집니다.");

    for (i = 0; i < 2; i++)
    {
        z = 0;

        randomy = rand() % (difficulty * 8 - 3) + 1;
        j = randomy;

        while (1)
        {
            for (x = 0; x < (difficulty * 16 - 4); x = x + 2)
            {
                if (item[x][j][0] == 2)
                {
                    item[x][j][0] = 0;
                    gotoxy(x + MAPLOCATIONX + 4, j + MAPLOCATIONY + 2);
                    printf("  \b\b");

                    z++;
                    break;
                }
            }

            if (z == 1)
                break;

            j++;

            if (j == (difficulty * 8 - 2))
                j = 0;

            if (j == randomy - 1)
            {
                noflag++;
                break;
            }
        }

        if (noflag == 1)
            break;
    }
}

void wordstop(char word[], int difficulty)
{
    int i;

    for (i = 0; i < WORDSTOPSIZE - 1; i++)
        word[i] = 'a' + rand() % 26;
    word[i] = '\0';
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    printf("                                ");
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY + 1);
    printf("                         ");
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    printf("제시된 단어를 똑같이 쓸때까지 움직이지 못합니다.");
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY + 1);
    printf("해당 문자열을 따라 적으세요: %s - ", word);
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY + 1);
}

void stop(const char w[], char sword[], int* i, int* itemnum, int* wstop, int difficulty, int map_array[][34])
{
    char ch;

    if (_kbhit())
    {
        ch = _getch();

        if (ch >= 'a' && ch <= 'z')
        {
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 46 + (*i), difficulty * 8 + 3 + MAPLOCATIONY + 1);

            printf("%c", ch);
            sword[(*i)] = ch;
            (*i)++;
        }
        else if (ch == '\b' && (*i) > 0)
        {
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 46 + (*i), difficulty * 8 + 3 + MAPLOCATIONY + 1);

            printf("\b \b");
            (*i)--;
            sword[(*i)] = '\0';
        }
    }

    if ((*i) >= (WORDSTOPSIZE - 1))
    {
        sword[(*i)] = '\0';
        if (!strcmp(w, sword))
        {
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
            printf("                                                    ");
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY + 1);
            printf("                                                    ");
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
            printf("지금부터 다시 움직일 수 있습니다.");
            *itemnum = -1;
            *wstop = 0;
            printmap(map_array);
        }
        else
        {
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 46, difficulty * 8 + 3 + MAPLOCATIONY + 1);
            printf("      ");
            for ((*i) = 0; (*i) < WORDSTOPSIZE; (*i)++)
                sword[(*i)] = '\0';
            gotoxy(10, 42);
            (*i) = 0;
        }
    }
}

void detector(int x, int y, int m, int n, int difficulty)
{
    int a, b;

    a = x - 4 - MAPLOCATIONX;
    b = y - 2 - MAPLOCATIONY;

    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    printf("                                      ");
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    if (a < m && b > n)
        printf("북동쪽에 포켓몬 빵이 있습니다.");
    else if (a > m && b > n)
        printf("북서쪽에 포켓몬 빵이 있습니다.");
    else if (a > m && b < n)
        printf("남서쪽에 포켓몬 빵이 있습니다.");
    else if (a < m && b < n)
        printf("남동쪽에 포켓몬 빵이 있습니다.");
    else if (a == m && b > n)
        printf("북쪽에 포켓몬 빵이 있습니다.");
    else if (a == m && b < n)
        printf("남쪽에 포켓몬 빵이 있습니다.");
    else if (a < m && b == n)
        printf("동쪽에 포켓몬 빵이 있습니다.");
    else if (a > m && b == n)
        printf("서쪽에 포켓몬 빵이 있습니다.");
}

void respawn(int* x, int* y, int difficulty) //x, y는 플레이어 좌표 매개변수
{
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    printf("                                      ");
    gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
    printf("처음 위치로 리스폰됩니다.");
    gotoxy(*x, *y);
    printf("  ");
    *x = 4 + MAPLOCATIONX;
    *y = 2 + MAPLOCATIONY;
    gotoxy(*x, *y);
    printf("◆\b\b");
}

void confuse(int map[][34], int* x, int* y)
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
                if (map[(*x) - MAPLOCATIONX][(*y) + 1 - MAPLOCATIONY] == 0)
                {
                    gotoxy(*x, *y);
                    printf("  ");
                    (*y)++;
                    gotoxy(*x, *y);
                    printf("◆\b\b");
                    //printf("◆\b");
                }
                break;

            case 80:
                if (map[(*x) - MAPLOCATIONX][(*y) - 1 - MAPLOCATIONY] == 0)
                {
                    gotoxy(*x, *y);
                    printf("  ");
                    (*y)--;
                    gotoxy(*x, *y);
                    printf("◆\b\b");
                    //printf("◆\b");
                }
                break;

            case 75:
                if (map[(*x) + 2 - MAPLOCATIONX][(*y) - MAPLOCATIONY] == 0)
                {
                    gotoxy(*x, *y);
                    printf("  ");
                    (*x)++;
                    (*x)++;
                    gotoxy(*x, *y);
                    printf("◆\b\b");
                    //printf("◆\b");
                }
                break;

            case 77:
                if (map[(*x) - 2 - MAPLOCATIONX][(*y) - MAPLOCATIONY] == 0)
                {
                    gotoxy(*x, *y);
                    printf("  ");
                    (*x)--;
                    (*x)--;
                    gotoxy(*x, *y);
                    printf("◆\b\b");
                    //printf("◆\b"); 
                }
                break;
            }
        }
    }
}

void timechange(int* timelimit, int difficulty)
{
    int i;

    i = rand() % 2;

    if (i == 0)
    {
        gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
        printf("                                                ");
        gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
        printf("시간이 %d초 줄어듭니다.", difficulty + 1);

        *timelimit = (*timelimit) - difficulty - 1;

        gotoxy(difficulty * 16 + 4 + MAPLOCATIONX + 8, (difficulty * 8 + 2) / 2 - 2 + MAPLOCATIONY);
        if ((*timelimit) < 10)
            printf("0%d", *timelimit);
        else
            printf("%d", *timelimit);
    }
    else
    {
        gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
        printf("                                                ");
        gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
        printf("시간이 %d초 늘어납니다.", 5 - difficulty);

        *timelimit = (*timelimit) - difficulty + 5;

        gotoxy(difficulty * 16 + 4 + MAPLOCATIONX + 8, (difficulty * 8 + 2) / 2 - 2 + MAPLOCATIONY);
        if ((*timelimit) < 10)
            printf("0%d", *timelimit);
        else
            printf("%d", *timelimit);
    }
}

void changejfrequ(int* jfrequ, int difficulty)
{
    int i;

    i = rand() % 3;

    if (i == 0)
    {
        gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
        printf("                                                ");
        gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
        printf("잼민이의 속도가 느려집니다.");
        *jfrequ += 70;
    }
    else
    {
        if (*jfrequ > 70)
        {
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
            printf("                                                ");
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
            printf("잼민이의 속도가 빨라집니다.");
            *jfrequ -= 70;
        }
        else
        {
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
            printf("                                                ");
            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
            printf("이미 잼민이의 속도가 빨라질대로 빨라졌습니다.");
        }
    }
}