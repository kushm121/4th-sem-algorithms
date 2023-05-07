#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int container(int weight[], int capacity, int n){
    if (capacity == 0 || n == 0)
        return 0;

    else if (weight[n-1] > capacity)
        return container(weight, capacity, n-1);

    else
        return max(1 + container(weight, capacity - weight[n-1], n-1), container(weight, capacity, n-1));
}

int main(){
    int n, capacity;
    cout << "enter number of containers: ";
    cin >> n;
    cout << "enter capacity: ";
    cin >> capacity;
    int weight[n];

    for (int i=0; i<n; i++){
        cout << "enter weight: ";
        cin >> weight[i];
    }

    cout << "\n containers loaded: " << container(weight, capacity, n);
}