#include <iostream>
#include <vector>
#define INF 9999999
using namespace std;

class Graph {
private:
    int size;
    vector<vector<int>> adj_matrix;
    vector<string> vertex_data;

public:
    Graph(int n) {
        size = n;
        adj_matrix.resize(n, vector<int>(n, 0));
        vertex_data.resize(n);
    }

    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            adj_matrix[u][v] = weight;
            adj_matrix[v][u] = weight;
        }
    }

    void addVertexData(int v, string data) {
        if (v >= 0 && v < size) {
            vertex_data[v] = data;
        }
    }

    int getMinKeyVertex(const vector<int>& key_values, const vector<bool>& in_mst) {
        int minKey = INF, minIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (!in_mst[i] && key_values[i] < minKey) {
                minKey = key_values[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void primsAlgorithm() {
        vector<int> key_values(size, INF);
        vector<int> parent(size, -1);
        vector<bool> in_mst(size, false);

        key_values[0] = 0;

        cout << "Edge \tWeight\n";

        for (int count = 0; count < size; ++count) {
            int u = getMinKeyVertex(key_values, in_mst);
            in_mst[u] = true;

            if (parent[u] != -1)
                cout << vertex_data[parent[u]] << "-" << vertex_data[u] << " \t" << adj_matrix[u][parent[u]] << "\n";

            for (int v = 0; v < size; ++v) {
                if (adj_matrix[u][v] && !in_mst[v] && adj_matrix[u][v] < key_values[v]) {
                    key_values[v] = adj_matrix[u][v];
                    parent[v] = u;
                }
            }
        }
    }
};

int main()
{
    Graph g(8);

    g.addVertexData(0, "A");
    g.addVertexData(1, "B");
    g.addVertexData(2, "C");
    g.addVertexData(3, "D");
    g.addVertexData(4, "E");
    g.addVertexData(5, "F");
    g.addVertexData(6, "G");
    g.addVertexData(7, "H");

    g.addEdge(0, 1, 4);
    g.addEdge(0, 3, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 7, 2);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 5, 4);
    g.addEdge(4, 5, 5);
    g.addEdge(4, 6, 3);
    g.addEdge(5, 6, 7);
    g.addEdge(6, 7, 5);

    cout << "Prim's Algorithm MST:\n";
    g.primsAlgorithm();

    return 0;
}
