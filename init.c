#include "init.h"

void InitializePlayer(Player * P, int PlayerID)
{
    (*P).Gold = 0;
    (*P).Income = 0;
    (*P).PlayerID = PlayerID;
    (*P).Upkeep = 0;
    CreateEmptyBuilding(&(*P).Villages);
    CreateEmptyUnit(&(*P).Unit);
}
