#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            s = q.front();
            q.pop();
            cout << s << " ";

            for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    cout << "breath First Traversal (starting from vertex 0): ";
    g.BFS(0);

    return 0;
}
