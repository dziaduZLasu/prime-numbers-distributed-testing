/* 
 * File:   Communicator.h
 * Author: artur
 *
 * Created on 30 październik 2012, 16:52
 */

#ifndef COMMUNICATOR_H
#define	COMMUNICATOR_H
#include<mpi.h>


class Communicator {
public:
    Communicator(int* argc, char* argv[], ompi_communicator_t* comm);
    Communicator(const Communicator& orig);
    virtual ~Communicator();
    void nodeSelfIdentify();
    void bcastTasks(int *pPerNode);
    void scatterTasks(int continous[][2], int recvNodeRangesArr[2]);
    void reduceTasks(int *pointsInsidePerNode, int *pointsInside);
    int getId();
    int getNodeCount();
private:
    ompi_communicator_t* comm;
    MPI_Status stat;
    void* message;
    int nodeId;
    int nodeCount;
    int data;

};

#endif	/* COMMUNICATOR_H */

