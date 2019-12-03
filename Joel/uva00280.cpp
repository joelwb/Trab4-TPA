#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visiteds, inaccessibles;

void getInaccessibles(int initial, vector<int> *edges[]) {
    vector<int>::iterator pos = find(visiteds.begin(), visiteds.end(), initial);
    if (visiteds.empty() || pos == visiteds.end()) {
        visiteds.push_back(initial);

        for (int v : *edges[initial]){
            if (find(inaccessibles.begin(), inaccessibles.end(), v) != inaccessibles.end()) {
                inaccessibles.erase(find(inaccessibles.begin(), inaccessibles.end(), v));
            }
            
            getInaccessibles(v, edges);
        }

    }    
}

int main() {
    int n, j, startVertex;

    while (cin >> n && n != 0){
        vector<int> *edges[n+1];

        while (cin >> startVertex && startVertex != 0) {
            edges[startVertex] = new vector<int>();
            while (cin >> j && j != 0){
                edges[startVertex]->push_back(j);
            } 
        }

        cin >> j;

        for (int i = 0; i < j; i++) {
            cin >> startVertex;

            visiteds.clear();
            inaccessibles.clear();
            for (int k = 1; k <= n; k++) {
                inaccessibles.push_back(k);
            }

            getInaccessibles(startVertex, edges);

            cout << inaccessibles.size() << " ";

            for (int k = 0; k < inaccessibles.size() - 1; k++) {
                cout << inaccessibles[k] << " ";
            }

            cout << inaccessibles[inaccessibles.size()-1] << endl;
        }
    }
}