/*
	I pledge my honor that I have abided by the stevens honor system
	Nick Gattuso
*/

#include <stdio.h>
#include "SIdictLL.c"


void print(SIdict d) {
    nodePtr curr = d->head;

    while(curr != NULL) {
        printf("%s\t%d\n", curr->key, curr->val);
        curr = curr->next;
    }
}

int main(){
	SIdict dict = makeSIdict();
    addOrUpdate(dict, "First", 2);
    addOrUpdate(dict, "CS", 300);
    addOrUpdate(dict, "ISCOOL", 20);
    print(dict);
    addOrUpdate(dict, "CS", 135);
    print(dict);

    printf("%i\n", lookup(dict,"CS"));
    //prints out non-0 if it has key
    printf("%i\n", hasKey(dict,"Hello"));

    remKey(dict,"CS");
    print(dict);
    remKey(dict,"CS");
    print(dict);

}