#include "gameplay.h"

int main(void)
{
    int difficulty, menu_return, x, y, stime, ctime, i, j, startcode, itemnum, timelimit, wordnum, b_x, b_y, score, anyi, jfail, jfrequ, clearnum, flagget, extreme;
    //int jfrequ, custommap, customitem, customwall, jnum; //커스텀 관련 함수
    int item[60][30][2] = { {0} }, map_array[68][34] = { {0} }; // 맵, 아이템 위치 관련
    char word[WORDSTOPSIZE], inputword[WORDSTOPSIZE] = { '\0' }, anychar, name[11] = { '\0' }; // 아이템 중 키보드 타이핑
    clock_t jtime, jftime;
    struct jcoord jm[10] = { {0,0} };

    srand((unsigned int)time(NULL));
    x = 4 + MAPLOCATIONX;
    y = 2 + MAPLOCATIONY;
    timelimit = 0;
    difficulty = 0;
    i = 0;
    j = 0;
    jfrequ = 1000;
    extreme = 0;
    clearnum = 0;
    //custommap = 4;
    //customitem = 1;
    //customwall = 1;
    //jnum = 1;
    FILE* ranking = fopen("rank.txt", "at");
    fclose(ranking);

    system("mode con cols=160 lines=60");

    start();
    description1();

    while (1)
    {
        system("cls");

        menu_return = main_inter(&difficulty, extreme, clearnum, ranking); //quit는 0반환 일반 게임플레이는 1반환

        if (menu_return == 0)
        {
            system("cls");
            gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
            printf("게임이 잠시후 종료됩니다.");
            Sleep(1000);
            gotoxy(MAPLOCATIONX, MAPLOCATIONY + 7);
            printf("안녕히가십시오.\n\n\n\n\n\n\n\n\n\n\n\n");
            return 0;
        }

        else if (menu_return == 1)
        {
            flagget = 0;
            jfail = 0;
            score = 0;

            if (difficulty == 5 && clearnum > 0)
            {
                map(difficulty, map_array);
                item_location(item, map_array, difficulty, &b_x, &b_y); //커스텀 따로 만들기

                system("cls");
                loading(map_array, item, 4); //로딩도,,, 커스텀용 다시 짜야할듯
                printmap(map_array); //얜 커스텀 그대로
                printitem(item); //얘도 커스텀 그대로
                ingameui(difficulty); //얘는 커스텀 따로
                timelimit = 60;

                stime = time(NULL);
                ctime = 0;
                jtime = clock();
                locatejp(x, y, jm, difficulty, map_array, item); //커스텀용 살짝만 디피컬티 대신 jnum 들어가야되고 ㅏ 아니네 그 생성하는 제한 둬야되서 커스텀일때 맵 크기도 들어가야되네 걍 따로 ㄱㄱ
                startcode = rand() % ITEMCOUNT;
                itemnum = -1;

                jfrequ = 200;

                while (1)
                {
                    if (itemnum == -1 && time(NULL) > ctime + (4 * 2)) //커스텀에서 이거 시간만 지정해버리자
                        moving(map_array, &x, &y); //difficulty 전달이 필요해서 넣었던건가
                    else if (itemnum == 0)
                    {
                        if (i == 0)
                        {
                            wordnum = 0;
                            wordstop(word, 4);
                            i++;
                        }
                        stop(word, inputword, &wordnum, &itemnum, &i, 4, map_array);
                    }//타자게임
                    else if (time(NULL) <= ctime + (4 * 2)) //커스텀에서 마찬가지로 시간만 지정
                        confuse(map_array, &x, &y);//거꾸로
                     //대충 키보드 필요한 애들

                    if (itemnum == -1)
                        itemnum = item_get(&x, &y, 4, item, startcode, b_x, b_y, &ctime, &j, &timelimit, &jfrequ, &flagget); //아이템 난이도별로 시간 지정 되는 애들 커스텀에서 다 지정해줘야되고

                    if (time(NULL) >= (stime + 1))
                    {
                        timebar(&timelimit, 4);
                        stime = time(NULL);
                    }//타임바

                    jftime = clock();
                    if (jftime >= (jtime + jfrequ))
                    {
                        jaemin(map_array, item, jm, 9); //커스텀에서 디피컬티 대신 jnum으로
                        jtime = clock();
                    }

                    if (time(NULL) == ctime + (4 * 2) + 1 && j == 1) //confuse 끊김 출력
                    {
                        gotoxy((4 * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, 4 * 8 + 3 + MAPLOCATIONY);
                        printf("                                                ");
                        gotoxy((4 * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, 4 * 8 + 3 + MAPLOCATIONY);
                        printf("지금부터 똑바로 움직입니다.");
                        j = 0;
                    }

                    for (anyi = 0; anyi < 8; anyi++)
                    {
                        if (x == jm[anyi].x && y == jm[anyi].y)
                        {
                            jfail++;
                            break;
                        }
                    }

                    if (jfail == 1 || timelimit <= 0)
                        break;

                    if (item[x - 4 - MAPLOCATIONX][y - 2 - MAPLOCATIONY][0] == 1) //moving에서 조건 설정해주면 초록줄 없애기 ㅆㄱㄴ
                    {
                        x = 4 + MAPLOCATIONX;
                        y = 2 + MAPLOCATIONY;
                        difficulty++;
                        extreme++;
                        clearnum++;

                        score += timelimit * 500;
                        score += flagget * 100;

                        system("cls");

                        anyi = MAPLOCATIONY;

                        gotoxy(22, anyi);
                        printf("┌─────────────────────────────────────┐");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("│                                     │");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("└─────────────────────────────────────┘");
                        anyi = 0;

                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 2);
                        printf("       EXTREME LEVEL CLEAR!");
                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 3);
                        printf("           축하합니다!!\n");
                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
                        if (extreme == 1)
                            printf("  명예의 전당이 오픈됩니다.");
                        else
                            printf("익스트림 레벨을 %d번 클리어했습니다.", extreme);
                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 5);
                        printf("%d점이 명예의 전당에 기록됩니다.", score);
                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 6);
                        printf("  이름을 입력해주세요 (10글자 이내)");
                        gotoxy(MAPLOCATIONX + 9, MAPLOCATIONY + 7);
                        scanf_s("%s", name, sizeof(name) - 1);

                        ranking = fopen("rank.txt", "a+t");
                        fprintf(ranking, "%s %d\n", name, score);
                        fclose(ranking);

                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 8);
                        printf("       아무 키나 누르세요");

                        anychar = _getch();

                        break;
                    }//난이도 클리어
                } // 그냥 커스텀에서 difficulty 들어가는 애들은 difficulty 5일때로 따로 지정해서 다 해줘야되네 ㅘ씨
            }

            else
            {
                while (1)
                {
                    map(difficulty, map_array); //커스텀 따로만들기
                    item_location(item, map_array, difficulty, &b_x, &b_y); //커스텀 따로 만들기

                    system("cls");
                    loading(map_array, item, difficulty); //로딩도,,, 커스텀용 다시 짜야할듯
                    printmap(map_array); //얜 커스텀 그대로
                    printitem(item); //얘도 커스텀 그대로
                    ingameui(difficulty); //얘는 커스텀 따로
                    timelimit = 60;

                    stime = time(NULL);
                    ctime = 0;
                    jtime = clock();
                    locatejp(x, y, jm, difficulty, map_array, item); //커스텀용 살짝만 디피컬티 대신 jnum 들어가야되고 ㅏ 아니네 그 생성하는 제한 둬야되서 커스텀일때 맵 크기도 들어가야되네 걍 따로 ㄱㄱ
                    startcode = rand() % ITEMCOUNT;
                    itemnum = -1;

                    if (difficulty == 2)
                        jfrequ = 500;
                    else if (difficulty == 3)
                        jfrequ = 430;
                    else if (difficulty == 4)
                        jfrequ = 300; //jfrequ 얜 아예 그냥 지정이 되니까 빼고

                    while (1)
                    {
                        if (itemnum == -1 && time(NULL) > ctime + (difficulty * 2)) //커스텀에서 이거 시간만 지정해버리자
                            moving(map_array, &x, &y); //difficulty 전달이 필요해서 넣었던건가
                        else if (itemnum == 0)
                        {
                            if (i == 0)
                            {
                                wordnum = 0;
                                wordstop(word, difficulty);
                                i++;
                            }
                            stop(word, inputword, &wordnum, &itemnum, &i, difficulty, map_array);
                        }//타자게임
                        else if (time(NULL) <= ctime + (difficulty * 2)) //커스텀에서 마찬가지로 시간만 지정
                            confuse(map_array, &x, &y);//거꾸로
                         //대충 키보드 필요한 애들

                        if (itemnum == -1)
                            itemnum = item_get(&x, &y, difficulty, item, startcode, b_x, b_y, &ctime, &j, &timelimit, &jfrequ, &flagget); //아이템 난이도별로 시간 지정 되는 애들 커스텀에서 다 지정해줘야되고

                        if (time(NULL) >= (stime + 1))
                        {
                            timebar(&timelimit, difficulty);
                            stime = time(NULL);
                        }//타임바

                        jftime = clock();
                        if (jftime >= (jtime + jfrequ))
                        {
                            jaemin(map_array, item, jm, difficulty); //커스텀에서 디피컬티 대신 jnum으로
                            jtime = clock();
                        }

                        if (time(NULL) == ctime + (difficulty * 2) + 1 && j == 1) //confuse 끊김 출력
                        {
                            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
                            printf("                                                ");
                            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
                            printf("지금부터 똑바로 움직입니다.");
                            j = 0;
                        }

                        for (anyi = 0; anyi < difficulty - 1; anyi++)
                        {
                            if (x == jm[anyi].x && y == jm[anyi].y)
                            {
                                jfail++;
                                break;
                            }
                        }

                        if (jfail == 1 || timelimit <= 0)
                            break;

                        if (item[x - 4 - MAPLOCATIONX][y - 2 - MAPLOCATIONY][0] == 1) //moving에서 조건 설정해주면 초록줄 없애기 ㅆㄱㄴ
                        {
                            if (difficulty == 2)
                                score += timelimit * 100;
                            else if (difficulty == 3)
                                score += timelimit * 300;
                            else if (difficulty == 4)
                                score += timelimit * 500;

                            x = 4 + MAPLOCATIONX;
                            y = 2 + MAPLOCATIONY;

                            difficulty++;
                            if (difficulty == 3 || difficulty == 4)
                            {
                                system("cls");

                                anyi = MAPLOCATIONY;

                                gotoxy(22, anyi);
                                printf("┌─────────────────────────────┐");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("│                             │");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("└─────────────────────────────┘");
                                anyi = 0;

                                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 3);
                                printf("         CLEAR!");
                                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
                                printf(" 다음 난이도로 넘어갑니다.\n");
                                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 5);
                                printf("현재 점수는 %d 점입니다.\n", score);
                                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 6);
                                printf("   아무 키나 누르세요");

                                anychar = _getch();
                            }
                            break;
                        }//난이도 클리어
                    } // 그냥 커스텀에서 difficulty 들어가는 애들은 difficulty 5일때로 따로 지정해서 다 해줘야되네 ㅘ씨

                    if (difficulty == 5 || timelimit <= 0 || jfail == 1)
                        break;
                }
            }

            if (timelimit <= 0 || jfail == 1)
            {
                x = 4 + MAPLOCATIONX;
                y = 2 + MAPLOCATIONY;
                system("cls");
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 3);
                printf("       GAME OVER");
                if (difficulty == 2 || difficulty == 3 || difficulty == 4)
                {
                    gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
                    printf(" 총 점수는 %d점입니다.", score);
                }
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 5);
                printf("3초후 메뉴로 돌아갑니다.");
                Sleep(3000);
                continue;
            } //시간 끝나서 게임오버

            if (difficulty == 5)
            {
                clearnum++;
                system("cls");

                anyi = MAPLOCATIONY;
                gotoxy(22, anyi);
                printf("┌────────────────────────────────────────────────┐");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("│                                                │");
                anyi++;
                gotoxy(22, anyi);
                printf("└────────────────────────────────────────────────┘");
                anyi = 0;
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 3);
                printf("               축하합니다!");
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
                printf(" 잼민이들과 함정을 피해 포켓몬빵을 얻었습니다!");
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 5);
                printf("         총 점수는 %d점입니다.", score);
                if (clearnum == 1)
                {
                    gotoxy(MAPLOCATIONX, MAPLOCATIONY + 6);
                    printf("         EXTREME 레벨이 열렸습니다.");
                }
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 7);
                printf("    지금까지 게임을 %d번 클리어하였습니다.", clearnum - extreme);
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 8);
                printf("           아무 키나 누르세요.");
                anychar = _getch();
                continue;
            } //게임 클리어
        }

        //else if (menu_return == 2)
        //{
        //   system("cls");
        //   printf("%d, %d, %d, %d, %d", custommap, customitem, jfrequ, customwall, jnum);
        //   Sleep(1000);

        //   difficulty = 4;

        //   custommapping(custommap, customwall, map_array);
        //   printmap(map_array);

        //   anychar = _getch();
        //}
    }
    return 0;
}