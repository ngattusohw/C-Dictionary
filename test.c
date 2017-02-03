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
    if((index = hasKey(d, key))) {
        for(i=1; i < index && node != NULL; ++i)
            node = node->next;
        node->val = val;
        //free mem
        return 1;
    }
    nodePtr temp = (nodePtr) malloc(sizeof(struct node));
    temp->key = key;
    temp->val = val;

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

void print(SIdict d) {
    nodePtr curr = d->head;

    while(curr != NULL) {
        printf("%s\t%d\n", curr->key, curr->val);
        curr = curr->next;
    }
}

int main() {
    SIdict dict = makeSIdict();
    addOrUpdate(dict, "lmao", 2);
    addOrUpdate(dict, "blah", 300);
    addOrUpdate(dict, "lmao", 20);
    print(dict);
}
