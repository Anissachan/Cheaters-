#include <iostream>
#include <vector>
#include <string>

using namespace std;

class hashTable{

    private:
        struct HashNode{
            int value;
            HashNode* next;
        };

    public:
        hashTable();
        void hashFunction(string &word, int key);
        int* detectCollision(int numFiles, vector<string> &files);
        ~hashTable();

};
