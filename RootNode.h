/* 
 * File:   RootNode.h
 * Author: artur
 *
 * Created on 3 listopad 2012, 15:27
 */

#ifndef ROOTNODE_H
#define	ROOTNODE_H

class RootNode {
public:
    RootNode();
    int calcRanges(int**&, int);
private:
    int start;
    int end;

};

#endif	/* ROOTNODE_H */

