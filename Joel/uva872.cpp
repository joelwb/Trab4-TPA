#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

vector<int> visiteds;
bool consts[26][26];
vector<vector<int>> orderedGraphs;

bool passInConst(int actual) {
    for (int i = 0; i < 26; i++) {
        bool isVisited = find(visiteds.begin(), visiteds.end(), i) != visiteds.end();
        if (consts[actual][i] && !isVisited) return false;
    }

    return true;
}

void visit(int initial, vector<int> lstNos, bool flag) {
    
    vector<int>::iterator pos = find(visiteds.begin(), visiteds.end(), initial);
    if ((visiteds.empty() || pos == visiteds.end()) && flag) {
        if (!passInConst(initial)) {
            flag = false;
        } else {
            visiteds.push_back(initial);
        }

        for (int v : lstNos){
            visit(v, lstNos, flag);
        }

        if (flag) {
            if (visiteds.size() == lstNos.size()) {
                orderedGraphs.push_back(vector<int>(visiteds));
            }

            visiteds.pop_back();
        }

    }    
}

int charToInt(char c) { return ((int)c - 65); }

char intToChar(int i) { return (char) (i+65); }

bool cmp(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i]) return a[i] < b[i];
    }

    return true;
}

int main() {
    int n;
    string s;
    stringstream ss;

    cin >> n;
    cin.ignore();


    for (int i = 0; i < n; i++) {
        getline(cin, s);
        getline(cin, s);
        ss.clear();
        ss << s;

        vector<int> lstNos;

        while (ss >> s) {
            lstNos.push_back(charToInt(s[0]));
        }
        
        fill(*consts, *consts + (26*26), false);
        
        getline(cin, s);
        ss.clear();
        ss << s;

        while (ss >> s) {
            consts[charToInt(s[2])][charToInt(s[0])] = true;
        }

        orderedGraphs.clear();
        for (int j : lstNos) {
            visiteds.clear();
            visit(j, lstNos, true);
        }

        sort(orderedGraphs.begin(), orderedGraphs.end(), cmp);

        for (vector<int> g : orderedGraphs){
            for (int j = 0; j < g.size() - 1; j++){
                cout << intToChar(g[j]) << " ";
            }

            cout << intToChar(g[g.size()-1]) << endl;
        }

        if (orderedGraphs.empty()) cout << "NO" << endl;
        if (i != n-1) cout << endl;
    }
}