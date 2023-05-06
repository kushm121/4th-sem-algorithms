#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void minmax(int arr[], int low, int high, int *min, int *max){
    if (low == high){ //1 element in array
        *min = *max = arr[low];
    }

    else if(high == low+1){ //2 elements in array
        if (arr[low] >= arr[high]){
            *max = arr[low];
            *min = arr[high];
        }

        else{
            *max = arr[high];
            *min = arr[low];
        }
    }

    else{
        int mid = (low + high) / 2;
        int min1, min2, max1, max2;
        minmax(arr, low, mid, &min1, &max1);
        minmax(arr, mid+1, high, &min2, &max2);

        if (min1 <= min2){
            *min = min1;
        }
        else{
            *min = min2;
        }

        if (max1 >= max2){
            *max = max1;
        }
        else{
            *max = max2;
        }
    }
}

int main(){
    int arr[10] = {1,10,2,9,3,8,4,7,5,6};
    int low = 0;
    int high = 10;
    int min,max;

    minmax(arr, 0, 9, &min, &max);
    cout << "min: " << min;
    cout << "\n";
    cout << "max: " << max;
}