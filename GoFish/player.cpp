#include "player.h"
#include "card.h"
#include "deck.h"
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

Player::Player() {
    myName = "";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    vector<Card>::iterator i1, i2;
    for (i1 = myHand.begin(); i1 != myHand.end(); i1++){
        if (*i1 == c1){
            myBook.push_back(c1);
            myHand.erase(i1);
            break;
        }
    }
    for (i2 = myHand.begin(); i2 != myHand.end(); i2++){
        if (*i2 == c2){
            myBook.push_back(c2);
            myHand.erase(i2);
            break;
        }
    }
}


Card Player::removeCardFromHand(Card c) {
    Card temp;
    vector<Card>::iterator i;
    i = find(myHand.begin(), myHand.end(), c);
    temp = *i;
    myHand.erase(i);
    return temp;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

string Player::showHand() const {
    string hand;
    for(int i=0; i<myHand.size(); i++){
        hand = hand + myHand[i].toString() + " ";
    }
    return hand;
}

bool Player::sameRankInHand(Card c) const {
    for(int i=0; i<myHand.size(); i++){
        if(c.getRank() == myHand[i].getRank()){
            return true;
        }
    }
    return false;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    Card _c1, _c2;

    for(int i = 0; i< myHand.size(); i++){
        _c1 = myHand.at(i);
        for(int j = i+1; j<myHand.size(); j++){
            _c2 = myHand.at(j);
            if(_c1.getRank() == _c2.getRank()){
                c1 = _c1;
                c2 = _c2;
                return true;
            }
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    srand(time(NULL));
    return myHand.at((rand() % getHandSize()));
}

bool Player::cardInHand(Card c) const {
    for(int i=0; i<myHand.size(); i++){
        if(myHand[i] == c)
            return true;
    }

    return false;
}

string Player::showBooks() const {
    vector<Card>::const_iterator i;
    string output;
    for(i=myBook.begin(); i!=myBook.end(); i++){
        output = output + (*i).toString() + " ";
    }
    return output;
}

Card Player::getSameCard(Card c) const{
    for(int i=0; i<myHand.size(); i++){
        if(c.getRank() == myHand[i].getRank()){
            return myHand[i];
        }
    }
}

