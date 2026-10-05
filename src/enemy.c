#include "enemy.h"
#include "random.h"

entity enemy_create(int challenge_level) {
    const int health = random_int(1, 5) + challenge_level * 2;

    return (entity) {
        .coins = (challenge_level * 2) + random_int(1, 5),
        .base_attack = challenge_level,
        .critical_chance = challenge_level + random_int(1, 5),
        .current_health = health,
        .defense = challenge_level - 1,
        .maximum_health = health,
        .is_defending = false,
        .is_preparing_attack = false,
    };
}
