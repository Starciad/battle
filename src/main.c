#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main(void) {
    srand(time(NULL));

    game_start();
    
    return 0;
}