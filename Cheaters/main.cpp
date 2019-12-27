//
// Created by aniss on 12/3/2019.
//
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include <stdlib.h>
#include "collisionMatrix.h"
#include "hashtable.h"


using namespace std;

int* detectCollision(int numFiles, vector<string> &files, collisionMatrix matrix);


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


int main(int argc, char* argv[]) {
    string dir = argv[1];
    int n = atoi(argv[2]);
    int limit = atoi(argv[3]);

    hashTable* HashTable =  new hashTable();

    vector<string> files = vector<string>();
    getdir(dir, files);
    ifstream file;

    for (unsigned int i = 0; i < files.size(); i++) {

        if (files[i].substr(0, 1) == ".") {
            files.erase(files.begin() + i);
            i--;
        }
    }

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

                for (int j = 0; j < queue.size(); j++) {
                    pushString = pushString + queue[j];
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

    HashTable->detectCollision(files.size(), files, limit);
    return 0;
}









