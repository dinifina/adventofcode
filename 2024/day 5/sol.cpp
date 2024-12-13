#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

struct node {
    int pageNum;
    struct node *nextnode;
};

struct vertexList {
    struct node *head;
};

struct Graph {
    int v;
    struct vertexList *vl;
};

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

struct node* newNode(int val) {
    struct node *newnode = new node;
    newnode->pageNum = val;
    newnode->nextnode = NULL;

    return newnode;
}

void addEdge(Graph *G, int v1, int v2) {
    node *n2 = newNode(v2);

    // Checks if there are no nodes in list v1
    if (G->vl[v1].head == NULL) {
        G->vl[v1].head = n2;
    } else {
    // Else add to beginning of list
        n2->nextnode = G->vl[v1].head;
        G->vl[v1].head = n2; 
    }
}

bool isReachable(Graph *G, int from, int to) {
    if (from == to) {
        return true;
    }

    vector<bool> visited(G->v, false);
    list<int> queue;

    visited[from] = true;
    queue.push_back(from);

    list<int>::iterator it;

    while(!queue.empty()) {
        from = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of dequeued vertex s
        struct node* currNode = G->vl[from].head;
        while (currNode != NULL) {
            if (currNode->pageNum == to) {
                return true;
            }

            if (!visited[currNode->pageNum]) {
                visited[currNode->pageNum] = true;
                queue.push_back(currNode->pageNum);
            }

            currNode = currNode->nextnode;
        }
    }

    return false;
}

void dfs(int v, Graph* g, vector<bool> &visited, vector<int> &ans) {
    visited[v] = true;

    node* currNode = g->vl[v].head;
    while (currNode != NULL) {
        if (!visited[currNode->pageNum]) {
            dfs(currNode->pageNum, g, visited, ans);
        }
        currNode = currNode->nextnode;
    }

    ans.push_back(v);
}

vector<int> topologicalSort(Graph* g, vector<int> update) {
    vector<bool> visited(g->v, false);
    vector<int> sorted = {};
    vector<int> ans = {};

    for (int i = 0; i < g->v; i++) {
        if (!visited[i]) {
            dfs(i, g, visited, sorted);
        }
    }

    reverse(sorted.begin(), sorted.end());
    
    for (int i = 0; i < sorted.size(); i++) {
        if (find(update.begin(), update.end(), sorted[i]) != update.end()) {
            ans.push_back(sorted[i]);
        }
    }

    return ans;
}

int main() {
    fstream MyFile("puzzle.txt");
    string text;

    struct Graph* g = createGraph(100);
    int sum = 0;
    int sumOfIncorrect = 0;

    int line = 0;

    // Create mega graph
    while(getline(MyFile, text) && text != "") {
        int page1 = stoi(text.substr(0, text.find("|")));
        int page2 = stoi(text.substr(text.find("|") + 1));
        addEdge(g, page1, page2);
    }

    while(getline(MyFile, text)) {
        stringstream s(text);
        string token;
        vector<int> update = {};
        Graph* updateGraph = createGraph(100);
        
        // Create graph for each update and add edges for every rule of each page num mentioned
        while(getline(s, token, ',')) {
            int currPage = stoi(token);
            update.push_back(currPage);
            node* currNode = g->vl[currPage].head;

            while (currNode != NULL) {
                addEdge(updateGraph, currPage, currNode->pageNum);
                currNode = currNode->nextnode;
            }
        }

        bool isValidUpdate = true;
        for (int i = 0; i < update.size() - 1; i++) {
            if (!isReachable(updateGraph, update[i], update[i + 1])) {
                isValidUpdate = false;
                break;
            }
        }

        if (isValidUpdate) {
            int mid = update[update.size()/2];
            sum += mid;
        } else {
            // Topological sort graph
            vector<int> sorted = topologicalSort(updateGraph, update);
            sumOfIncorrect += sorted[sorted.size()/2];
        }

        line++;
    }

    cout << "Sum of correct updates: " << sum << endl;
    cout << "Sum of incorrect updates: " << sumOfIncorrect << endl;
}