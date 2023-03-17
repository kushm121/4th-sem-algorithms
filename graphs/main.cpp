#include <iostream>
using namespace std;
#include <queue>

int vertices,edges;

void dfs(int adj[][10], int source, int visited[])
{
    cout << source + 1 << "-> ";
    visited[source] = 1;
    for (int i = 0; i <= vertices; i++)
    {
        if (adj[source][i] == 1 && (!visited[i]))
        {
            dfs(adj, i, visited);
        }
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

    dfs(a, source, visited);
    return 0;
}