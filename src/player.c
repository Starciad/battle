#include "player.h"

entity player_create(void) {
    return (entity) {
        .coins = 0,
        .base_attack = 1,
        .critical_chance = 10,
        .current_health = 10,
        .defense = 0,
        .maximum_health = 10,
        .is_defending = false,
        .is_preparing_attack = false,
    };
}
