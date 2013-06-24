/* 
 * File:   RootNode.cpp
 * Author: artur
 * 
 * Created on 3 listopad 2012, 15:27
 */
#include <iostream>
#include "RootNode.h"
using namespace std;

RootNode::RootNode() {

    this->start = 3;
    this->end =0;
    while (this->end == 0 || this->end > 123456789) {
        cout << "Podaj zakres całkowity do sprawdzenia. Od 3 do [max 123456789]:  ";
        cin >> this->end;
    }
}

int RootNode::calcRanges(int** &ret, int nodeCount) {
    int len = nodeCount;
    ret = new int*[len];
    int j = this->start;
    int step = (this->end - this->start) / (nodeCount);
    for (int i = 0; i < len; ++i) {
        ret[i] = new int[2];
        ret[i][0] = j;

        j += step;
        if (i == len - 1)
            j += (this->end - this->start) % (nodeCount);
        ret[i][1] = j;
    }
    return len;
}


