/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */
#include <stdio.h>
#include <math.h>

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */

double taylor_sine(double x, int n) {
    double term = x;       // First term is x^1 / 1!
    double sum = x;
    int sign = -1;

    for (int i = 1; i < n; ++i) {
        term = term * x * x / ((2 * i) * (2 * i + 1));
        sum += sign * term;
        sign *= -1;
    }

    return sum;
}

int main() {
    double angle;
    int terms;

    printf("Enter angle in radians: ");
    scanf("%lf", &angle);

    printf("Enter number of terms: ");
    scanf("%d", &terms);

    double result = taylor_sine(angle, terms);
    printf("Approximate sin(%lf) using %d terms: %lf\n", angle, terms, result);
    
    double result2 = sin(angle);
    printf("Approximate sin(%lf) using %d terms: %lf\n", angle, terms, result2);
    return 0;
}