#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdbool.h>
#include "item.h"

extern const int INVENTORY_CAPACITY;

typedef struct inventory {
    item items[10];
} inventory;

extern int inventory_count_items(const inventory* inv);
extern int inventory_get_item_index(const inventory* inv, const item it);

extern bool inventory_add_item(inventory* inv, const item it);
extern bool inventory_remove_item(inventory* inv, const item it);

extern void inventory_clear(inventory* inv);
extern void inventory_print(const inventory* inv);

#endif // INVENTORY_H