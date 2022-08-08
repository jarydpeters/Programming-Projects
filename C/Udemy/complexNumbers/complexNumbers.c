/*  Complex Numbers Exercise
 *
 *  Performs mathematical operations using math.h and complex.h
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI acos(-1)

int main(void)
{
    //ans1 = ans2 = imaginary unit squared
    double complex ans1 = I * I;
    printf("\nreal and imaginary parts of i * i:        %0.1f + %0.1fi", creal(ans1), cimag(ans1));

    //ans2 = ans1 = imaginary unit squared
    double complex ans2 = pow(I,2);
    printf("\nreal and imaginary parts of i^2:           %0.1f + %0.1fi", creal(ans2), cimag(ans2));

    //ans3 = Euler's formula
    double complex ans3 = exp(I * PI);
    printf("\nreal and imaginary parts of e^(i*pi):      %0.1f + %0.1fi", creal(ans3), cimag(ans3));

    //ans4 = 1 + 2 * I
    //ans5 = 1 - 2 * I
    //ans4 and ans5 are conjugates
    double complex ans4 = 1+2*I;
    double complex ans5 = 1-2*I;
    printf("\nreal and imaginary parts of (1+2i)*(1-2i): %0.1f + %0.1fi", creal(ans4 * ans5), cimag(ans4 * ans5));

    return 0;
}