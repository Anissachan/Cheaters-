#include "hashtable.h"
#include <iostream>
#include <vector>
#include <string>

void hashTable::hashFunction(string &word, int key) {
    int index = 0;
    int multiplier = 1;
    int num = 13;

    for(int i = 0 ; i< word.length(); i = i++){
        multiplier = num * multiplier;
        index = index + (word[i]*multiplier);
    }

    index = index%50003;

    HashNode* temp = new HashNode;
    temp ->value = key;

    if(table[index] == NULL){
        temp->next = NULL;
        table[index] = temp;
    }
    else{
        temp->next = table[index];
        table[index] = temp;
    }
}
