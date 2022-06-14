#include "gameplay.h"

void rankingread(FILE* ranking)
{
    int scorerank[5] = { 0 }, i, score, j, b;
    char namerank[5][11] = { '\0' }, name[11] = { '\0' }, ch;

    ranking = fopen("rank.txt", "r+t");

    while (fscanf(ranking, "%s %d", name, &score) != -1)
    {
        for (j = 0; j < 5; j++)
        {
            if (scorerank[j] < score)
            {
                for (i = 4; i > j; i--)
                {
                    scorerank[i] = scorerank[i - 1];
                    strcpy(namerank[i], namerank[i - 1]);
                }

                scorerank[j] = score;
                strcpy(namerank[j], name);

                break;
            }
        }
    }

    fclose(ranking);

    b = 12;
    for (i = 0; i < 5; i++)
    {
        gotoxy(30, b);
        printf("%d. %s - %d", i + 1, namerank[i], scorerank[i]);
        b++;
        b++;
    }

    ch = _getch();
}