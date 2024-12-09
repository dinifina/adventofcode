#include <iostream>
#include <fstream>

using namespace std;

struct node {
    int pageNum;
    struct node *nextnode;
}

struct vertexList {
    struct node *head;
}

struct Graph {
    int v;
    //vl is a list of vertex lists
    struct vertexList *vl;
}

struct Graph* createGraph(int n) {
    int i;
    struct Graph *vlist = new Graph;
    vlist->v = n;

    vlist->vl = new vertexList[n + 1];

    // instantiate each vertex head as null
    for(int i = 0; i < n + 1; i++) {
        vlist->vl[i].head = NULL;
    }

    return vlist;
}

struct node* NewNode(int val) {
    struct node *newnode = new node;
    newnode->pageNum = val;
    newnode->nextnode = NULL;

    return newnode;
}