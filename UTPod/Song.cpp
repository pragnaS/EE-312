//This is Song.cpp

#include "Song.h"

using namespace std;

Song::Song(){
    artist = "NO NAME";
    title = "NO TITLE";
    size = DEFAULT_SIZE;
}
Song::Song(string _artist, string _title, int _size){
    artist = _artist;
    title = _title;
    size = _size;
}

string Song::getArtist(){
    return artist;
}

string Song::getTitle(){
    return title;
}

int Song::getSize() const {
    return size;
}
void Song::setArtist(string _artist){
    artist = _artist;
}

void Song::setTitle(string _title){
    title = _title;
}

void Song::setSize(int _size){
    size = _size;
}

bool Song::operator >(Song const &rhs){
    if(artist > rhs.artist)
        return true;
    if((artist == rhs.artist) && (title > rhs.title))
        return true;
    return (artist == rhs.artist) && (title == rhs.title) && (size > rhs.size);

}

bool Song::operator <(Song const &rhs){
    if(artist < rhs.artist)
        return true;
    if((artist == rhs.artist) && (title < rhs.title))
        return true;
    return ((artist == rhs.artist) && (title == rhs.title) && (size<rhs.size));
}

bool Song::operator ==(Song const &rhs){
    return ((artist == rhs.artist) && (title == rhs.title) && (size == rhs.size));
}



