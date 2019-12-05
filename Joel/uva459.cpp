/*
Autor Joel Will Belmiro
O problema quer que se descobra a quantidade de subgrafos não conectados
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

pair<int,int> getEdgeValues(string edgesStr){
    return make_pair(((int)edgesStr[0] - 65), ((int)edgesStr[1] - 65));
}

vector<int> visiteds;
set<int> subgraph;
vector<set<int>> maxConSubgraphs;

void getSubgraph(int initial, vector<int> *edges[]) {
    vector<int>::iterator pos = find(visiteds.begin(), visiteds.end(), initial);
    if (visiteds.empty() || pos == visiteds.end()) {
        visiteds.push_back(initial);
        subgraph.insert(initial);

        for (int v : *edges[initial]){
            getSubgraph(v, edges);
        }

    }    
}

bool hasGraph(set<int> g){
    for (set<int> s : maxConSubgraphs){
        set<int> graph;
        graph.insert(g.begin(), g.end());
        graph.insert(s.begin(), s.end());

        if (graph.size() == g.size()) return true;
    }

    return false;
}

int main(){
    int n;
    string edge;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> edge;
        cin.ignore();

        int maxEdge = ((int)edge[0] - 65);
        vector<int> *adjList[maxEdge+1];
        for (int i = 0; i < maxEdge+1; i++) adjList[i] = new vector<int>();
        
        while (getline(cin, edge) && edge != "") {
            pair<int, int> edgeValues = getEdgeValues(edge);

            adjList[edgeValues.first]->push_back(edgeValues.second);
            adjList[edgeValues.second]->push_back(edgeValues.first);
        }

        set<int> subgraphs[maxEdge+1];

        for (int j = 0; j < maxEdge+1; j++) {
            subgraph.clear();
            visiteds.clear();
            getSubgraph(j, adjList);
            subgraphs[j] = set<int>(subgraph.begin(), subgraph.end());
        }

        maxConSubgraphs.clear();
        for (int j = 0; j < maxEdge+1; j++) {
            if (!hasGraph(subgraphs[j])) {
                maxConSubgraphs.push_back(subgraphs[j]);
            }
        }

        
        cout << maxConSubgraphs.size() << endl;
        
        if (i != n-1) cout << endl;
    }
}