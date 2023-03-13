#include <iostream>
#include <vector>
#include <stack>

// Calculate the Hamming distance between two binary vectors
int hammingDistance(const std::vector<int>& v1, const std::vector<int>& v2) {
    int distance = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            distance++;
        }
    }
    return distance;
}

// Generate all binary vectors of a given size
void generateBinary(int size, std::vector<int>& v, std::vector<std::vector<int>>& combinations) {
    if (size == 0) {
        // Add the current binary combination to the list of combinations
        combinations.push_back(v);
        return;
    }

    // Generate binary combinations by setting the current digit to 0 or 1
    v.push_back(0);
    generateBinary(size - 1, v, combinations);
    v.pop_back();

    v.push_back(1);
    generateBinary(size - 1, v, combinations);
    v.pop_back();
}

// Find the maximal clique of a given size in a Hamming graph with a minimum distance
void findMaximalClique(int size, int distance, std::vector<std::vector<int>>& combinations, std::vector<std::vector<int>>& clique) {
    // Initialize the stack with the first combination
    std::stack<std::vector<int>> s;
    s.push(combinations[0]);
    clique.push_back(combinations[0]);

    // Perform depth-first search
    while (!s.empty()) {
        std::vector<int> current = s.top();
        s.pop();

        // Check if adding any combination to the clique is possible
        for (int i = 0; i < combinations.size(); i++) {
            bool canAdd = true;
            for (int j = 0; j < clique.size(); j++) {
                if (hammingDistance(combinations[i], clique[j]) < distance) {
                    canAdd = false;
                    break;
                }
            }
            if (canAdd) {
                s.push(combinations[i]);
                clique.push_back(combinations[i]);
            }
        }
    }
}
int main() {
    std::cout << "Enter size of binary vectors: ";
    int size;
    std::cin >> size;

    std::cout << "Enter minimum distance: ";
    int distance;
    std::cin >> distance;

    std::vector<int> v;
    std::vector<std::vector<int>> combinations;
    generateBinary(size, v, combinations);

    std::vector<std::vector<int>> clique;
    findMaximalClique(size, distance, combinations, clique);

    std::cout << "Maximal clique:" << std::endl;
    for (int i = 0; i < clique.size(); i++) {
        for (int j = 0; j < size; j++) {
            std::cout << clique[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Size of maximal clique: " << clique.size() << std::endl;

    return 0;
}