#include "init.h"

void InitializePlayer(Player * P, int PlayerID)
{
    (*P).Gold = 100;
    (*P).Income = 0;
    (*P).PlayerID = PlayerID;
    (*P).Upkeep = 0;
    CreateEmptyBuilding(&(*P).Villages);
    CreateEmptyUnit(&(*P).Unit);
}

void InitializeKata(Kata * Move, Kata * Undo, Kata * Change_Unit, Kata * Recruit, Kata * Attack,
                    Kata * Map, Kata * Info, Kata * End_Turn, Kata * Exit)
{
    (*Move).Length = 4;
    (*Move).TabKata[1] = 'M';
    (*Move).TabKata[2] = 'o';
    (*Move).TabKata[3] = 'v';
    (*Move).TabKata[4] = 'e';

    (*Undo).Length = 4;
    (*Undo).TabKata[1] = 'U';
    (*Undo).TabKata[2] = 'n';
    (*Undo).TabKata[3] = 'd';
    (*Undo).TabKata[4] = 'o';

    (*Change_Unit).Length = 11;
    (*Change_Unit).TabKata[1] = 'C';
    (*Change_Unit).TabKata[2] = 'h';
    (*Change_Unit).TabKata[3] = 'a';
    (*Change_Unit).TabKata[4] = 'n';
    (*Change_Unit).TabKata[5] = 'g';
    (*Change_Unit).TabKata[6] = 'e';
    (*Change_Unit).TabKata[7] = '_';
    (*Change_Unit).TabKata[8] = 'U';
    (*Change_Unit).TabKata[9] = 'n';
    (*Change_Unit).TabKata[10] = 'i';
    (*Change_Unit).TabKata[11] = 't';


    (*Recruit).Length = 7;
    (*Recruit).TabKata[1] = 'R';
    (*Recruit).TabKata[2] = 'e';
    (*Recruit).TabKata[3] = 'c';
    (*Recruit).TabKata[4] = 'r';
    (*Recruit).TabKata[5] = 'u';
    (*Recruit).TabKata[6] = 'i';
    (*Recruit).TabKata[7] = 't';


    (*Attack).Length = 6;
    (*Attack).TabKata[1] = 'A';
    (*Attack).TabKata[2] = 't';
    (*Attack).TabKata[3] = 't';
    (*Attack).TabKata[4] = 'a';
    (*Attack).TabKata[5] = 'c';
    (*Attack).TabKata[6] = 'k';

    (*Map).Length = 3;
    (*Map).TabKata[1] = 'M';
    (*Map).TabKata[2] = 'a';
    (*Map).TabKata[3] = 'p';

    (*Info).Length = 4;
    (*Info).TabKata[1] = 'I';
    (*Info).TabKata[2] = 'n';
    (*Info).TabKata[3] = 'f';
    (*Info).TabKata[4] = 'o';

    (*End_Turn).Length = 8;
    (*End_Turn).TabKata[1] = 'E';
    (*End_Turn).TabKata[2] = 'n';
    (*End_Turn).TabKata[3] = 'd';
    (*End_Turn).TabKata[4] = '_';
    (*End_Turn).TabKata[5] = 'T';
    (*End_Turn).TabKata[6] = 'u';
    (*End_Turn).TabKata[7] = 'r';
    (*End_Turn).TabKata[8] = 'n';

    (*Exit).Length = 4;
    (*Exit).TabKata[1] = 'E';
    (*Exit).TabKata[2] = 'x';
    (*Exit).TabKata[3] = 'i';
    (*Exit).TabKata[4] = 't';


}

