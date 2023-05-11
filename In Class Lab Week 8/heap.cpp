#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int max = root;
   int left = 2 * root + 1;
   int right = 2 * root + 2;
   if (left <= n && arr[root] < arr[left])
   {
      max = left;
   }
   if (right <= n && arr[max] < arr[right])
   {
      max = right;
   }
   if (max != root)
   {
      int temp = arr[root];
      arr[root] = arr[max];
      arr[max] = temp;
      heapify(arr, n, max);
   }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int firstKey = (n / 2) - 1;
   for (int i = firstKey; i >= 0; i--)
   {
      heapify(arr, n, i);
   }

   // extracting elements from heap one by one
   for (int j = n - 1; j > 0; j--)
   {
      int temp = arr[j];
      arr[j] = arr[0];
      arr[0] = temp;
      heapify(arr, j, 0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int size;
   cin >> size;

   int heap_arr[size];

   for (int i = 0; i < size; i++)
   {
      cin >> heap_arr[i];
   }

   cout << "Input array" << endl;
   displayArray(heap_arr, size);

   heapSort(heap_arr, size);

   cout << "Sorted array" << endl;
   displayArray(heap_arr, size);
}