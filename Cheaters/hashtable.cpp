#include <iostream>
#include <vector>
#include <string>
#include "hashtable.h"
#include "collisionMatrix.h"
#include <algorithm>

using namespace std;

hashTable::hashTable() {

	for(int i=0; i<MAX_SIZE; i++){
		table[i] = NULL;
	}
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

void hashTable::detectCollision(int numFiles, vector<string> &files, int minCollisions){

	collisionMatrix matrix(numFiles);

	for(int i=0; i<MAX_SIZE; i++){
		while(table[i] != NULL){
			HashNode* temp = table[i];
			int fileNumber = temp->fileIndex;

			while(temp != NULL){
				if (fileNumber != temp->fileIndex){
					matrix.increment(fileNumber, temp->fileIndex);
				}
				temp = temp->next;
			}
			temp = table[i];
			table[i] = table[i] ->next;
			delete(temp);
		}
	}

	vector<int> collisions;
	vector<string> rowFile;
	vector <string> colFile;
	for (int i = 0; i < files.size(); i++) {
		for (int j = 0; j < files.size(); j++) {
			if (matrix.getValue(i, j) > minCollisions) {
				collisions.push_back(matrix.getValue(i,j));
				rowFile.push_back(files.at(i));
				colFile.push_back(files.at(j));
			}
		}
	}
	sort(collisions.begin(), collisions.end(), greater<int>());


	vector<int>::iterator it = collisions.begin();
	vector<string>::iterator here = rowFile.begin();
	vector<string>::iterator there = colFile.begin();
	while(it != collisions.end()){
		cout << " " << *it << ": " << *here << ", " << "" << *there << endl;

		it++;
		here++;
		there++;

	}
}

hashTable::~hashTable(){
	for(int i=0; i<MAX_SIZE; i++){
		HashNode* temp = table[i];
		delete temp;
	}

}



