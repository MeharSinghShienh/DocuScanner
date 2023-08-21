#include "Search.h"
using namespace std;


// how many documents have each word or a specified word
void df(Trienode* trie) {
    char* token2;
    token2 = strtok(NULL, " \t\n");
    if (token2 != NULL) {
        cout<<token2<<" "<<trie->dsearchword(token2,0)<<endl;        
    } else {
        char* buffer = (char*)malloc(256*sizeof(char));
        trie->dsearchall(buffer,0);
        free(buffer);
    }
    token2 = NULL;
    free(token2);
}

//how many times a specific word shows up in a document
int tf(char* token, Trienode* trie) { 
    char* token2;
    token2 = strtok(NULL," \t\n");
    if (token2 == NULL) {
        free(token2);
        return -1;
    }
    for (int i = 0; i < strlen(token2); i++) {
        if (!isdigit(token2[i])) {
            token2 = NULL;
            free(token2);
            return -1;
        }
    }
    int id = atoi(token2);
    token2 = strtok(NULL, " \t\n");
    if (token2 == NULL) {
        free(token2);
        return -1;
    }
    cout<<id<<" "<<token2<<" "<<trie->tfsearchword(id,token2,0)<<endl;
}