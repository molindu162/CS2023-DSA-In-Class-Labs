#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

vector<int> quickSort(vector<int> arr, int l, int u, int pivot){
    vector<int> a = arr;
    int j = l;
    int i = j - 1;

    if (l >= u ){
        return a;
    }

    while (j <= u){
        if (a[j] < a[pivot]){
            i += 1;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        j += 1;
    }

    i += 1;
    int temp = a[i];
    a[i] = a[pivot];
    a[pivot] = temp;
    int k = i;

    quickSort(a, 0, k - 1, k - 1);
    quickSort(a, k + 1, u, u);
    return a;
}

int main()
{
    int n;
    vector<int> a;
    while(true){
        cout << "Enter the number: ";
        cin >> n;
        double median;
        a.push_back(n);
        vector<int> arr = quickSort(a, 0, a.size() - 1, a.size() - 1);
        if (arr.size() % 2 != 0)
        {
            int mid = floor(arr.size() / 2);
            median = arr[mid];
    }
    else if (arr.size() % 2 == 0){
        int mid = floor(arr.size() / 2);
        median = (arr[mid] + arr[mid - 1]) / 2;
    }
    cout << "Median: ";
    cout << median << endl;
    cout << "Sorted Array: " << endl;
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}
