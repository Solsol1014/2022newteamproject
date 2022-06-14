//�ʱ� 3- 31x15 �߱� 4- 41x19 ��� 5- 51x23 (������) //����- 10x+1 ����- 4x+3
#include "gameplay.h"

void map(int difficulty, int map_array[][34]) //x�� difficulty
{
    int x, ix, iy, box;

    x = difficulty;

    if (x == 4)
        box = 100;
    else if (x == 5)
        box = 150;
    else
        box = 25 * (x - 1);

    for (ix = 0; ix < 68; ix++)
    {
        for (iy = 0; iy < 34; iy++)
            map_array[ix][iy] = 0;
    }

    if (x == 5)
        x = 4;

    for (ix = 0; ix < x * 16 + 4; ix++)
    {
        for (iy = 0; iy < x * 8 + 2; iy++)
        {
            if ((iy == 0) || (iy == 1))
                map_array[ix][iy] = 1;

            if ((ix == 0) || (ix == 1) || (ix == 2) || (ix == 3))
                map_array[ix][iy] = 1;

            if ((ix == x * 16) || (ix == x * 16 + 1) || (ix == x * 16 + 2) || (ix == x * 16 + 3))
                map_array[ix][iy] = 1;

            if ((iy == x * 8) || (iy == x * 8 + 1))
                map_array[ix][iy] = 1;
        }
    }

    while (box > 0)
    {
        while (box > 0)
        {
            ix = (rand() % ((x * 16 - 4) / 2)) * 2 + 4;
            iy = rand() % (x * 8 - 2) + 2;

            if (map_array[ix][iy] == 0 && !(ix == 4 && iy == 2))
            {
                map_array[ix][iy] = 1;
                map_array[ix + 1][iy] = 1;
                box--;
            }
        }

        for (ix = 0; ix < x * 16; ix++)
        {
            for (iy = 0; iy < x * 8; iy++)
            {
                if (map_array[ix][iy] == 0)
                {
                    if (map_array[ix - 2][iy] == 1 && map_array[ix + 2][iy] == 1 && map_array[ix][iy + 1] == 1 && map_array[ix][iy - 1] == 1)
                    {
                        if (iy == 2)
                            map_array[ix][iy + 1] = 0;
                        else
                            map_array[ix][iy - 1] = 0;
                        box++; //Ŀ���ҿ����� �̰��� 200�� �ߴµ��� �ȵǸ� �� �ĳ־����� ����
                    }
                }
            }
        }
    }
}

void printmap(int map_array[][34])
{
    int ix, iy;

    for (ix = 0; ix < 68; ix = ix + 2)
    {
        for (iy = 0; iy < 34; iy++)
        {
            if (map_array[ix][iy] == 1)
            {
                gotoxy(ix + MAPLOCATIONX, iy + MAPLOCATIONY);
                printf("��");
            }
        }
    }
}

void locatejp(int x, int y, struct jcoord* jm, int difficulty, int map_array[][34], int item[][30][2])
{
    int i;

    gotoxy(x, y);
    printf("��\b\b");

    if (difficulty == 5)
    {
        for (i = 0; i < 8; i++)
        {
            jm[i].x = (rand() % ((4 * 16 - 4) / 2)) * 2 + 4 + MAPLOCATIONX;
            jm[i].y = rand() % (4 * 8 - 2) + 2 + MAPLOCATIONY;

            if (map_array[(jm[i].x) - MAPLOCATIONX][(jm[i].y) - MAPLOCATIONY] == 1 || !(item[(jm[i].x) - MAPLOCATIONX - 4][(jm[i].y) - MAPLOCATIONY - 2][0] == 0) || ((jm[i].x) == 4 + MAPLOCATIONX && (jm[i].y) == 2 + MAPLOCATIONY))
                i--;
        }

        for (i = 0; i < 8; i++)
        {
            gotoxy(jm[i].x, jm[i].y);
            printf("��\b\b");
        }
    }
    else
    {
        for (i = 0; i < difficulty - 1; i++)
        {
            jm[i].x = (rand() % ((difficulty * 16 - 4) / 2)) * 2 + 4 + MAPLOCATIONX;
            jm[i].y = rand() % (difficulty * 8 - 2) + 2 + MAPLOCATIONY;

            if (map_array[(jm[i].x) - MAPLOCATIONX][(jm[i].y) - MAPLOCATIONY] == 1 || !(item[(jm[i].x) - MAPLOCATIONX - 4][(jm[i].y) - MAPLOCATIONY - 2][0] == 0) || ((jm[i].x) == 4 + MAPLOCATIONX && (jm[i].y) == 2 + MAPLOCATIONY))
                i--;
        }

        for (i = 0; i < difficulty - 1; i++)
        {
            gotoxy(jm[i].x, jm[i].y);
            printf("��\b\b");
        }
    }
}

/*void custom_map(int difficulty, int map_array[][34], int custommap, int customwall) {
   int ix, iy, box, i;

   if (difficulty == 4)
      box = 100;
   else
      box = 25 * (difficulty - 1);

   for (ix = 0; ix < 68; ix++)
   {
      for (iy = 0; iy < 34; iy++)
         map_array[ix][iy] = 0;
   }

   for (ix = 0; ix < x * 16 + 4; ix++)
   {
      for (iy = 0; iy < x * 8 + 2; iy++)
      {
         if ((iy == 0) || (iy == 1))
            map_array[ix][iy] = 1;

         if ((ix == 0) || (ix == 1) || (ix == 2) || (ix == 3))
            map_array[ix][iy] = 1;

         if ((ix == x * 16) || (ix == x * 16 + 1) || (ix == x * 16 + 2) || (ix == x * 16 + 3))
            map_array[ix][iy] = 1;

         if ((iy == x * 8) || (iy == x * 8 + 1))
            map_array[ix][iy] = 1;
      }
   }

   while (box > 0)
   {
      while (box > 0)
      {
         ix = (rand() % ((x * 16 - 4) / 2)) * 2 + 4;//�������� ���� ��ġ�� �ʰ� �ּ� 2ĭ�� �ϳ��� ������
         iy = rand() % (x * 8 - 2) + 2;

         if (map_array[ix][iy] == 0 || !(ix == 4 && iy == 2))
         {
            map_array[ix][iy] = 1;
            map_array[ix + 1][iy] = 1;
            box--;
         }
      }

      for (ix = 0; ix < x * 16; ix++)
      {
         for (iy = 0; iy < x * 8; iy++)
         {
            if (map_array[ix][iy] == 0)
            {
               if (map_array[ix - 2][iy] == 1 && map_array[ix + 2][iy] == 1 && map_array[ix][iy + 1] == 1 && map_array[ix][iy - 1] == 1)
               {
                  if (iy == 2)
                     map_array[ix][iy + 1] = 0;
                  else
                     map_array[ix][iy - 1] = 0;
                  box++;
               }
            }
         }
      }
   }
}*/