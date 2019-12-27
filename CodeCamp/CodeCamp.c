#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>


// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Pragna Subrahmanya, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Pragna Subrahmanya
 * email address: pragnals@utexas.edu
 * UTEID: ps28338
 * Section 5 digit ID: 16025
 *
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
    int hamming_dist=0;

    for(int i=0; i<len; i++){
        if(aList[i] != bList[i])
            hamming_dist++;
    }

    return hamming_dist;

}


/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {

  int num1_lastDigit = 0;
  int num2_lastDigit = 0;

  if(num1<0)
      num1 = -1*num1;
  if(num2<0)
      num2 = -1*num2;

    num1_lastDigit = num1 % 10;
    num2_lastDigit = num2 % 10;

    if(num1_lastDigit == num2_lastDigit)
        return 1;
    else
        return 0;





}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {
    int sum = 0;
    for(int i=1; i<1000; i++){
        if(i % 3 == 0 || i % 5 == 0)
            sum = sum + i;
    }
    return sum;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {
    int reverseNum = 0; int temp = 0;
    int currentDigit = 0;
    bool negative = false;

    if(num<0){
        negative = true;
        num = -1 * num;
    }

  while(num != 0){
      currentDigit = num % 10;
      reverseNum = (reverseNum * 10) + currentDigit;

      if((reverseNum - currentDigit)/10 != temp){
          return 0;     //overflow detected
      }


      temp = reverseNum;
      num = num/10;
  }

  if(negative == true)
      reverseNum = -1 * reverseNum;

  return reverseNum;

}

  

