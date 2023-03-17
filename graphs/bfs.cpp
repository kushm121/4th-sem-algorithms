#include <iostream>
using namespace std;
#include <queue>

int vertices,edges;

void bfs(int adj[10][10], int source, int visited[]){
    queue<int> q;
    q.push(source);
    visited[source-1] = 1;
    int node;

    while (!q.empty()){
        node = q.front();
        q.pop();
        cout << node << "->";

        for (int i=0; i<vertices; i++){
            if (adj[node-1][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                q.push(i+1);
            }
        }
        visited[node-1] = 1;
    }

}

int main(){
    int a[10][10], n, m, x, i, j;
    int source;
    int visited[10] = {0};
    cout << "Enter Number of Vertices : ";
    cin >> vertices;
    cout << "Enter Number of Edges : ";
    cin >> edges;
    for (i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            a[i][j] = 0;
    int p, q;
    for (i = 1; i <= edges; i++)
    {
        cout << "Enter Source :";
        cin >> p;
        cout << "Enter Destination :";
        cin >> q;
        a[p - 1][q - 1] = 1;
    }
    cout << "\nThe Adjacency Matrix is : \n\n";
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout  << "enter source:";
    cin >> source;

    bfs(a, source, visited);
    return 0;
}
