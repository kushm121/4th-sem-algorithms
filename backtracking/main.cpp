#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int graph[50][50];
vector<int> maxclique;

bool isclique(vector<int> clique)
{
    for (int i = 0; i < clique.size(); i++)
    {
        for (int j = i + 1; j < clique.size(); j++)
        {
            if (graph[clique[i]][clique[j]] != 1)
            {
                return false;
            }
        }
    }
    return true;
}
void findmaxclique(vector<int> candidates, vector<int> clique)
{
    if (candidates.empty())
    {
        if (isclique(clique) && clique.size() > maxclique.size())
        {
            maxclique = clique;
        }
        return;
    }
    if (clique.size() + candidates.size() <= maxclique.size())
    {
        return;
    }
    int v = candidates.back();
    candidates.pop_back();
    findmaxclique(candidates, clique);
    clique.push_back(v);
    if (isclique(clique))
    {
        findmaxclique(candidates, clique);
    }
}
int main()
{
    int n,m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cout << "enter source: ";
        cin >> a;
        cout << "enter destination: ";
        cin >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    vector<int> candidates;
    vector<int> clique;
    for (int i = 0; i < n; i++)
    {
        candidates.push_back(i);
    }

    findmaxclique(candidates, clique);
    cout << "max clique: ";
    for (int i = 0; i < maxclique.size(); i++)
    {
        cout << maxclique[i] << " ";
    }

    cout << "\n size of max clique: " << maxclique.size();
}