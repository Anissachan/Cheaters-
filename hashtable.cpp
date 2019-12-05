#include "hashtable.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

hashTable::hashTable() {

    for(int i=0; i<MAX_SIZE; i++){
        table[i] = NULL;
    }
    cout<<"Table Size : "<<table;
}

void hashTable::hashFunction(string &word, int fileIndex) {
    unsigned int index = 0;
    int multiplier = 1;
    for(int i = 0 ; i< word.length(); ++i){
        multiplier = multiplier * 5;
        index = index + (word[word.length()-i-1] * multiplier);
    }

    index = index % MAX_SIZE;

    HashNode* temp = new HashNode;
    temp ->value = fileIndex;


    if(table[index] == NULL){
        temp->next = NULL;
        table[index] = temp;
    }
    else{
        temp->next = table[index];
        table[index] = temp;
    }
}


