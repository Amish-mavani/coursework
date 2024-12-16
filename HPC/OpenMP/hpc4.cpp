#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

// Odd-even transposition sort
void oddEvenTranspositionSort(std::vector<int>& arr) {
    int n = arr.size();
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        
        #pragma omp parallel for
        for (int i = 1; i < n-1; i += 2) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
                sorted = false;
            }
        }
        
        #pragma omp parallel for
        for (int i = 0; i < n-1; i += 2) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
                sorted = false;
            }
        }
    }
}

// Quick sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low-1;
        
        #pragma omp parallel for
        for (int j = low; j <= high-1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        
        std::swap(arr[i+1], arr[high]);
        
        int pi = i+1;
        
        #pragma omp task
        quickSort(arr, low, pi-1);
        #pragma omp task
        quickSort(arr, pi+1, high);
    }
}

// Bitonic sort
void bitonicSort(std::vector<int>& arr, int low, int count, bool direction) {
    if (count > 1) {
        int k = count / 2;
        
        #pragma omp parallel sections
        {
            #pragma omp section
            bitonicSort(arr, low, k, true);
            #pragma omp section
            bitonicSort(arr, low+k, k, false);
        }
        
        #pragma omp parallel for
        for (int i = low; i < low+k; i++) {
            if (direction == (arr[i] > arr[i+k]))
                std::swap(arr[i], arr[i+k]);
        }
    }
}

int main() {
    int n = 10000;
    std::vector<int> arr(n);
    
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
    
    // Odd-even transposition sort
    std::vector<int> odd_even_arr = arr;
    double start_time = omp_get_wtime();
    oddEvenTranspositionSort(odd_even_arr);
    double end_time = omp_get_wtime();
    std::cout << "Odd-even transposition sort time: " << end_time - start_time << std::endl;
    
    // Quick sort
    std::vector<int> quick_arr = arr;
    start_time = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        quickSort(quick_arr, 0, n-1);
    }
    end_time = omp_get_wtime();
    std::cout << "Quick sort time: " << end_time - start_time << std::endl;
    // Bitonic sort
    std::vector<int> bitonic_arr = arr;
    start_time = omp_get_wtime();
    bitonicSort(bitonic_arr, 0, n, true);
    end_time = omp_get_wtime();
    std::cout << "Bitonic sort time: " << end_time - start_time << std::endl;
    return 0;
}
