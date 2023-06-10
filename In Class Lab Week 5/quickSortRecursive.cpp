#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using namespace std::chrono;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitioning(int arr[], int l, int u, int pivot){
    int i = l - 1;

    for (int j = l; j < u; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i += 1;
            swap(&arr[i], &arr[j]);
        }
    }
    return i + 1;
}

void quickSort(int arr[], int l, int u, int pivot){

    if (l >= u ){
        return;
    }

    int i = partitioning(arr, l, u, pivot);
    swap(&arr[i], &arr[pivot]);
    int k = i;

    quickSort(arr, 0, k - 1, k - 1);
    quickSort(arr, k + 1, u, u);
}

int main(){
    int sz = 100;
    int a[sz];
    for (int i = 0; i < sz; i++)
        a[i] = rand() % 100;

    auto start = high_resolution_clock::now();

    quickSort(a, 0, sz - 1, floor(sz / 2));
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl;

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}