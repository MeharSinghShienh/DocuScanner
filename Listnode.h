#include <iostream>
#include <cstdlib>
#include <cstring>

#ifndef LISTNODE_H
#define LISTNODE_H

class Listnode {
    Listnode *next; // next item in list
    int id; // document id
    int times; //how many times word appears in document
    public:
        Listnode(int did):id(did),times(0) {
            next = NULL;
        }
        ~Listnode();
        void add(int did);
        int search(int did);
        int volume();
};

#endif