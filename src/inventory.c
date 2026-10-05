#include <stdio.h>
#include "inventory.h"

const int INVENTORY_CAPACITY = 10;

static void inventory_sort_items(inventory* inv) {
    // Simple bubble sort for demonstration purposes
    for (int i = 0; i < INVENTORY_CAPACITY - 1; i++) {
        for (int j = 0; j < INVENTORY_CAPACITY - i - 1; j++) {
            if (inv->items[j] < inv->items[j + 1]) { // Descending order
                item temp = inv->items[j];
                inv->items[j] = inv->items[j + 1];
                inv->items[j + 1] = temp;
            }
        }
    }
}

static int inventory_get_empty_slot_index(const inventory* inv) {
    for (int i = 0; i < INVENTORY_CAPACITY; i++) {
        if (inv->items[i] == ITEM_NONE) { // Assuming ITEM_NONE indicates an empty slot
            return i;
        }
    }
    return -1; // Inventory full
}

int inventory_count_items(const inventory* inv) {
    int count = 0;

    for (int i = 0; i < INVENTORY_CAPACITY; i++) {
        if (inv->items[i] != ITEM_NONE) {
            count++;
        }
    }

    return count;
}

int inventory_get_item_index(const inventory* inv, const item it) {
    for (int i = 0; i < INVENTORY_CAPACITY; i++) {
        if (inv->items[i] == it) {
            return i;
        }
    }

    return -1; // Item not found
}

bool inventory_add_item(inventory* inv, const item it) {
    int index = inventory_get_empty_slot_index(inv);

    if (index != -1) {
        inv->items[index] = it;
        inventory_sort_items(inv);
        return true;
    }

    return false;
}

bool inventory_remove_item(inventory* inv, const item it) {
    int index = inventory_get_item_index(inv, it);

    if (index != -1) {
        inv->items[index] = ITEM_NONE; // Mark the slot as empty
        inventory_sort_items(inv);
        return true;
    }

    return false;
}

void inventory_clear(inventory* inv) {
    for (int i = 0; i < INVENTORY_CAPACITY; i++) {
        inv->items[i] = ITEM_NONE;
    }
}

void inventory_print(const inventory* inv) {
    for (int i = 0; i < INVENTORY_CAPACITY; i++) {
        if (inv->items[i] == ITEM_NONE) {
            printf("  - %02d. (empty slot)\n", i + 1);
        } else {
            printf("  - %02d. %s | %s\n", i + 1, item_get_name(inv->items[i]), item_get_description(inv->items[i]));
        }
    }
}