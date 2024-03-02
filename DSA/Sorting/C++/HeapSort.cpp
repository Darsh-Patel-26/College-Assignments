#include"iostream"
#include"sys\time.h"
#include"vector"

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i, 
    left = 2*i + 1,
    right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        std::swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // creating heap
    for(int i = n/2 - 1; i>=0; i--) {
        heapify(arr,n,i);
    }

    // sorting
    for(int i = n - 1; i >= 0; i--) {
        std::swap(arr[i], arr[0]);
        heapify(arr,i,0);
    }
}

int main() {
    std::vector<int> arr;
    struct timeval t1,t2;
    for(int i = 0; i< 100000; i++) {
        arr.push_back(rand()%10000);
    }

    gettimeofday(&t1,nullptr);
    heapSort(arr);
    gettimeofday(&t2,nullptr);

    printf("%ld MS",t2.tv_sec-t1.tv_sec);

    return 0;
}