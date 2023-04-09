#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int capacity;
    int n;
    cout << "enter number of containers:";
    cin >> n;
    cout << "enter capacity:";
    cin >> capacity;
    int x[10] = {0};
    int weights[n];
    for (int i=0; i<n; i++){
        cout << "enter weights:";
        cin >> weights[i];
    }

    sort(weights, weights + n); //time complexity O(nlogn)

    for (int i=0; i<n; i++){
        if ((capacity - weights[i]) >= 0){
            capacity -= weights[i];
            x[i] = 1;
        }
    }

    cout << "selected items:";
    for (int i=0; i<n; i++){
        cout << x[i] << " ";
    }
}
