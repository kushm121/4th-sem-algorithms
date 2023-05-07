#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void tsp(int graph[][4], bool visited[], int pos, int n, int count, int cost, int cities[], int index, int &ans){
    if (count == n && graph[pos][0]){
        ans = min(ans, cost + graph[pos][0]);
        cities[index] = pos;
        return;
    }

    for (int i=0; i<n; i++){
        if (!visited[i] && graph[pos][i]){
            visited[i] = true;
            cities[index++] = pos;
            tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], cities, index, ans);
            visited[i] = false; //marking it false for backtracking
            index--;
        }
    }
}

int main(){
    int n = 4, pos = 0, count = 1, cost = 0;
    bool visited[4] = {true};
    int ans = INT_MAX;
    int cities[4] = {0};
    int graph[4][4] = {
            {0, 30, 6, 4},
            {30, 0, 5, 10},
            {6, 5, 0, 20},
            {4, 10, 20, 0}
    };

    tsp(graph, visited, 0, n, 1, 0, cities, 0, ans);
    cout << "cost: " << ans << "\n";

    for (int i=0; i<n; i++){
        cout << cities[i] << " -> ";
    }
}