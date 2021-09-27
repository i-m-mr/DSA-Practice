#include <bits/stdc++.h>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  vector<int> L;
  vector<int> M;

  for (int i = p; i <= q; i++) {
    L.push_back(arr[i]);
  }
  for (int j = q+1; j <=r ; j++)
    M.push_back(arr[j]);

  // Maintain current index of sub-arrays and main array
  int n1 = L.size(), n2 = M.size();
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver program
int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }

  mergeSort(arr, 0, n - 1);

  cout << "Sorted array: \n";
  printArray(arr, n);
  return 0;
}