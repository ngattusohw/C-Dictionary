#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "SIdict.h"

void print(SIdict d);

typedef struct node* nodePtr;
struct node {
    char* key;
    int val;
    nodePtr next;
};

struct si_dict {
    nodePtr head;
};

SIdict makeSIdict() {
    SIdict dict = (SIdict) malloc(sizeof(struct si_dict));
    dict->head = NULL;
    return dict;
}

int hasKey(SIdict d, char* key) {
    int index = 1;
    nodePtr curr = d->head;

    while(curr != NULL) {
        if(strcmp(key, curr->key) == 0)
            return index;
        curr = curr->next;
        ++index;
    }

    return 0;
}

int addOrUpdate(SIdict d, char* key, int val) {
    int i, index;
    nodePtr node = d->head;
    //if it has, update
    if((index = hasKey(d, key))) {
        for(i=1; i < index && node != NULL; ++i)
            node = node->next;
        node->val = val;
        //free mem
        return 1;
    }
    //if it doesnt, make a new node
    nodePtr temp = (nodePtr) malloc(sizeof(struct node));
    temp->key = key;
    temp->val = val;

    //if the list dict is initally empty
    if(d->head == NULL) {
        node = NULL;
    }
    else {
        node = d->head;
    }

    d->head = temp;
    temp->next = node;

    return 0;
}

/* A function to print out the whole dictionary */
void print(SIdict d) {
    nodePtr curr = d->head;

    while(curr != NULL) {
        printf("%s\t%d\n", curr->key, curr->val);
        curr = curr->next;
    }
}

int lookup(SIdict d, char* key){
    nodePtr curr = d->head;
    while(curr != NULL){
        if(strcmp(key, curr->key) == 0){
            return curr->val;
        }
        curr = curr->next;
    }

    return -1;
}

int remKey(SIdict d, char* key){
    nodePtr curr = d->head;
    nodePtr hold;

    while(curr != NULL){
        if(strcmp(key, curr->key) == 0){
            //remove the node from the linked list
            hold->next = curr->next;
            curr->next = NULL;
            //curr->val = NULL;
            curr->key = NULL;
            return 1;
        }

        hold = curr;
        curr = curr->next;
        
    }

    return 0;
}

int main() {
    SIdict dict = makeSIdict();
    addOrUpdate(dict, "lmao", 2);
    addOrUpdate(dict, "blah", 300);
    addOrUpdate(dict, "penis", 20);
    print(dict);
    printf("%i\n" , lookup(dict, "lmao"));
    printf("%i\n" , lookup(dict, "penis"));
    printf("%i\n" , lookup(dict, "ass"));

    printf("%i\n" , remKey(dict, "lmao"));
    print(dict);
}
