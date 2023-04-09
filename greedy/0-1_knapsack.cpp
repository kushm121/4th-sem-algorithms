#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class item{
public:
    int weight;
    int cost;
    int position;
    float density;
};

void bubbleSort(item items[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (items[j].density < items[j+1].density)
            {
                swap(items[j], items[j+1]);
            }
}


int main(){
    int n;
    int capacity;
    cout << "enter number of items:";
    cin >> n;
    cout << "enter capacity:";
    cin >> capacity;
    item items[n];
    int w,c;
    int total_cost = 0;
    int x[10] = {0};

    for (int i=0; i<n; i++){
        cout << "enter weight:";
        cin >> w;
        items[i].weight = w;
    }

    for (int i=0; i<n; i++){
        cout << "enter cost:";
        cin >> c;
        items[i].cost = c;
        items[i].density = (items[i].cost / items[i].weight);
        items[i].position = i;
    }

    bubbleSort(items, n);

    for (int i=0; i<n && items[i].weight <= capacity; i++){
        x[items[i].position] = 1;
        capacity -= items[i].weight;
        total_cost += items[i].cost;
    }

    cout << "items selected:";
    for (int i=0; i<n; i++){
        cout << x[i] << " ";
    }

    cout << "total cost:" << total_cost;
}
