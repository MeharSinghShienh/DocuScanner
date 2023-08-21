#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Trienode.h"
#include "Map.h"
#include <cmath>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;


void df(Trienode* trie);

int tf(char* token, Trienode* trie);