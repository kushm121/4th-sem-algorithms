#include<iostream>
using namespace std;

int main(){
    int vertices, edges;
    int src,dst;
    int mat[10][10] = {0}, indegree[10] = {0}, flag[10] = {0};
    cout << "enter number of vertices:";
    cin >> vertices;
    cout << "enter number of edges:";
    cin >> edges;

    for(int i=0; i<edges; i++)
    {
        cout << "enter source:";
        cin>> src;
        cout << "enter destination:";
        cin>> dst;
        mat[src][dst]=1;
    }

    for(int i=1; i<=vertices; i++)
        for(int j=1; j<=vertices; j++){
            indegree[i]=indegree[i]+mat[j][i];
        }

    cout << "topological sort:";
    int count=0;
    while(count<vertices)
    {
        for(int k=1; k<=vertices; k++)
        {
            if((indegree[k]==0) && (flag[k]==0))
            {
                cout << k << " ";
                flag [k]=1;
            }

            for(int i=1; i<=vertices; i++)
            {
                if(mat[i][k]==1)
                    indegree[k]--;
            }
        }
        count++;
    }
}
