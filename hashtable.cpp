#include "hashtable.h"
#include <iostream>
#include <vector>
#include <string>

void hashTable::hashFunction(string &word, int key) {
    int index = 0;
    int multiplier = 5;
    int num = 13;
    
    for(int i = 0; i < (MAXSIZE - 1); i++){
        index = (MAXSIZE - i - 1)*pow(37,i);
    }
    

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
