#include "entity.h"
#include "random.h"

const int ATTACK_RANGE = 3;

static int clamp_attack_value(const int value) {
    if (value <= 0) {
        return 1;
    } else {
        return value;
    }
}

int entity_get_attack_value(const entity *e, const entity_attack_value_type type) {
    int value = 0;

    switch (type) {
        case ENTITY_ATTACK_VALUE_MINIMUM:
            value = e->base_attack - ATTACK_RANGE;
            break;
        case ENTITY_ATTACK_VALUE_MAXIMUM:
            value = e->base_attack + ATTACK_RANGE;
            break;
        case ENTITY_ATTACK_VALUE_RANDOM:
            value = random_int(
                entity_get_attack_value(e, ENTITY_ATTACK_VALUE_MINIMUM),
                entity_get_attack_value(e, ENTITY_ATTACK_VALUE_MAXIMUM)
            );
            break;
        case ENTITY_ATTACK_VALUE_CRITICAL_HIT:
            value = (entity_get_attack_value(e, ENTITY_ATTACK_VALUE_RANDOM) + 1) * 2;
            break;
        case ENTITY_ATTACK_VALUE_POWERFUL:
            value = (entity_get_attack_value(e, ENTITY_ATTACK_VALUE_MAXIMUM) / 2) +
                    entity_get_attack_value(e, ENTITY_ATTACK_VALUE_CRITICAL_HIT);
            break;
        default:
            value = e->base_attack;
            break;
    }

    return clamp_attack_value(value);
}

int entity_heal(entity *e, const int heal_amount) {
    int actual_heal = heal_amount;

    if (e->current_health + heal_amount > e->maximum_health) {
        actual_heal = e->maximum_health - e->current_health;
        e->current_health = e->maximum_health;
    } else {
        e->current_health += heal_amount;
    }

    return actual_heal;
}

// Returns the actual damage taken after defense calculations
int entity_take_damage(entity *e, const int damage) {
    int value = damage;

    // If the entity is defending, the damage is halved.
    if (e->is_defending) {
        value /= 2;
        e->is_defending = false; // Reset defending status after taking damage
    }

    // Reduce damage considering the current defense value.
    value -= e->defense;

    // Clamp the damage value. If it is less than 0, it will be converted to 1.
    value = clamp_attack_value(value);

    // Subtract the damage from current health
    if (value >= e->current_health) {
        e->current_health = 0;
    } else {
        e->current_health -= value;
    }

    return value;
}

bool entity_is_alive(const entity *e) {
    return e->current_health > 0;
}

bool entity_is_critical_hit(const entity *e) {
    return random_int(1, 100) <= e->critical_chance;
}
