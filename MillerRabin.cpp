/* 
 * File:   MillerRabin.cpp
 * Author: artur
 * 
 * Zamieszczony tu kod nie jest moją implementacją testu MR
 * Pochodzi on z: http://www.algorytm.org/algorytmy-arytmetyczne/test-pierwszosci-test-millera-rabina/miller-rabin-c.html
 * 
 * Natomiast jestem autorem widocznych zmian czy tez poprawek.
 * 
 * 
 * Created on 3 listopad 2012, 20:21
 */

#include "MillerRabin.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <cmath>
using namespace std;

int MillerRabin::shift2Pow(int pow) {
    return 1 << pow;
}

int MillerRabin::processTest(int n) {

    int s = 0;
    int s2 = 1;
    int a, d, i, r, prime;
    srand(time(NULL));

    if (n < 4 && n > 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }


    while ((s2 & (n - 1)) == 0) {
        s += 1;
        s2 <<= 1;
    }
    d = n / s2;

    for (i = 0; i < PRECISE_K; i++) {
        a = RandomFloat(2, n);
        if (this->powModFast(a, d, n) != 1) {
            prime = 0;
            for (r = 0; r <= s - 1; r++) {
                if (this->powModFast(a, this->shift2Pow(r) * d, n) == n - 1) {
                    prime = 1;
                    break;
                }
            }
            if (prime == 0) {
                return 0;
            }
        }
    }

    return 1;
}

float MillerRabin::RandomFloat(float min, float max) // range <min, max)
{
    float r = (float) rand() / (float) RAND_MAX;
    return min + r * (max - min);
}
//a^b mod m
long long int MillerRabin::powModFast(int a, int b, int m) {
    int i;
    long long int result = 1;
    long int x = a % m;

    for (i = 1; i <= b; i <<= 1) {
        x %= m;
        if ((b & i) != 0) {
            result *= x;
            result %= m;
        }
        x *= x;
    }

    return result;
}


