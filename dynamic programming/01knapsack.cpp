#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void knapsack(int n, int profit[], int weight[],int capacity){
    int mat[n][capacity+1]; //rows go in reverse order

    for (int i=n-1; i>=0; i--){
        if (i == n-1){ //for first iteration
            for (int j=0; j<=capacity; j++){
                if (j >= weight[i]) //item can be accommodated
                    mat[i][j] = profit[i];

                else
                    mat[i][j] = 0;
            }
        }

        else{
            for (int j=0; j<= capacity; j++){
                if(j >= weight[i]) //item can be accommodated
                    mat[i][j] = max(mat[i+1][j], mat[i+1][j - weight[i]] + profit[i]);

                else //item cannot be accommodated
                    mat[i][j] = mat[i+1][j]; //putting previous value
            }
        }
    }

    cout << "\n";
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<=capacity; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    cout << "profit: " << mat[0][capacity]; //last value in matrix
}

int main(){
    int n, capacity;
    cout << "enter number of items: ";
    cin >> n;
    int profit[n], weight[n];
    cout << "enter capacity: ";
    cin >> capacity;

    for (int i=0; i<n; i++){
        cout << "enter profit for item " << i << ": ";
        cin >> profit[i];
        cout << "enter weight for item " << i << ": ";
        cin >> weight[i];
    }

    knapsack(n, profit, weight, capacity);
}
