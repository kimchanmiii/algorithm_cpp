#include <iostream>
using namespace std;

int cnt[4] = {0, 0, 0, 0};

int partition_hoare(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
            cnt[2]++;
        } while (arr[i] < pivot);
        do {
            j--;
            cnt[2]++;
        } while (arr[j] > pivot);
        if (i < j) {
            swap(arr[i], arr[j]);
            cnt[0]++;
        }
        else { return j; }
    }
}

void hoare (int arr[], int low, int high) 
{
    if (high <= low) return;
    int k = partition_hoare(arr, low, high);
    hoare(arr, low, k);
    hoare(arr, k+1, high);
}

int partition_lomuto(int arr[], int low, int high) 
{
    int pivot = arr[low];
    int j = low;

    for (int i = low+1; i <= high; i++) {
        cnt[3]++;
        if (arr[i] < pivot) {
            j++;
            swap(arr[i], arr[j]);
            cnt[1]++;
        }
    }

    int pivot_pos = j;
    swap(arr[pivot_pos], arr[low]);
    cnt[1]++;
    return pivot_pos;
}

void lomuto (int arr[], int low, int high)
{
    if (low >= high) return;
    int k = partition_lomuto(arr, low, high);
    lomuto(arr, low, k-1);
    lomuto(arr, k+1, high);
}

int main() {
    int testCase;

    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int n, k;    
        cin >> n;
        int arr1[n];
        int arr2[n];

        for (int j = 0; j < 4; j++) {
            cnt[j] = 0;
        }

        for (int j = 0; j < n; j++) {
            cin >> arr1[j];
            arr2[j] = arr1[j];
        }

        hoare(arr1, 0, n-1);
        lomuto(arr2, 0, n-1);

        for (int j = 0; j < 4; j++) {
            cout << cnt[j] << " ";
        }
        cout << '\n';
    }
}