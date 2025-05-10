#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;
    
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        
        for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    
    void DFS(int s) {
        vector<bool> visited(V, false);
        DFSUtil(s, visited);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    cout << "Depth First Traversal (starting from vertex 0): ";
    g.DFS(0);

    return 0;
}
