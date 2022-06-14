#include "gameplay.h"

int main(void)
{
    int difficulty, menu_return, x, y, stime, ctime, i, j, startcode, itemnum, timelimit, wordnum, b_x, b_y, score, anyi, jfail, jfrequ, clearnum, flagget, extreme;
    //int jfrequ, custommap, customitem, customwall, jnum; //Ŀ���� ���� �Լ�
    int item[60][30][2] = { {0} }, map_array[68][34] = { {0} }; // ��, ������ ��ġ ����
    char word[WORDSTOPSIZE], inputword[WORDSTOPSIZE] = { '\0' }, anychar, name[11] = { '\0' }; // ������ �� Ű���� Ÿ����
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

        menu_return = main_inter(&difficulty, extreme, clearnum, ranking); //quit�� 0��ȯ �Ϲ� �����÷��̴� 1��ȯ

        if (menu_return == 0)
        {
            system("cls");
            gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
            printf("������ ����� ����˴ϴ�.");
            Sleep(1000);
            gotoxy(MAPLOCATIONX, MAPLOCATIONY + 7);
            printf("�ȳ������ʽÿ�.\n\n\n\n\n\n\n\n\n\n\n\n");
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
                item_location(item, map_array, difficulty, &b_x, &b_y); //Ŀ���� ���� �����

                system("cls");
                loading(map_array, item, 4); //�ε���,,, Ŀ���ҿ� �ٽ� ¥���ҵ�
                printmap(map_array); //�� Ŀ���� �״��
                printitem(item); //�굵 Ŀ���� �״��
                ingameui(difficulty); //��� Ŀ���� ����
                timelimit = 60;

                stime = time(NULL);
                ctime = 0;
                jtime = clock();
                locatejp(x, y, jm, difficulty, map_array, item); //Ŀ���ҿ� ��¦�� ������Ƽ ��� jnum ���ߵǰ� �� �ƴϳ� �� �����ϴ� ���� �־ߵǼ� Ŀ�����϶� �� ũ�⵵ ���ߵǳ� �� ���� ����
                startcode = rand() % ITEMCOUNT;
                itemnum = -1;

                jfrequ = 200;

                while (1)
                {
                    if (itemnum == -1 && time(NULL) > ctime + (4 * 2)) //Ŀ���ҿ��� �̰� �ð��� �����ع�����
                        moving(map_array, &x, &y); //difficulty ������ �ʿ��ؼ� �־����ǰ�
                    else if (itemnum == 0)
                    {
                        if (i == 0)
                        {
                            wordnum = 0;
                            wordstop(word, 4);
                            i++;
                        }
                        stop(word, inputword, &wordnum, &itemnum, &i, 4, map_array);
                    }//Ÿ�ڰ���
                    else if (time(NULL) <= ctime + (4 * 2)) //Ŀ���ҿ��� ���������� �ð��� ����
                        confuse(map_array, &x, &y);//�Ųٷ�
                     //���� Ű���� �ʿ��� �ֵ�

                    if (itemnum == -1)
                        itemnum = item_get(&x, &y, 4, item, startcode, b_x, b_y, &ctime, &j, &timelimit, &jfrequ, &flagget); //������ ���̵����� �ð� ���� �Ǵ� �ֵ� Ŀ���ҿ��� �� ��������ߵǰ�

                    if (time(NULL) >= (stime + 1))
                    {
                        timebar(&timelimit, 4);
                        stime = time(NULL);
                    }//Ÿ�ӹ�

                    jftime = clock();
                    if (jftime >= (jtime + jfrequ))
                    {
                        jaemin(map_array, item, jm, 9); //Ŀ���ҿ��� ������Ƽ ��� jnum����
                        jtime = clock();
                    }

                    if (time(NULL) == ctime + (4 * 2) + 1 && j == 1) //confuse ���� ���
                    {
                        gotoxy((4 * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, 4 * 8 + 3 + MAPLOCATIONY);
                        printf("                                                ");
                        gotoxy((4 * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, 4 * 8 + 3 + MAPLOCATIONY);
                        printf("���ݺ��� �ȹٷ� �����Դϴ�.");
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

                    if (item[x - 4 - MAPLOCATIONX][y - 2 - MAPLOCATIONY][0] == 1) //moving���� ���� �������ָ� �ʷ��� ���ֱ� ������
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
                        printf("������������������������������������������������������������������������������");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("��                                     ��");
                        anyi++;
                        gotoxy(22, anyi);
                        printf("������������������������������������������������������������������������������");
                        anyi = 0;

                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 2);
                        printf("       EXTREME LEVEL CLEAR!");
                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 3);
                        printf("           �����մϴ�!!\n");
                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
                        if (extreme == 1)
                            printf("  ���� ������ ���µ˴ϴ�.");
                        else
                            printf("�ͽ�Ʈ�� ������ %d�� Ŭ�����߽��ϴ�.", extreme);
                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 5);
                        printf("%d���� ���� ���翡 ��ϵ˴ϴ�.", score);
                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 6);
                        printf("  �̸��� �Է����ּ��� (10���� �̳�)");
                        gotoxy(MAPLOCATIONX + 9, MAPLOCATIONY + 7);
                        scanf_s("%s", name, sizeof(name) - 1);

                        ranking = fopen("rank.txt", "a+t");
                        fprintf(ranking, "%s %d\n", name, score);
                        fclose(ranking);

                        gotoxy(MAPLOCATIONX, MAPLOCATIONY + 8);
                        printf("       �ƹ� Ű�� ��������");

                        anychar = _getch();

                        break;
                    }//���̵� Ŭ����
                } // �׳� Ŀ���ҿ��� difficulty ���� �ֵ��� difficulty 5�϶��� ���� �����ؼ� �� ����ߵǳ� �Ⱦ�
            }

            else
            {
                while (1)
                {
                    map(difficulty, map_array); //Ŀ���� ���θ����
                    item_location(item, map_array, difficulty, &b_x, &b_y); //Ŀ���� ���� �����

                    system("cls");
                    loading(map_array, item, difficulty); //�ε���,,, Ŀ���ҿ� �ٽ� ¥���ҵ�
                    printmap(map_array); //�� Ŀ���� �״��
                    printitem(item); //�굵 Ŀ���� �״��
                    ingameui(difficulty); //��� Ŀ���� ����
                    timelimit = 60;

                    stime = time(NULL);
                    ctime = 0;
                    jtime = clock();
                    locatejp(x, y, jm, difficulty, map_array, item); //Ŀ���ҿ� ��¦�� ������Ƽ ��� jnum ���ߵǰ� �� �ƴϳ� �� �����ϴ� ���� �־ߵǼ� Ŀ�����϶� �� ũ�⵵ ���ߵǳ� �� ���� ����
                    startcode = rand() % ITEMCOUNT;
                    itemnum = -1;

                    if (difficulty == 2)
                        jfrequ = 500;
                    else if (difficulty == 3)
                        jfrequ = 430;
                    else if (difficulty == 4)
                        jfrequ = 300; //jfrequ �� �ƿ� �׳� ������ �Ǵϱ� ����

                    while (1)
                    {
                        if (itemnum == -1 && time(NULL) > ctime + (difficulty * 2)) //Ŀ���ҿ��� �̰� �ð��� �����ع�����
                            moving(map_array, &x, &y); //difficulty ������ �ʿ��ؼ� �־����ǰ�
                        else if (itemnum == 0)
                        {
                            if (i == 0)
                            {
                                wordnum = 0;
                                wordstop(word, difficulty);
                                i++;
                            }
                            stop(word, inputword, &wordnum, &itemnum, &i, difficulty, map_array);
                        }//Ÿ�ڰ���
                        else if (time(NULL) <= ctime + (difficulty * 2)) //Ŀ���ҿ��� ���������� �ð��� ����
                            confuse(map_array, &x, &y);//�Ųٷ�
                         //���� Ű���� �ʿ��� �ֵ�

                        if (itemnum == -1)
                            itemnum = item_get(&x, &y, difficulty, item, startcode, b_x, b_y, &ctime, &j, &timelimit, &jfrequ, &flagget); //������ ���̵����� �ð� ���� �Ǵ� �ֵ� Ŀ���ҿ��� �� ��������ߵǰ�

                        if (time(NULL) >= (stime + 1))
                        {
                            timebar(&timelimit, difficulty);
                            stime = time(NULL);
                        }//Ÿ�ӹ�

                        jftime = clock();
                        if (jftime >= (jtime + jfrequ))
                        {
                            jaemin(map_array, item, jm, difficulty); //Ŀ���ҿ��� ������Ƽ ��� jnum����
                            jtime = clock();
                        }

                        if (time(NULL) == ctime + (difficulty * 2) + 1 && j == 1) //confuse ���� ���
                        {
                            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
                            printf("                                                ");
                            gotoxy((difficulty * 16 + 4) / 2 - 32 + MAPLOCATIONX + 8, difficulty * 8 + 3 + MAPLOCATIONY);
                            printf("���ݺ��� �ȹٷ� �����Դϴ�.");
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

                        if (item[x - 4 - MAPLOCATIONX][y - 2 - MAPLOCATIONY][0] == 1) //moving���� ���� �������ָ� �ʷ��� ���ֱ� ������
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
                                printf("��������������������������������������������������������������");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��                             ��");
                                anyi++;
                                gotoxy(22, anyi);
                                printf("��������������������������������������������������������������");
                                anyi = 0;

                                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 3);
                                printf("         CLEAR!");
                                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
                                printf(" ���� ���̵��� �Ѿ�ϴ�.\n");
                                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 5);
                                printf("���� ������ %d ���Դϴ�.\n", score);
                                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 6);
                                printf("   �ƹ� Ű�� ��������");

                                anychar = _getch();
                            }
                            break;
                        }//���̵� Ŭ����
                    } // �׳� Ŀ���ҿ��� difficulty ���� �ֵ��� difficulty 5�϶��� ���� �����ؼ� �� ����ߵǳ� �Ⱦ�

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
                    printf(" �� ������ %d���Դϴ�.", score);
                }
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 5);
                printf("3���� �޴��� ���ư��ϴ�.");
                Sleep(3000);
                continue;
            } //�ð� ������ ���ӿ���

            if (difficulty == 5)
            {
                clearnum++;
                system("cls");

                anyi = MAPLOCATIONY;
                gotoxy(22, anyi);
                printf("����������������������������������������������������������������������������������������������������");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("��                                                ��");
                anyi++;
                gotoxy(22, anyi);
                printf("����������������������������������������������������������������������������������������������������");
                anyi = 0;
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 3);
                printf("               �����մϴ�!");
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 4);
                printf(" ����̵�� ������ ���� ���ϸ��� ������ϴ�!");
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 5);
                printf("         �� ������ %d���Դϴ�.", score);
                if (clearnum == 1)
                {
                    gotoxy(MAPLOCATIONX, MAPLOCATIONY + 6);
                    printf("         EXTREME ������ ���Ƚ��ϴ�.");
                }
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 7);
                printf("    ���ݱ��� ������ %d�� Ŭ�����Ͽ����ϴ�.", clearnum - extreme);
                gotoxy(MAPLOCATIONX, MAPLOCATIONY + 8);
                printf("           �ƹ� Ű�� ��������.");
                anychar = _getch();
                continue;
            } //���� Ŭ����
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