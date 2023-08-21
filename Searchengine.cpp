#include "Searchengine.h"

using namespace std;

int inputmanager(char* input, Trienode* trie, Mymap* map) {
    char* token = strtok(input," \t\n");
    if (!strcmp(token,"/df")) {
        df(trie);
    } else if (!strcmp(token,"/tf")) {
        if (tf(token,trie) == -1) {
            return -1;
        }
    } else if (!strcmp(token,"/exit")) {
        cout<<"Exiting..."<<endl;
        token = NULL;
        free(token);
        return 2;
    } else {
        return -1;
    }
    token = NULL;
    free(token);
    return 1;
}

int main(int argc, char **argv) {
    if(argc!=4 || strcmp(argv[1], "-d") || strcmp(argv[3], "-k")) {
        cout<<"wrong arguments"<<endl;
        return -1;
    } 
    cout<<"Please Wait"<<endl;
    int linecounter=0;
    int maxlength=-1;
    if (read_sizes(&linecounter,&maxlength,argv[2]) == -1) {
        cout<<"this"<<endl;
        return -1;
    }

    Mymap *mymap = new Mymap(linecounter,maxlength);
    Trienode *trie = new Trienode();
    if (read_input(mymap, trie, argv[2]) == -1) {
        delete(mymap);
        return -1;
    }

    cout<<"Database Ready"<<endl;

    char* input = NULL;
    size_t inputlength = 0;
    while(1) {
        getline(&input, &inputlength, stdin);
        int ret = inputmanager(input, trie, mymap);
        if (ret == -1) {
            cout << "Wrong Input" << endl;
        } else if (ret == 2) {
            free(input);
            break;
        }
        free(input);
        inputlength = 0;
    }

    delete(mymap);
    delete(trie);

    return 1;
}