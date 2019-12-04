#include "hashtable.h"
#include <iostream>
#include <vector>
#include <string>

void hashTable::hashFunction(string &word, int key) {
    int index = 0;
    int multiplier = 1;
    for(int i = 0 ; i< word.length(); i+=2){
        multiplier = multiplier * 5;
        index = index + (word[word.length()-i-1] * multiplier);
    }

    index = index % 50051;

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

