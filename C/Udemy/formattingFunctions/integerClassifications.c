/*  Integer Classifications Library
 *
 *  contains functions that can classify an input integer as even, odd, and/or prime
 * 
 *  Author: Jaryd Peters
 */

#include "boolDefine.h"

int isEven(const int num)
{
    return((num % 2) == 0);
}

int isOdd(const int num)
{
    return !isEven(num);
    //return ((num % 2) == 1); would also work here
}

int isPrime(const int num)
{
    //negative or even integers are not prime
    if((num < 0) || isEven(num))
    {
        return FALSE;
    }
    else
    {
        //divide num by every integer from 2 (avoid dividing by 0 and 1) up to half of num to check if num is prime
        for(int i = 2; i <= (num / 2); i++)
        {
            if((num % i) == 0)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

int isNotPrime(const int num)
{
    return !isPrime(num);
}