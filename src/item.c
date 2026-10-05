#include <stdio.h>
#include "item.h"
#include "random.h"

static const char* ITEM_NONE_NAME = "(Empty Slot)";
static const char* ITEM_HEALTH_POTION_NAME = "Health Potion";
static const char* ITEM_UNKNOWN_NAME = "Unknown Item";

static const char* ITEM_NONE_DESCRIPTION = "An empty slot. No item is present.";
static const char* ITEM_HEALTH_POTION_DESCRIPTION = "A potion that restores 20 health points when used.";
static const char* ITEM_UNKNOWN_DESCRIPTION = "An unknown item with mysterious properties.";

static const int HEAL_AMOUNT = 20;

const char* item_get_name(const item type) {
    switch (type) {
        case ITEM_NONE:
            return ITEM_NONE_NAME;
        case ITEM_HEALTH_POTION:
            return ITEM_HEALTH_POTION_NAME;
        default:
            return ITEM_UNKNOWN_NAME;
    }
}

const char* item_get_description(const item type) {
    switch (type) {
        case ITEM_NONE:
            return ITEM_NONE_DESCRIPTION;
        case ITEM_HEALTH_POTION:
            return ITEM_HEALTH_POTION_DESCRIPTION;
        default:
            return ITEM_UNKNOWN_DESCRIPTION;
    }
}

int item_get_price(const item type) {
    switch (type) {
        case ITEM_NONE:
            return 0;
        case ITEM_HEALTH_POTION:
            return 10;
        default:
            return 0;
    }
}

item item_get_random(void) {
    return (item)(random_int(ITEM_NONE + 1, ITEM_LENGTH - 1));
}

void item_use(entity* user, const item it) {
    switch (it) {
        case ITEM_HEALTH_POTION:
        {
            const int actual_heal = entity_heal(user, HEAL_AMOUNT);
            printf("* You used a %s and restored %d health!\n", ITEM_HEALTH_POTION_NAME, actual_heal);
            break;
        }
        case ITEM_NONE:
        default:
            puts("* There is no item to use!");
            break;
    }
}