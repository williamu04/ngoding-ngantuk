#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct weapon
{
    char name[50];
    int price;
    int damage;
    int rounds;
} weapon;

typedef struct weaponNode
{
    struct weapon data;
    struct weaponNode *after;
    struct weaponNode *prev;
    struct weaponNode *next;
} weaponNode;

typedef struct weaponList
{
    struct weaponNode *first;
    struct weaponNode *last;    
} weaponList;

void insertweapon(struct weaponList *list, struct weaponNode *after, const struct weapon *data) {
    if (after != NULL) {

        struct weaponNode *newNode;

        newNode = (struct weaponNode *)malloc(sizeof(struct weaponNode));
        newNode->data = *data;
        newNode->prev = after; /* selaraskan rantai linked list */
        newNode->next = after->next; /* selaraskan rantai linked list */

        after->next = newNode;

        if (newNode->next == NULL) {
            list->last = newNode;
        } else {
            newNode->next->prev = newNode;
        }
    } else {

        struct weaponNode *newNode;

        newNode = (struct weaponNode *)malloc(sizeof(struct weaponNode));
        newNode->data = *data;
        newNode->prev = NULL; /* sesuai definisi, beri NULL apabila merupakan elemen pertama */
        newNode->next = list->first; /* selaraskan rantai linked list */

        list->first = newNode;

        if (list->last == NULL) {
            list->last = newNode;
        } else {
            newNode->next->prev = newNode;
        }
    }
}

void deleteweapon(struct weaponList *list, struct weaponNode *node) {
    if (list->first != NULL) {
        if (node == list->first) {

            struct weaponNode *oldNext;

            oldNext = list->first->next;

            free(list->first);

            list->first = oldNext;

            if (list->first == NULL) {
                list->last = NULL;
            } else {
                list->first->prev = NULL;
            }
        } else if (node == list->last) {

            struct weaponNode *oldPrev;

            oldPrev = list->last->prev;

            free(list->last);

            list->last = oldPrev;

            if (list->last == NULL) {
                list->first = NULL;
            } else {
                list->last->next = NULL;
            }
        } else {

            struct weaponNode *oldPrev, *oldNext;

            oldPrev = node->prev;
            oldNext = node->next;

            free(node);

            oldPrev->next = oldNext;
            oldNext->prev = oldPrev;
        }
    }
}

void printweapons(struct weaponList *list) {
    if (list->first != NULL) {
        struct weaponNode *iterator;

        for (iterator = list->first; iterator != NULL; iterator = iterator->next) {
            printf("weapon: %s ($: %d, %%: %d, n: %d)\n", iterator->data.name, iterator->data.price, iterator->data.damage, iterator->data.rounds);
        }
    } else {
        printf("(list is empty)\n");
    }
    printf("\n");
}

int main() {
    struct weaponNode *iterator;
    struct weaponList list;
    struct weapon wpn;

    list.first = NULL;
    list.last = NULL;

    strcpy(wpn.name, "Desert Eagle");
    wpn.price = 750;
    wpn.damage = 35;
    wpn.rounds = 7;
    insertweapon(&list, list.last, &wpn);

    strcpy(wpn.name, "M4A1");
    wpn.price = 3100;
    wpn.damage = 20;
    wpn.rounds = 30;
    insertweapon(&list, list.last, &wpn);

    strcpy(wpn.name, "H&K MP5");
    wpn.price = 1500;
    wpn.damage = 15;
    wpn.rounds = 30;
    insertweapon(&list, list.last, &wpn);

    strcpy(wpn.name, "AK-47");
    wpn.price = 2500;
    wpn.damage = 25;
    wpn.rounds = 30;
    insertweapon(&list, list.last, &wpn);

    printweapons(&list);

    printf("Menghapus elemen pertama...\n");
    deleteweapon(&list, list.first);
    printweapons(&list);

    printf("Menghapus elemen terakhir...\n");
    deleteweapon(&list, list.last);
    printweapons(&list);

    printf("Menambahkan AWP...\n");
    strcpy(wpn.name, "AWP Magnum");
    wpn.price = 4750;
    wpn.damage = 100;
    wpn.rounds = 10;
    insertweapon(&list, list.last, &wpn);
    printweapons(&list);

    printf("Menghapus senjata yang harganya lebih dari $3000...\n");
    iterator = list.first;
    while (iterator != NULL) {
        struct weaponNode *next;

        next = iterator->next;
        if (iterator->data.price > 3000) {
            deleteweapon(&list, iterator);
        }
        iterator = next;
    }
    printweapons(&list);

    printf("Menghapus elemen pertama...\n");
    deleteweapon(&list, list.first);
    printweapons(&list);

    return 0;
}