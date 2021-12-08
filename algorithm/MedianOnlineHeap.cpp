#include <iostream>
using namespace std;

void maxHeap(int heap[], int s, bool state) {
    if (state) {   
        int idx = s-1;
        while (idx > 1) { 
            if (heap[idx/2] < heap[idx]) {
                int temp = heap[idx/2];
                heap[idx/2] = heap[idx];
                heap[idx] = temp;
            }
            else break;
            idx /= 2;
        }
    }
    else {
        int idx = 1;
        while (idx <= (s-1)/2){
            int m = idx*2;
            if (s > idx*2+1 && heap[idx*2] < heap[idx*2+1]) m = idx*2+1;
            idx = m;
            if (heap[idx/2] < heap[idx]) {
                int temp = heap[idx/2];
                heap[idx/2] = heap[idx];
                heap[idx] = temp;
            }
            else break;
        }
    }
}

void minHeap(int heap[], int s, bool state) {
    if (state) {
        int idx = s-1;
        while (idx != 1){
            if (heap[idx/2] > heap[idx]) {
                int temp = heap[idx/2];
                heap[idx/2] = heap[idx];
                heap[idx] = temp;
            } 
            else break;
            idx /= 2;
        }
    }
    else{
        int idx = 1;
        while (idx <= (s-1)/2){
            int m = idx*2;
            if (s > idx*2+1 && heap[idx*2] > heap[idx*2+1]) m = idx*2+1;
            idx = m;
            if (heap[idx/2] > heap[idx]) {
                int temp = heap[idx/2];
                heap[idx/2] = heap[idx];
                heap[idx] = temp;
            }
            else break;
        }
    }
}

int main() {
    int testCase, k, n;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        int answer = 0;
        
        cin >> k;
        cin >> n;
        int max_heap[k+1];
        int min_heap[k+1];

        for (int idx = 0; idx < k+1; idx++){
            max_heap[idx] = 0;
            min_heap[idx] = 0;
        } 

        int max_size = 1;
        int min_size = 1;

        max_heap[max_size++] = n;
        answer += max_heap[1]%10;

        for (int j = 1; j < k; j++) {
            cin >> n;
            if (n < max_heap[1]) {
                max_heap[max_size++] = n;
                maxHeap(max_heap, max_size, true);
            }
            else {
                min_heap[min_size++] = n;
                minHeap(min_heap, min_size, true);
            }

            if (max_size < min_size) {
                max_heap[max_size++] = min_heap[1];
                maxHeap(max_heap, max_size, true);

                min_heap[1] = min_heap[min_size-1];
                min_heap[min_size--] = 0;
                minHeap(min_heap, min_size, false);
            }
            else if (max_size > min_size+1) {
                min_heap[min_size++] = max_heap[1];
                minHeap(min_heap, min_size, true);

                max_heap[1] = max_heap[max_size-1];
                max_heap[max_size--] = 0;
                maxHeap(max_heap, max_size, false);
            }

            if ((max_size+min_size)%2 == 0) answer += ((max_heap[1]+min_heap[1])/2)%10;
            else answer += max_heap[1]%10;
        }
        cout << answer%10 << '\n';
    }
}