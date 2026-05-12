#include <iostream>
#include <algorithm>
using namespace std;

//--Insertion Sort--
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
    int key = arr[i];
     int j = i - 1;
       while (j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
    j--;
}
arr[j + 1] = key;
  }
}
//--Selection Sort--
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n-1; i++) {
  int minIndex = i;
        for (int j = i+1; j  < n; j++) {
        if (arr[j] < arr[minIndex]){
        minIndex = j;
            }
        }
        int temp = arr[minIndex];
         arr[minIndex] = arr[i];
          arr[i] = temp;
 }
}
//--Marge Sort--
 void merge (int arr[], int left, int mid, int right) {
  int start = mid - left + 1;
  int end = right - mid;
int L[start], R[end];
  for (int i = 0; i < start; i++)
  L[i] = arr[left + i];
    for (int j = 0; j < end; j++)
  R[j] = arr[mid + 1 + j];
int i = 0,  j = 0,  k = left;
while (i < start && j < end) {
if (L[i] <= R[j]) {
   arr[k] = L[i];
   i++;
    }
   else {
     arr[k] = R[j];
     j++;
   }
k++;
}
while (i < start) {
arr[k] = L[i];
  i++;
  k++;
}
while (j < end) {
arr[k] = R[j];
 j++;
  k++;
  }
}
void mergeSort(int arr[], int left, int right) {
   if (left < right) {
int mid = left + (right - left) / 2;
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
merge(arr, left, mid, right);
     }
}
//--Quick Sort--
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
        i++;
        swap (arr[i], arr[j]);
    }
}
   swap (arr[i + 1], arr[high] );
return (i + 1);
}
void quickSort (int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high)  ;
        quickSort (arr, low, pi - 1);
         quickSort (arr, pi + 1, high);
    }
}
// -- Fractional Knapsack --
struct Item {
       int profit, weight;
};
bool cmp(Item a, Item b) {
     double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
     return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n) {
                  sort(arr, arr+n, cmp);
            double totalProfit = 0.0;
             for (int i = 0; i < n; i++) {
             if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalProfit += arr[i].profit;
           } else {
            totalProfit +=arr[i].profit * ((double)W / arr[i].weight);
             break;
    }
    }
    return totalProfit;
}
//-- 0/1 Knapsack (Dynamic Programming) --
int knapsack(int weights[], int values[], int n, int capacity) {
              int dp[n+1][capacity+1];
            for (int i = 0; i <= n; i++) {
                  for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][capacity];
}
int main() {
// Insertion Sort
    int arr1[] = {25, 45, 15, 5, 35};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
     cout << "Original array (Insertion Sort): ";
       for (int i = 0; i < n1; i++) cout << arr1[i] << " ";
    cout << endl;
    insertionSort(arr1, n1);
     cout << "Sorted array (Insertion Sort): ";
       for (int i = 0; i < n1; i++) cout << arr1[i] << " ";
    cout << endl << endl;
// Selection Sort
    int arr2[] = {18, 68, 48, 8, 88, 28};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
     cout << "Original array (Selection Sort): ";
       for (int i = 0; i < n2; i++) cout << arr2[i] << " ";
    cout << endl;
    selectionSort(arr2, n2);
      cout << "Sorted array (Selection Sort): ";
        for (int i = 0; i < n2; i++) cout << arr2[i] << " ";
    cout << endl << endl;
// Merge Sort
    int arr3[] = {80, 10, 40, 20, 60, 30};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
       cout << "Original array (Merge Sort): ";
         for (int i = 0; i < n3; i++) cout << arr3[i] << " ";
    cout << endl;
    mergeSort(arr3, 0, n3-1);
      cout << "Sorted array (Merge Sort): ";
        for (int i = 0; i < n3; i++) cout << arr3[i] << " ";
    cout << endl << endl;
// Quick Sort
    int arr4[] = {44, 50, 48, 42, 46};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
       cout << "Original array (Quick Sort): ";
         for (int i = 0; i < n4; i++) cout << arr4[i] << " ";
    cout << endl;
    quickSort(arr4, 0, n4-1);
       cout << "Sorted array (Quick Sort): ";
         for (int i = 0; i < n4; i++) cout << arr4[i] << " ";
    cout << endl;
// Fractional Knapsack
    Item items[] = {{60,10}, {100,20}, {120,30}, {50,5}};
     int W = 20;
     int n5 = sizeof(items)/sizeof(items[0]);
    cout << "Maximum Profit (Fractional Knapsack, capacity " << W << ") = "
         << fractionalKnapsack(W, items, n5) << endl << endl;
// 0/1 Knapsack
    int weights[] = {2, 7, 5, 8};
    int values[] = {1, 6, 3, 7};
    int n6 = 4;
    int capacity = 6;
    cout << "Maximum Profit (0/1 Knapsack, capacity " << capacity << ") = "
         << knapsack(weights, values, n6, capacity) << endl;
return 0;
}
