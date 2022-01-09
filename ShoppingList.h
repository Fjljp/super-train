#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H


    // Struct definitions

struct GrocaryItem
{
    char productName[20];
    float amount;
    char unit[10];
};
typedef struct GrocaryItem GrocaryItem;

struct ShoppingList
{
    int length;
    GrocaryItem *itemList;  // Changed to a pointer to be able to use a dynamic array
};
typedef struct ShoppingList ShoppingList;
    // Function declarations


void addItem( ShoppingList *list);
void printList( ShoppingList *list);
void editItem( ShoppingList *list);
void removeItem( ShoppingList *list);
void saveList( ShoppingList *list);
void loadList( ShoppingList* list);




#endif
