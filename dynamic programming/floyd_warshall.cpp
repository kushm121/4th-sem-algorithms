#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(int graph[0][10], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                if (j == k){
                    graph[j][k] = 0;
                }

                else{
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                }
            }
        }
    }

    cout << "shortest path: \n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << i << " --> " << j << " = " << graph[i][j] << "\n";
        }
    }
}

int main(){
    int n, val;
    cout << "enter number of vertices: ";
    cin >> n;
    int graph[10][10];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << "enter value: "; //-1 for infinite
            cin >> val;
            if (val == -1){
                graph[i][j] = 999;
            }

            else{
                graph[i][j] = val;
            }
        }
    }

    cout <<"\n";
    floyd_warshall(graph, n);
}
