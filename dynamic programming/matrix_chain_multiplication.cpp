#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "enter number of elements in r matrix: ";
    cin >> n;
    int r[n];
    for (int i=0; i<n; i++){
        cout << "enter element of r matrix: ";
        cin >> r[i];
    }

    int mat[n-1][n-1], kay[n-1][n-1];
    for(int i=0; i<n-1; i++){
        for (int j=0; j<n-1; j++){
            mat[i][j] = 0;
            kay[i][j] = 0;
        }
    }

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1; j++){
            if (i == j){
                mat[i][j] = 0;
                kay[i][j] = 0;
            }

            else if (j == i+1){
                mat[i][j] = r[i] * r[i+1] * r[i+2];
                kay[i][j] = i+1;
            }
        }
    }

    for (int x=0; x<n-2; x++){ //this loop is for 0,n-2th element
        for (int i=0; i<n-1; i++){
            for (int j=0; j<n-1; j++){
                if (j > i && j != i+1){
                    int min = INT_MAX;
                    for (int k=i; k<=j; k++){
                        int temp = mat[i][k] + mat[k+1][j] + (r[i] * r[k+1] * r[j+1]);
                        if (temp < min){
                            min = temp;
                            mat[i][j] = min;
                            kay[i][j] = k+1;

                        }
                    }
                }
            }
        }
    }

    cout << "\n matrix: \n";
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    cout << "kay matrix: \n";
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1; j++){
            cout << kay[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    cout << "total computations = " << mat[0][n-2];
}
