#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
vi owner, visited; // global variables

int AlternativePath(int left) {
    if (visited[left]) return 0;
    visited[left] = true;
    for (int j = 0; j < (int)AdjList[left].size(); j++) {
        int right = AdjList[left][j].first;
        // either greedy assignment or recurse
        if (owner[right] == -1 || AlternativePath(owner[right])) {
            owner[right] = left;
            return 1; // we found one matching
        }
    }
    return 0; // no matching
}

int main() {
    int i, j;

    int V = 4, num_vertices_on_left = 2;
    AdjList.assign(V, vii());
    AdjList[0].push_back(ii(2, 1));
    AdjList[0].push_back(ii(3, 1));
    AdjList[1].push_back(ii(2, 1));


  // the MCBM routine
    int cardinality = 0;
    owner.assign(V, -1);
    for (int left = 0; left < num_vertices_on_left; left++) {
        visited.assign(num_vertices_on_left, 0);
        cardinality += AlternativePath(left);
    }

    printf("Found %d matchings\n", cardinality);

    return 0;
}
