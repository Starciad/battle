#ifndef ITEM_H
#define ITEM_H

#include "entity.h"

typedef enum item {
    // No Item
    ITEM_NONE = 0,

    // Consumables
    ITEM_HEALTH_POTION,

    // System
    ITEM_LENGTH
} item;

extern const char* item_get_name(const item type);
extern const char* item_get_description(const item type);
extern int item_get_price(const item type);
extern item item_get_random(void);
extern void item_use(entity* user, const item it);

#endif // ITEM_H