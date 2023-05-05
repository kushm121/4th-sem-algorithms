#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minindex(int dist[], bool visited[], int n){
    int min = INT_MAX;
    int index = 0;

    for (int i=0; i<n; i++){
        if (!visited[i] && dist[i] < min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[][5], int source, int n){
    int distance[5];
    bool visited[5];

    for (int k = 0; k < n; k++)
    {
        distance[k] = INT_MAX;
        visited[k] = false;
    }

    distance[source] = 0;

    for (int i = 0; i < n; i++)
    {
        int m = minindex(distance, visited, n);
        visited[m] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && graph[m][j] && distance[m] != INT_MAX && distance[m] + graph[m][j] < distance[j])
                distance[j] = distance[m] + graph[m][j];
        }
    }

    cout << "vertex  distance" << "\n";
    for (int i=0; i<n; i++){
        cout << i << "  " << distance[i];
        cout << "\n";
    }
}

int main(){
    int n;
    cout << "enter n:";
    cin >> n;
    int graph[5][5];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << "enter weight for " << i << "," << j << " :";
            cin >> graph[i][j]; //enter 0 for infinite
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    int source;
    cout << "enter source:";
    cin >> source;
    cout << "\n";
    dijkstra(graph, source, n);
}
