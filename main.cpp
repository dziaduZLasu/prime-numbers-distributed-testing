/* 
 * File:   main.cpp
 * Author: artur
 *
 * Created on 3 listopad 2012, 19:52
 */

#include "Communicator.h"
#include<iostream>
#include <cstdlib>
#include "RootNode.h"
#include "MillerRabin.h"
#include "PWRTask.h"
using namespace std;

int main(int argc, char** argv) {

    RootNode *srv;
    MillerRabin *mr;
    PWRTask *t;
    int** nodeRangesArr = NULL;
    int recvNodeRangesArr[2];
    int arrLen = 0;
    
    Communicator *c = new Communicator(&argc, argv, MPI_COMM_WORLD);    
    
    //ciągła realokacaja dla scatter nie mogłem sobie z tym poradzić w inny sposób
    //mimo wszystko chciałem utrzymac niezaleznosc od ilości węzłów
    int continous[c->getNodeCount()][2];

    if (c->getId() == 0) {
        srv = new RootNode();
        arrLen = srv->calcRanges(nodeRangesArr, c->getNodeCount());
        //ciągła realokacaja dla scatter    
        for (int i = 0; i < arrLen; i++) {
            continous[i][0] = nodeRangesArr[i][0];
            continous[i][1] = nodeRangesArr[i][1];
        }
    }

    c->scatterTasks(continous, recvNodeRangesArr);

    mr = new MillerRabin();
    t = new PWRTask();
    int sum;
    // Każdy węzeł w tym root liczy swój zakres
    //c->nodeSelfIdentify();
    int i = (recvNodeRangesArr[0] % 2 == 0) ? recvNodeRangesArr[0] + 1 : recvNodeRangesArr[0];
    for (i; i <= recvNodeRangesArr[1]+1; i += 2) {
        sum = t->checkDigitsOrderAndSum(i);
        if (sum && mr->processTest(sum) && mr->processTest(i)) {
            cout << i << endl;
        }
    }

    delete c;
    return 0;
}
