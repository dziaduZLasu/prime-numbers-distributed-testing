/* 
 * File:   Communicator.cpp
 * Author: artur
 * 
 * Created on 30 październik 2012, 16:52
 */

#include "Communicator.h"
using namespace std;

Communicator::Communicator(int* argc, char* argv[], ompi_communicator_t* comm) {
    this->comm = comm;
    MPI_Init(argc, &argv);
    MPI_Comm_rank(this->comm, &this->nodeId);
    MPI_Comm_size(this->comm, &this->nodeCount);
}

Communicator::Communicator(const Communicator& orig) {
}

Communicator::~Communicator() {
    MPI_Finalize();
}

void Communicator::nodeSelfIdentify() {
    if (this->nodeId == 0)
        cout << "Master - id: " << this->nodeId << " z: " << this->nodeCount << " procesów." << endl;
    else
        cout << "Slave - id: " << this->nodeId << " z: " << this->nodeCount << " procesów." << endl;
}

int Communicator::getId() {
    return this->nodeId;
}

int Communicator::getNodeCount() {
    return this->nodeCount;
}

void Communicator::bcastTasks(int *pPerNode) {
    MPI_Bcast(pPerNode, 1, MPI_INT, 0, this->comm);
}

void Communicator::scatterTasks(int continous[][2], int recvNodeRangesArr[2]) {
    MPI_Scatter(continous, 2, MPI_INT, recvNodeRangesArr, 2, MPI_INT, 0, this->comm);
}

void Communicator::reduceTasks(int *pointsInsidePerNode, int *pointsInside) {
    MPI_Reduce(pointsInsidePerNode, pointsInside, 1, MPI_INT, MPI_SUM, 0, this->comm);
}






