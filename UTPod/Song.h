//This is Song.h
#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

class Song{

    private:
        string artist;
        string title;
        int size;

        static const int DEFAULT_SIZE = 0;

    public:

        Song();

        Song(string _artist, string _title, int _size);

        //This function sets the name of the artist of the song
        //Input parameter: name of the artist
        void setArtist(string _artist);

        //This function sets the title of the song
        void setTitle(string _title);

        //This function sets the memory size of the song
        void setSize(int _size);

        //This function returns the name of the artist of the song
        string getArtist();

        //This function returns the title of the song
        string getTitle();

        //This function returns the memory size of the song
        int getSize() const;

        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        bool operator ==(Song const &rhs);

        //~Song();
};


#endif
