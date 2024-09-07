#include <bits/stdc++.h>
using namespace std;

class MergeSort {
public:
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r-l)/2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> sorted(r-l+1);
        int k = 0;
        int i = l;
        int j = m + 1;
        while (i <= m && j <= r) {
            if (nums[i] < nums[j]) {
                sorted[k++] = nums[i++];
            } else {
                sorted[k++] = nums[j++];
            }
        }
        while (i <= m) {
            sorted[k++] = nums[i++];
        }
        while (j <= r) {
            sorted[k++] = nums[j++];
        }
        copy(sorted.begin(), sorted.end(), nums.begin() + l);
    }
};

class HeapSort {
public:
    void heapSort(vector<int>& nums) {
        buildMaxHeap(nums);
        int heapSize = nums.size();
        for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[i], nums[0]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& nums) {
        for (int i = nums.size() / 2; i >= 0; --i)
        maxHeapify(nums, i, nums.size());
    }

    void maxHeapify(vector<int>& nums, int i, int heapSize) {
        const int l = 2 * i + 1;
        const int r = 2 * i + 2;
        int largest = i;
        if (l < heapSize && nums[largest] < nums[l])
            largest = l;
        if (r < heapSize && nums[largest] < nums[r])
            largest = r;
        if (largest != i) {
            swap(nums[largest], nums[i]);
            maxHeapify(nums, largest, heapSize);
        }
    }
};

class QuickSort {
public:
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = partition(nums, l, r);
        quickSort(nums, l, m - 1);
        quickSort(nums, m + 1, r);
    }

    int partition(vector<int>& nums, int l, int r) {
        const int randIndex = rand() % (r - l + 1) + l;
        swap(nums[randIndex], nums[r]);
        const int pivot = nums[r];
        int nextSwapped = l;
        for (int i = l; i < r; ++i)
        if (nums[i] <= pivot)
            swap(nums[nextSwapped++], nums[i]);
        swap(nums[nextSwapped], nums[r]);
        return nextSwapped;
    }
};