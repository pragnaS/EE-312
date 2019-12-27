#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Pragna Subrahmanya
 * email address: pragnals@utexas.edu
 * UTEID: ps28338
 * Section 5 digit ID: 16025
 *  
 */

//function prototypes. These will be completed in CodeCamp.c
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int num1, int num2);
int reverseInt(int num); 
//****************************

int main() {


  // test 1, hamming distance
  int h3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -6};
  int h4[] = {1, 1, 1, 1, 1, 1, -6, -6, -6, -6}; 
  int expected = 8;
  int actual = hammingDistance(h3, h4, 10);
  printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 1, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 1, hamming distance\n\n");

  // test 2, hamming distance
  int h5[60000] = {2};
  int h6[60000] = {2}; 
  expected = 0;
  actual = hammingDistance(h5, h6, 60000);
  printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 2, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 2, hamming distance\n\n");

  // test 3, last digit
  int n1 = -100;
  int n2 = 120;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 3 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 3, last digit\n\n");
  else 
     printf("**** FAILED **** test 3, last digit\n\n");

  // test 4, last digit
  n1 = 55555;
  n2 = -123468;
  expected = false;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
    printf("passed test 4, last digit\n\n");
  else 
     printf("**** FAILED **** test 4, last digit\n\n");


  // test 5, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 5 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 5, sum of multiples of 3 or 5\n\n");
  else 
     printf("**** FAILED **** test 5, sum of multiples of 3 or 5\n\n");


  // test 6, reverse int
  n1 = -3000;
  expected = -3;
  actual = reverseInt(n1); 
  printf("Test 6 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 6, reverse int\n\n");
  else 
     printf("**** FAILED **** test 6, reverse int\n\n");

  // test 7, reverse int
  n1 = -1999999999;
  expected = 0;
  actual = reverseInt(n1); 
  printf("Test 7 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 7, reverse int\n");
  else 
     printf("**** FAILED **** test 7, reverse int\n");

}

