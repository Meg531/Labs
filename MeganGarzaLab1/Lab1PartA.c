/*
Author:                   Megan Garza
Assignment Number:        Lab Assignment 1 Part A
File Name:                MeganGarzaLab1.zip
Course/Selection:         CS 2124 Section 0D1
Due Date:                 21 September 2020
Instructor:               Dr. Ku
*/

#include <stdio.h>

double power(double a, int n);

int main() {
    double base;
    int exponent;

    printf("Enter base ");
    scanf("%lf", &base);
    printf("Enter exponent ");
    scanf("%d", &exponent);

    printf("%g raised to  %d = %g\n", base, exponent, power(base, exponent));
    return 0;
}

double power(double a, int n) {
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return 1 / power(a, -n);
    } else {
        return a * power(a, n - 1);
    }
}