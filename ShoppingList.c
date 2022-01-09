
#define _CRT_SECURE_NO_WARNINGS
#include"ShoppingList.h"
#include<stdio.h>
#include<stdlib.h> // For malloc() and free()
#include <string.h>


void addItem(ShoppingList *list)
{
    list->length ++;
    
   // list->itemList = (GrocaryItem*)realloc(testVariable, sizeof(list)*list->length);
   
 list->itemList = (GrocaryItem*)realloc(list->itemList, sizeof(list)*list->length);
    
    
    if (list->itemList == NULL)
        printf("NO memory allocated");
    
    if (list->itemList != NULL) {
        
    
        
    
  
            // Here we input and store the grocery items in the correct places using pointers to save data storage
        int i;
        float amount;
        char name[20], unit[10];
        printf("Enter name: ");
        fgets(name, 20, stdin);
        for(i=0; name[i] != '\0'; i++)
            list->itemList[list->length].productName[i] = name[i];
        
        list->itemList[list->length].productName[i-1] = '\0'; // Remove the last character (byte) "enter" stored in the array
        
        
        do{
            printf("Enter amount: ");
            scanf("%f", &amount);
            
            if (amount <= 0)
                printf("Please enter a number larger than 0\n");
            
        } while(amount <=0);
        list->itemList[list->length].amount = amount;
        fgetc(stdin);
        
        
        
        printf("Enter unit: ");
        fgets(unit, 10, stdin);
        for(i=0; unit[i] != '\0'; i++)
            list->itemList[list->length].unit[i] = unit[i];
        
        list->itemList[list->length].unit[i-1] = '\0';
        
        
        printf("The length of the list is now %d", list->length);
        

        
}
}

void printList(ShoppingList *list)
{
    
    
    
    int i;
        
    
    
    if (list->length == 0)
        printf("Your list is empty.");
    else{
        printf("Your list contains %d items:\n", list->length);
        
        for(i=0; i<list->length; i++){
            printf("%d.\t", i+1);
            printf("%s", (char*) list->itemList[i].productName);
            printf("\t %.2f \t", list->itemList[i].amount);
            printf(" %s \n", (char*) list->itemList[i].unit);
        }
    }
    
}


void editItem(ShoppingList *list)
{
    int option;
    
    if (list->length == 0)
        printf("List is empty!");
    
    else{
        do{
            printf("Which item do you want to change? ");
            scanf("%d", &option);
            fgetc(stdin);
            
            if (option <=0 || option > list->length)
                printf ("The list only contains %d items!\n", list->length);
            
        }while(option <=0 || option > list->length);
        
        printf("Current amount: %.2f %s", list->itemList[option-1].amount, list->itemList[option-1].unit);
        printf("\nEnter new amount: ");
        scanf("%f", &(list->itemList[option-1].amount));
        printf("NEW %.2f", list->itemList[option-1].amount);
        
    }
}

void removeItem(ShoppingList *list)
{
    int removal, i;
    
    if (list->length == 0)
        printf("List is empty");
    else {
        
        do{
            printf("What item do you want to remove? ");
            scanf("%d", &removal);
            fgetc(stdin);
            
            if (removal <=0 || removal > list->length)
                printf ("The list only contains %d items!\n", list->length);
            
        }while(removal <=0 || removal > list->length);
        
        
        for (i=0; i < (list->length - removal); i++) {
            list->itemList[removal-1+i] = list->itemList[removal+i];
        }
        list->length--;
        printf("The list now contains %d items!", list->length);
        
    }
}

void saveList(ShoppingList *list)
{
    
    FILE *filePointer;
    char *fileName[10];
    
    printf("Choose a file name: ");
    scanf("%s", *fileName);
    
    filePointer = fopen(*fileName, "wb");
    
   
    if (filePointer != NULL) {
        
        fwrite(list->itemList, sizeof(list->itemList), list->length, filePointer);
        fwrite(&list->length, sizeof(int), 1, filePointer);
        
    fclose(filePointer);
    } else{
        printf("Couldn't open file.");
    }


}

void loadList( ShoppingList* list)
{
   
    char  fileName2[10];
    FILE *filePointer2;
    
    printf("What file do you want to open?");
    scanf("%s", *fileName2);
    
    filePointer2 = fopen(fileName2, "rb");
    
    if (filePointer2 != NULL) {
        
    

//        fread(list->length, sizeof(int), 1, filePointer2);
        
        fread(list->itemList, sizeof(list->itemList), list->length, filePointer2);
        
        
        
    } else{

        printf("File couldn't be found.");
        
}
 
}




