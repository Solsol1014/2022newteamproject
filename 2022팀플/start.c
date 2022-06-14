#include "gameplay.h"

void start(void)
{
    int a, b;
    char ch;
    a = MAPLOCATIONX;
    b = MAPLOCATIONY;

    gotoxy(a, b); b++;
    printf("                 .\" - , .__\n"); gotoxy(a, b); b++;
    printf("                 `.     `.  ,\n"); gotoxy(a, b); b++;
    printf("              .--'  .._,'\" - ' `.\n"); gotoxy(a, b); b++;
    printf("             .    .'         `'\n"); gotoxy(a, b); b++;
    printf("             `.   /          ,'\n"); gotoxy(a, b); b++;
    printf("               `  '--.   ,-\"'\n"); gotoxy(a, b); b++;
    printf("                `\"` | ＼\n"); gotoxy(a, b); b++;
    printf("                   -. ＼, |\n"); gotoxy(a, b); b++;
    printf("                    `--Y.'      ___.\n"); gotoxy(a, b); b++;
    printf("                         ＼     L._, ＼\n"); gotoxy(a, b); b++;
    printf("               _.,        `.    <  <＼                _\n"); gotoxy(a, b); b++;
    printf("            ,' '           `,   `.   | ＼            ( `\n"); gotoxy(a, b); b++;
    printf("         ../, `.            `    |    .＼`.           ＼ ＼_\n"); gotoxy(a, b); b++;
    printf("        ,' ,..  .             _.,'    ||＼l            )  '\".\n"); gotoxy(a, b); b++;
    printf("       , ,'   ＼            , '.-.`-._,'  |           .  _._`.\n"); gotoxy(a, b); b++;
    printf("     ,' /      ＼ ＼         `' ' `--/   | ＼          / /   ..＼\n"); gotoxy(a, b); b++;
    printf("    .'  /        ＼ .          |＼__ - _ ,'` `        / /     `.`.\n"); gotoxy(a, b); b++;
    printf("    |  '          ..           `-...-\" | `-'       / /        . `.\n"); gotoxy(a, b); b++;
    printf("    | /           |L__           |     |          / /         `. `.\n"); gotoxy(a, b); b++;
    printf("   , /            .   .          |     |         / /            ` `\n"); gotoxy(a, b); b++;
    printf("  / /          ,. ,`._ `-_       |     |  _   ,-' /              ` ＼\n"); gotoxy(a, b); b++;
    printf(" / .           ＼\"`_/. `-_ ＼_,.  ,'    +-' `-'  _,       ..,-.   ＼`.\n"); gotoxy(a, b); b++;
    printf(".  '         .-f    ,'   `    '.       ＼__.---'     _   .'   '    ＼＼\n"); gotoxy(a, b); b++;
    printf("' /          `.'    l     .' /          \..      ,_|/   `.  ,'`      L`\n"); gotoxy(a, b); b++;
    printf("|'      _.-\"\"` `.    ＼ _,'  `            \ `.___`.'\"`-., |   |      | ＼\n"); gotoxy(a, b); b++;
    printf("||    ,'       `. `.   '       _,...._        `  |    `/ '  |   '     .|\n"); gotoxy(a, b); b++;
    printf("||  ,'           `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n"); gotoxy(a, b); b++;
    printf("|| '               V      / /           `   | `   ,'   ,' '.    !  `. ||\n"); gotoxy(a, b); b++;
    printf("||/             _,-------7 '              . |  `-'    l         /    `||\n"); gotoxy(a, b); b++;
    printf(". |           ,' .-   ,' ||               | .-.        `.      .'     ||\n"); gotoxy(a, b); b++;
    printf(" `'         ,'    `\".'    |               |    `.        '. - .'       `'\n"); gotoxy(a, b); b++;
    printf("           /      ,'      |               |,'    ＼-.._,.'/'\n"); gotoxy(a, b); b++;
    printf("           .     /        .               .       ＼    .''\n"); gotoxy(a, b); b++;
    printf("         .`.    |         `.             /         :_,'.'\n"); gotoxy(a, b); b++;
    printf("           ＼ `...＼   _     ,'-.        .'         /_.-'\n"); gotoxy(a, b); b++;
    printf("            `-.__ `,  `'   .  _.>----''.  _  __   /\n"); gotoxy(a, b); b++;
    printf("                 .'        /\"'          |  \"'   '_\n"); gotoxy(a, b); b++;
    printf("                /_|.-'＼ ,\".             '.'`__'-(＼\n"); gotoxy(a, b); b++;
    printf("                  / ,\"'\"＼,'               `/  `-. | \" m\n\n"); gotoxy(a, b); b++;

    while (1) {
        gotoxy(a, b);
        printf("                        Press Any Key To Start");
        Sleep(400);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                      \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        Sleep(100);
        if (_kbhit()) {
            system("cls");
            ch = _getch();
            break;
        }
    }
}

void description1(void)
{
    char ch;
    int a, b;
    b = 10;

    printf(" ######            ###                                                   ##   ##                      ##\n");
    printf("  ##  ##            ##                                                   ##   ##                      ##\n");
    printf("  ##  ##   ####     ##  ##   ####    ##  ##    ####    #####             ##   ##  ##  ##   #####     #####    ####    ######\n");
    printf("  #####   ##  ##    ## ##   ##  ##   #######  ##  ##   ##  ##            #######  ##  ##   ##  ##     ##     ##  ##    ##  ##\n");
    printf("  ##      ##  ##    ####    ######   ## # ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ##     ######    ##\n");
    printf("  ##      ##  ##    ## ##   ##       ##   ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ## ##  ##        ##\n");
    printf(" ####      ####     ##  ##   #####   ##   ##   ####    ##  ##            ##   ##   ####    ##  ##      ###    #####   ####\n");
    gotoxy(10, b);
    printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");

    a = 100;
    b = 15;
    gotoxy(15, b);
    printf("\"헐 리자몽...\"");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("SNS에서 포켓몬빵이 재출시를 했다는 소식을 봤을 무렵, 친구가 포켓몬빵을 구한 사진을 보게되었다.");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("그 사진에는 어릴 적 그렇게도 갖고 싶었던 리자몽 띠부띠부씰이 있었고,");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("그 순간 나는 포켓몬빵을 구해 나도 리자몽을 갖고 말겠다는 원대한 목표를 세우게 되었다.");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("문제는 잼민이들. 내가 가지고 있는 정보들을 잼민이들에게 들킨다면 포켓몬빵을 빼앗길 것이 분명했다.");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("어떻게든 잼민이들에게 걸리지 않고 포켓몬빵이 있는 편의점까지 도달해야한다.");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("\"좋아 가보는거야! 할 수 있어!\"");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("잼민이들과 여러 난관들을 해치고... 과연 포켓몬빵을 얻을 수 있을 것인가?!");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("PRESS ANY KEY TO START");
    b++;

    ch = _getch();
}

void description2(void)
{
    char ch;
    int a, b;
    b = 10;

    printf(" ######            ###                                                   ##   ##                      ##\n");
    printf("  ##  ##            ##                                                   ##   ##                      ##\n");
    printf("  ##  ##   ####     ##  ##   ####    ##  ##    ####    #####             ##   ##  ##  ##   #####     #####    ####    ######\n");
    printf("  #####   ##  ##    ## ##   ##  ##   #######  ##  ##   ##  ##            #######  ##  ##   ##  ##     ##     ##  ##    ##  ##\n");
    printf("  ##      ##  ##    ####    ######   ## # ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ##     ######    ##\n");
    printf("  ##      ##  ##    ## ##   ##       ##   ##  ##  ##   ##  ##            ##   ##  ##  ##   ##  ##     ## ##  ##        ##\n");
    printf(" ####      ####     ##  ##   #####   ##   ##   ####    ##  ##            ##   ##   ####    ##  ##      ###    #####   ####\n");
    gotoxy(10, b);
    printf("┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("│                                                                                                        │\n");
    b++;
    gotoxy(10, b);
    printf("└────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");

    a = 1000;
    b = 15;
    gotoxy(15, b);
    printf("\"헐 리자몽...\"");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("SNS에서 포켓몬빵이 재출시를 했다는 소식을 봤을 무렵, 친구가 포켓몬빵을 구한 사진을 보게되었다.");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("그 사진에는 어릴 적 그렇게도 갖고 싶었던 리자몽 띠부띠부씰이 있었고,");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("그 순간 나는 포켓몬빵을 구해 나도 리자몽을 갖고 말겠다는 원대한 목표를 세우게 되었다.");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("문제는 잼민이들. 내가 가지고 있는 정보들을 잼민이들에게 들킨다면 포켓몬빵을 빼앗길 것이 분명했다.");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("어떻게든 잼민이들에게 걸리지 않고 포켓몬빵이 있는 편의점까지 도달해야한다.");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("\"좋아 가보는거야! 할 수 있어!\"");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("잼민이들과 여러 난관들을 해치고... 과연 포켓몬빵을 얻을 수 있을 것인가?!");
    b++;
    b++;
    Sleep(a);
    gotoxy(15, b);
    printf("PRESS ANY KEY TO START");
    b++;

    ch = _getch();
}