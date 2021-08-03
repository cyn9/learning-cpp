#include <iostream>
#include <vector>

void print2DVector(const std::vector< std::vector<int> > &);

int main() {
    // Get a 3-by-4 matrix. Initialize all elements to zero.
    constexpr std::size_t N {3};
    constexpr std::size_t M {4};

    std::vector< std::vector<int> > V(N, std::vector<int>(M, 0));

    print2DVector(V);

    for (auto row = 0; row < V.size(); ++row) {
        for (auto col = 0; col < V[row].size(); ++col) {
            V[row][col] = (row+1) * (col+1);
        }
    }

    std::cout << '\n';
    print2DVector(V);

    return 0;
}

void print2DVector(const std::vector< std::vector<int> > &V) {
    for (auto row = 0; row < V.size(); ++row) {
        for (auto col = 0; col < V[row].size(); ++col) {
            std::cout << V[row][col] << "  ";
        }

        std::cout << '\n';
    }
}
