/* 
 * File:   PWRTask.cpp
 * Author: artur
 * 
 * Created on 4 listopad 2012, 16:44
 */

#include "PWRTask.h"
#include <math.h>
#include <stdlib.h>
using namespace std;

int PWRTask::checkDigitsOrderAndSum(int number) {
    int buff;
    int sum = 0;
    while (number) {
        buff = number;
        number = number / 10;
        if (buff % 10 <= number % 10) {
            return 0;
        }
        sum += buff % 10;
    }

    return sum;
}
