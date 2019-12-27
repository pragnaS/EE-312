#include <iostream>
#include <vector>
#include <string>

#ifndef CHEATER_HASHTABLE_H
#define CHEATER_HASHTABLE_H

using namespace std;

class hashTable{

    private:

        static const unsigned int MAX_SIZE = 50051;
        struct HashNode{
            int fileIndex;
            HashNode* next;
        };

        HashNode* table[MAX_SIZE];


    public:
        hashTable();
        void hashFunction(string &word, int fileIndex);
        void detectCollision(int numFiles, vector<string> &files, int minCollisions);
        ~hashTable();

};

#endif