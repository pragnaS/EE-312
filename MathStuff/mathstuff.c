/* mathStuff_xxxxxx.c

Roger Priebe and (you)
cs1428 10/15/2007 (updated 3/24/09)
EE312  10/3/2018

Finish comments here
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);

int isPrimeHelp(int num, int i);
int printPrimesHelp(int start, int last);
int findFactorsHelp(int n, int m);
//******************  MAIN  *****************************



int main () {
    
    
    int testNum;
    
    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);
    
    if (isPrime(testNum))  
       printf("%d is prime\n",testNum);
    else
       printf("%d is not prime.", testNum);
    
    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);
    
    printPrimes(testNum);
    
    printf("\n");
    
    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);
   
    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum)); 
    
    printf("\n");
    
    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);
    
    findFactors(testNum);
    
    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number){
   const int START_DIVISOR = 2; //HINT: You may want a helper function
   if(number == 0)
       return false;
   if(number == 1)
       return true;
   int prime = isPrimeHelp(number, number/2);
   if(prime == 1)
       return true;
   else
       return false;
}

int isPrimeHelp(int num, int i){
    if(i==1)
        return 1;
    else if(num%i == 0)
        return 0;
    else
        isPrimeHelp(num, i-1);
}

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n) {
    if(n==1) {
        printf("1");
        return;
    }
    int check = printPrimesHelp(1, n);
    if(check == 1)
        return;

}

int printPrimesHelp(int start, int last){

    if(isPrime(start))
        printf("%d ", start);

    if(start<last)
        printPrimesHelp(start+1, last);
    else
        return 1;

}


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    if(n<=1)
        return n;
    else
        return(findFibo(n-2) + findFibo(n-1));

}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    if(isPrime(number)){
        printf("%d = prime\n", number);
    }
    else{
        printf("%d = ", number);
        findFactorsHelp(number, number-1);
	printf("1\n");
    }


}

int findFactorsHelp(int num, int factor){
    if(isPrime(num))
        printf("%d * ", num);
    else if(num % factor == 0){
        findFactorsHelp(factor, factor-1);
        findFactorsHelp(num/factor, (num/factor)-1);
    }
    else findFactorsHelp(num, factor-1);
}

