#include "Listnode.h"

Listnode::~Listnode() {
    if (next != NULL) {
        delete(next);
    }
}

void Listnode::add(int did) {
    if (did == id) {
        times++;
    } else {
        if (next == NULL) {
            next = new Listnode(did);
        }
        next->add(did);
    }
}

int Listnode::search(int did) {
    if (did == id) {
        return times;
    } else {
        if (next == NULL) {
            return 0;
        } else {
            return next->search(did);
        }
    }
}

int Listnode::volume() {
    if (next != NULL) {
        return 1+next->volume();
    } else {
        return 1;
    }
}
