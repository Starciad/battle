#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>

extern const int ATTACK_RANGE;

typedef struct entity {
    int base_attack;
    int coins;
    int critical_chance;
    int current_health;
    int defense;
    int maximum_health;
    bool is_defending;
    bool is_preparing_attack;
} entity;

typedef enum entity_attack_value_type {
    ENTITY_ATTACK_VALUE_MINIMUM = 0,
    ENTITY_ATTACK_VALUE_MAXIMUM = 1,
    ENTITY_ATTACK_VALUE_RANDOM = 2,
    ENTITY_ATTACK_VALUE_CRITICAL_HIT = 3,
    ENTITY_ATTACK_VALUE_POWERFUL = 4,
} entity_attack_value_type;

extern int entity_get_attack_value(const entity *e, const entity_attack_value_type type);
extern int entity_heal(entity *e, const int heal_amount);
extern int entity_take_damage(entity *e, const int damage);

extern bool entity_is_alive(const entity *e);
extern bool entity_is_critical_hit(const entity *e);

#endif // ENTITY_H