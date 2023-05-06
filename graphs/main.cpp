#include <iostream>
#include <stack>
using namespace std;

void mothervertex(int graph[][10], int n, int s){
    stack<int> stk;
    int visited[10];

    for (int i=1; i<=n; i++){
        visited[i] = 0;
    }

    stk.push(s);
    visited[s] = 1;

    while (!stk.empty()){
        int u = stk.top();
        stk.pop();

        for (int i=1; i<=n; i++){
            if (graph[u][i] == 1 && visited[i] == 0){
                stk.push(i);
                visited[i] = 1;
            }
        }
    }
    for (int i=1; i<=n; i++){
        if (visited[i] == 0)
            return;
    }
    cout << "mother vertex: " << s;
}

int main(){
    int graph[10][10];
    int vertex, edge;
    int p,q;
    cout << "enter number of vertices:";
    cin >> vertex;
    cout << "enter number of edges:";
    cin >> edge;

    for (int i=1; i<=edge; i++){
        cout << "enter source:"; //enter from 1
        cin >> p;
        cout << "enter destination:";
        cin >> q;
        graph[p][q] = 1;
    }

    for (int i=1; i<=vertex; i++){
        mothervertex(graph, vertex, i);
    }
}