//
// Created by aniss on 12/3/2019.
//
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include "hashtable.h"
#include <queue>
#include <fstream>
#include <stdlib.h>

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main() {
    string dir = string("sm_doc_set");
    int n = 4;
    int limit = 200;
    hashTable* HashTable =  new hashTable();

    vector<string> files = vector<string>();
    getdir(dir, files);

    for (unsigned int i = 0; i < files.size(); i++) {

        if (files[i].substr(0, 1) == ".") {
            files.erase(files.begin() + i);
            i--;
        }
    }
    for (unsigned int i = 0; i < files.size(); i++) {
        cout << i << files[i] << endl;
    }

    ifstream file;

    for (int i = 0; i < files.size(); i++) {
        string filePtr = dir + '/' + files[i];
        file.open(filePtr.c_str());

        if (file.is_open()) {
            string word;
            vector<string> queue;

            while (!file.eof()) {
                while (queue.size() < n && !file.eof()) {
                    file >> word;
                    queue.push_back(word);
                }

                string pushString;

                for (int i = 0; i < queue.size(); i++) {
                    pushString = pushString + queue[i];
                }

                HashTable->hashFunction(pushString, i);
                queue.erase(queue.begin());
            }
        }
        else{
            cout<<"File not found";
            return 0;
        }
        file.close();

    }
    return 0;
}








