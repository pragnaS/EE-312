//This is UtPodDriver.cpp
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(){

    cout<<"Making UT Pod"<<endl;
    UtPod utpod;
    cout<<"Made a UT Pod"<<endl<<endl;

    Song song1("Taylor Swift", "Archer", 4);
    Song song2("BTS", "Dream Glow", 4);
    Song song3("Pink Sweat$", "Honesty", 7);
    Song song4("Kanye West", "Closed on Sundays", 9);
    Song song5("", "", 0);
    Song song6("NIKI","lowkey", 5);
    Song song7("Illenium", "In Your Arms", 3);
    Song song8("Lizzo", "Tempo", 4);
    Song song9("Lil Nas X", "Old Town Road", 6);
    Song song10("Teresa Teng", "Tian MiMi", 8);
    Song song11("Daniel Caesar", "Best Part", 5);
    Song song12("Kiana Lede", "EX", 4);
    Song movie1("Disney Works", "The Little Mermaid", 320);
    Song movie2("Anissa and Pragna", "150 MB of Sadness", 150);

    int add=0, remove = 0;

    cout<<"Adding all songs "<<endl<<endl;

    add+=utpod.addSong(song1);
    add+=utpod.addSong(song2);
    add+=utpod.addSong(song3);
    add+=utpod.addSong(song4);
    add+=utpod.addSong(song6);
    add+=utpod.addSong(song7);
    add+=utpod.addSong(song8);
    add+=utpod.addSong(song9);
    add+=utpod.addSong(song10);
    add+=utpod.addSong(movie1);

    utpod.showSongList();


    cout<<"\nSONG : "<<movie2.getTitle()<<", "<<movie2.getArtist()<<", "<<movie2.getSize()<<" MB "<<endl;
    cout <<"testing if song is too big"<< endl;          //adding a song that will exceed 512
    add+=utpod.addSong(movie2);

    if(add < 0){
        cout << "\nthis song exceeds the size of remaining memory of UtPod" << endl;
        cout << "song is not added to list" << endl<<endl;
    }

    utpod.showSongList();

    cout<<"\nSONG : "<<song5.getTitle()<<", "<<song5.getArtist()<<", "<<song5.getSize()<<" MB "<<endl;
    cout <<"\ntesting if Song size is less than or equal to zero" << endl;
    add = 0;
    add+=utpod.addSong(song5);

    if(add < 0){
        cout << "\nthere wasn't a size to the song to be added" << endl;
    }

    utpod.showSongList();

    //remove song test cases

    cout << "\ntesting removing a song" << endl << endl;

    cout << "removing the first song" << endl;
    remove = utpod.removeSong(song1);

    if(remove == 0){
        cout << "the first song was successfully removed" << endl << endl;
    }

    utpod.showSongList();

    cout << "\nremoving a song in the middle of the list" <<endl<<endl;
    remove = utpod.removeSong(song6);

    if(remove == 0){
        cout << "successfully removed song from the center of the list" << endl << endl;
    }

    utpod.showSongList();

    cout << "\nremoving a song from the end of the list" << endl;
    remove = utpod.removeSong(movie1);

    if(remove == 0){
        cout << "successfully removed song from the end of the list" << endl<<endl;
    }

    utpod.showSongList();

    cout << "\nremoving a duplicate of a song" << endl;
    Song song13("Lizzo", "Tempo", 4);
    add += utpod.addSong(song13);
    utpod.showSongList();
    remove = utpod.removeSong(song13);

    if(remove == 0){
        cout << "\nsuccessfully removed a duplicate song" << endl<<endl;
    }

    utpod.showSongList();

    cout <<"\nremoving a song that doesn't exist" << endl;
    remove = utpod.removeSong(song1);

    if(remove < 0){
        cout << "\nsuccessfully didn't remove a song that doesn't exist" << endl;
    }

    utpod.showSongList();


    //testing shuffle
    cout << "\ntesting shuffle" << endl << endl;
    cout << "first shuffle" <<endl<<endl;
    utpod.shuffle();
    utpod.showSongList();

    cout << "\nshuffling again" << endl<<endl;
    utpod.shuffle();
    utpod.showSongList();

    //testing sort
    cout << "\ntesting sort" << endl << endl;
    utpod.sortSongList();
    utpod.showSongList();


}
