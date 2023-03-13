#include <iostream>
#include <vector>

using namespace std;

int connection_count(int x, int y, int N) {
    // compute the number of connections between x and y
    int count = 0;
    for (int i = 0; i < N; i++) {
        if ((x & (1 << i)) != (y & (1 << i))) {
            count++;
        }
    }
    return count;
}

void find_clique(vector<int>& clique, vector<int>& possible_vertices, int N, int D) {
    // base case: if possible_vertices list is empty, return
    if (possible_vertices.empty()) {
        return;
    }

    // choose the node with the maximum connections in the possible_vertices list
    int max_node = possible_vertices[0];
    int max_count = -1;
    for (int i = 0; i < possible_vertices.size(); i++) {
        int count = 0;
        for (int j = 0; j < clique.size(); j++) {
            count += (connection_count(possible_vertices[i], clique[j], N) >= D);
        }
        if (count > max_count) {
            max_count = count;
            max_node = possible_vertices[i];
        }
    }

    // add the maximum node to the clique and update the possible_vertices list
    clique.push_back(max_node);
    vector<int> new_possible_vertices;
    for (int i = 0; i < possible_vertices.size(); i++) {
        if (connection_count(max_node, possible_vertices[i], N) >= D) {
            new_possible_vertices.push_back(possible_vertices[i]);
        }
    }
    possible_vertices = new_possible_vertices;

    // recursively find the clique with the updated possible_vertices list
    find_clique(clique, possible_vertices, N, D);
}

int main() {

    int N , D ;
    cin >> N;
    cin >> D;

    vector<int> clique; // set to store the clique
    vector<int> possible_vertices; // set to store the possible_vertices
    for (int i = 0; i < (1 << N); i++) {
        possible_vertices.push_back(i);
    }
    find_clique(clique, possible_vertices, N, D);
    cout << "Size of maximal clique: " << clique.size() << endl;
    return 0;
}