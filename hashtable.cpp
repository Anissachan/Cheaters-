#include <iostream>
#include <vector>
#include <string>
#include "hashtable.h"
#include "collisionMatrix.h"

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
    temp ->fileIndex = fileIndex;


    if(table[index] == NULL){
        temp->next = NULL;
        table[index] = temp;
    }
    else{
        temp->next = table[index];
        table[index] = temp;
    }
}

    int* hashTable::detectCollision(int numFiles, vector<string> &files){

        collisionMatrix matrix(numFiles);

        for(int i=0; i<MAX_SIZE; i++){
            while(table[i] != NULL){
            HashNode* temp = table[i];
            int fileNumber = temp->fileIndex;

            while(temp != NULL){
                if (fileNumber != NULL){
                    matrix.increment(fileNumber, temp->fileIndex);
                }
                temp = temp->next;
            }
            temp = table[i];
            table[i] = table[i] ->next;
            delete(temp);
        }
    }
}








