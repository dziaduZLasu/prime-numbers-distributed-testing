/* 
 * File:   MillerRabin.h
 * Author: artur
 *
 * Created on 3 listopad 2012, 20:21
 */

#ifndef MILLERRABIN_H
#define	MILLERRABIN_H

static const int PRECISE_K = 30;
class MillerRabin {
public:
    int processTest(int n);
private:
    float RandomFloat(float min, float max); // range <min, max)
    int  shift2Pow(int pow);
    long long int powModFast(int a, int b, int m);
};

#endif	/* MILLERRABIN_H */

