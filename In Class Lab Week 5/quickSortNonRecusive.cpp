#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

int partitioning(int arr[], int l, int u, int pivot)
{
    int x = arr[u];
    int i = (l - 1);

    for (int j = l; j <= u - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[u];
    arr[u] = temp;
    return (i + 1);
}


void quickSort(int arr[], int l, int u, int pivot)
{
    int array[u - l + 1];

    int i = -1;

    array[++i] = l;
    array[++i] = u;

    while (i >= 0)
    {
        u = array[i--];
        l = array[i--];


        int p = partitioning(arr, l, u, pivot);


        if (p - 1 > l)
        {
            array[++i] = l;
            array[++i] = p - 1;
        }


        if (p + 1 < u)
        {
            array[++i] = p + 1;
            array[++i] = u;
        }
    }
}

int  main(){

    int sz = 20;
    int a[sz];
    for (int i = 0; i < sz; i++)
        a[i] = rand() % 100;


    cout << endl;

    auto start = high_resolution_clock::now();

    quickSort(a, 0, sz - 1, sz - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl;

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}
