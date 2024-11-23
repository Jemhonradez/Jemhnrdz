// Title: Superhero Mission Control - Heap Challenge
// Theme: Manage priority tasks in a superhero mission control using heaps!

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap {
private:
    vector<int> heap;
    bool isMaxHeap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (parent >= 0 && ((isMaxHeap && heap[index] > heap[parent]) || (!isMaxHeap && heap[index] < heap[parent]))) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int target = index;

        if (left < heap.size() && ((isMaxHeap && heap[left] > heap[target]) || (!isMaxHeap && heap[left] < heap[target]))) {
            target = left;
        }

        if (right < heap.size() && ((isMaxHeap && heap[right] > heap[target]) || (!isMaxHeap && heap[right] < heap[target]))) {
            target = right;
        }

        if (target != index) {
            swap(heap[index], heap[target]);
            heapifyDown(target);
        }
    }

public:
    Heap(bool maxHeap = true) : isMaxHeap(maxHeap) {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Added task with priority " << value << (isMaxHeap ? " to Max-Heap" : " to Min-Heap") << ".\n";
    }

    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty. Nothing to delete.\n";
            return;
        }
        cout << "Removing task with priority " << heap[0] << (isMaxHeap ? " from Max-Heap" : " from Min-Heap") << ".\n";
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void displayHeap() {
        cout << "Heap: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << "\n";
    }

    void buildHeap(vector<int>& arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
        cout << "Heap built from array.\n";
    }
};

int main() {
    cout << "Welcome to the Superhero Mission Control - Heap Challenge!\n\n";

    Heap maxHeap(true); // Max-Heap for high-priority tasks
    Heap minHeap(false); // Min-Heap for low-priority tasks

    // Task 1: Insert elements into a heap
    cout << "Task 1: Insert tasks into a Max-Heap.\n";
    maxHeap.insert(50);
    maxHeap.insert(30);
    maxHeap.insert(70);
    maxHeap.insert(20);
    maxHeap.displayHeap();

    // Task 2: Delete the root and restore heap property
    cout << "\nTask 2: Delete the highest-priority task from the Max-Heap.\n";
    maxHeap.deleteRoot();
    maxHeap.displayHeap();

    // Task 3: Heapify a random array
    cout << "\nTask 3: Build a Min-Heap from a list of task priorities.\n";
    vector<int> priorities = {40, 10, 50, 30, 20};
    minHeap.buildHeap(priorities);
    minHeap.displayHeap();

    return 0;
}