//This is UtPod.cpp

#include "Song.h"
#include "UtPod.h"
#include<iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>

using namespace std;

UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
    unsigned int currentTime =  (unsigned)time(0);          //random number generator
    srand(currentTime);                                     //seed the random number generator
}


UtPod::UtPod(int size) {
    if((size>MAX_MEMORY) || (size<0))
        memSize = MAX_MEMORY;
    else memSize = size;

    songs = NULL;
    unsigned int currentTime =  (unsigned)time(0);          //random number generator
    srand(currentTime);                                     //seed the random number generator
}


int UtPod::addSong(Song const &s){
    if(s.getSize()>getRemainingMemory() || s.getSize()<=0 )
        return NO_MEMORY;
    SongNode* temp = new SongNode;
    temp->s = s;
    temp->next = NULL;

    if(songs == NULL){      //if there are no songs in the list, add the song to the head of the list
        songs = temp;
    }
    else {                  //if the list isn't empty, traverse to the end of the list and add the new song at the tail
        SongNode *traverse = songs;
        while(traverse->next != NULL){
            traverse = traverse -> next;
        }
        traverse->next = temp;
    }
    return SUCCESS;
}


int UtPod::removeSong(Song const &s){
    if (songs == NULL){
        return NOT_FOUND;
    }
    SongNode* trail = songs;
    if(trail->s == s){      //if the song is the first song in the list, then set the head to the head's next pointer
       songs = trail ->next;
       delete trail;
    }
    else {
        SongNode *deleteSong = songs->next;
        while (!(deleteSong->s == s)) {
            deleteSong = deleteSong->next;
            trail = trail->next;
            if (deleteSong == NULL) {
                return NOT_FOUND;
            }
        }
        trail->next = deleteSong->next;
        delete deleteSong;
    }
    return SUCCESS;
}


void UtPod::swap(Song &s1, Song &s2){
    SongNode* temp1 = songs;
    SongNode* temp2 = songs;
    Song temp;

    while(!(temp1->s == s1)){
        temp1 = temp1->next;
    }
    while(!(temp2->s == s2)){
        temp2 = temp2->next;
    }

    temp = temp1 -> s;
    temp1->s = temp2 -> s;
    temp2 -> s = temp;

}


void UtPod::showSongList(){
    SongNode* traverse = songs;
    while(traverse != NULL){
        cout<<(traverse->s).getTitle()<<", "<<(traverse->s).getArtist()<<", "<<(traverse->s).getSize()<<" MB "<<endl;
        traverse = traverse ->next;
        }
    delete traverse;
}


void UtPod::clearMemory(){
    SongNode* p1 = songs;
    while(p1!=NULL){
        removeSong(p1->s);
        p1 = p1->next;
    }
}


void UtPod::sortSongList(){
    SongNode* p1 = songs;
    SongNode* p2 = songs;

    while(p1 != NULL){
        p2 = p1;
        while(p2 != NULL){
            if((p1 -> s) > (p2 -> s)){
                swap(p1->s, p2->s);
            }
            p2 = p2->next;
        }
        p1 = p1 -> next;
    }
}


int UtPod::getRemainingMemory(){
    int remMem = memSize;
    SongNode *p1 = songs;
    while(p1!=NULL){
        remMem = remMem - ((p1->s).getSize());
        p1 = p1->next;
    }
    return remMem;
}

UtPod::~UtPod() {
    clearMemory();
    delete songs;
}

void UtPod::shuffle(){
    int numSongs = countSongs();
    if(numSongs<2)
        return;

    for(int i=0; i<numSongs; i++){
        int index1 = rand() % numSongs;
        int index2 = rand() % numSongs;

        SongNode* temp1 = songs;
        SongNode* temp2 = songs;

        while(index1>0){                //generating pointers to the random song nodes
            temp1 = temp1->next;
            index1--;
        }
        while(index2>0){
            temp2 = temp2->next;
            index2--;
        }
        swap(temp1->s, temp2->s);
    }
}

int UtPod::countSongs() {
    int numSongs = 0;
    SongNode* traverse = songs;
    while(traverse!=NULL){
        numSongs++;
        traverse=traverse->next;
    }
    return numSongs;
}




