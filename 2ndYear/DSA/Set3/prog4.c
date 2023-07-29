#include <stdio.h>

#include <stdlib.h>

 

// Function prototypes for the sorting algorithms

void insertion_sort(int *array, int size);

void selection_sort(int *array, int size);

void bubble_sort(int *array, int size);

void quick_sort(int *array, int low, int high);

void merge_sort(int *array, int low, int high);

void heap_sort(int *array, int size);

 

// Function to print the array at each pass of the sorting algorithm

void print_array(int *array, int size) {

for (int i = 0; i < size; i++) {

printf("%d ", array[i]);

}

printf("\n");

}

 

int main(int argc, char **argv) {

// Read in the size of the array

int size;

printf("Enter the size of the array: ");

scanf("%d", &size);

 

// Read in the elements of the array

int array[size];

printf("Enter the elements of the array: ");

for (int i = 0; i < size; i++) {

scanf("%d", &array[i]);

}

 

// Display the menu and prompt the user to choose a sorting algorithm

int choice;

printf("Select a sorting algorithm:\n");

printf("1. Insertion sort\n");

printf("2. Selection sort\n");

printf("3. Bubble sort\n");

printf("4. Quick sort\n");

printf("5. Merge sort\n");

printf("6. Heap sort\n");

printf("Enter your choice: ");

scanf("%d", &choice);

 

// Call the selected sorting algorithm

switch (choice) {

case 1:

insertion_sort(array, size);

break;

case 2:

selection_sort(array, size);

break;

case 3:

bubble_sort(array, size);

break;

case 4:

quick_sort(array, 0, size - 1);

break;

case 5:

merge_sort(array, 0, size - 1);

break;

case 6:

heap_sort(array, size);

break;

default:

printf("Invalid choice.\n");

break;

}

 

// Print the sorted array

printf("Sorted array: ");

print_array(array, size);

 

return 0;

}

 

// Insertion sort implementation

void insertion_sort(int *array, int size) {

for (int i = 1; i < size; i++) {

int key = array[i];

int j = i - 1;

while (j >= 0 && array[j] > key) {

array[j + 1] = array[j];

j--;

}

array[j + 1] = key;

print_array(array, size); // Print the array after each pass

}

}

// Selection sort implementation

void selection_sort(int *array, int size) {

for (int i = 0; i < size - 1; i++) {

int min_index = i;

for (int j = i + 1; j < size; j++) {

if (array[j] < array[min_index]) {

min_index = j;

}

}

int temp = array[i];

array[i] = array[min_index];

array[min_index] = temp;

print_array(array, size); // Print the array after each pass

}

}

 

// Bubble sort implementation

void bubble_sort(int *array, int size) {

for (int i = 0; i < size - 1; i++) {

for (int j = 0; j < size - i - 1; j++) {

if (array[j] > array[j + 1]) {

int temp = array[j];

array[j] = array[j + 1];

array[j + 1] = temp;

}

}

print_array(array, size); // Print the array after each pass

}

}

 

// Helper function for quick sort

int partition(int *array, int low, int high) {

int pivot = array[high];

int i = low - 1;

for (int j = low; j <= high - 1; j++) {

if (array[j] <= pivot) {

i++;

int temp = array[i];

array[i] = array[j];

array[j] = temp;

}

}

int temp = array[i + 1];

array[i + 1] = array[high];

array[high] = temp;

print_array(array, high - low + 1); // Print the array after each pass

return (i + 1);

}

 

 

// Quick sort implementation

void quick_sort(int *array, int low, int high) {

if (low < high) {

int partition_index = partition(array, low, high);

quick_sort(array, low, partition_index - 1);

quick_sort(array, partition_index + 1, high);

}

}

 

 

// Helper function for merge sort

void merge(int *array, int low, int mid, int high) {

int i, j, k;

int n1 = mid - low + 1;

int n2 = high - mid;

int L[n1], R[n2];

for (i = 0; i < n1; i++) {

L[i] = array[low + i];

}

for (j = 0; j < n2; j++) {

R[j] = array[mid + 1 +j];

}

i = 0;

j = 0;

k = low;

while (i < n1 && j < n2) {

if (L[i] <= R[j]) {

array[k] = L[i];

i++;

} else {

array[k] = R[j];

j++;

}

k++;

}

while (i < n1) {

array[k] = L[i];

i++;

k++;

}

while (j < n2) {

array[k] = R[j];

j++;

k++;

}

print_array(array, high - low + 1); // Print the array after each pass

}

 

// Merge sort implementation

void merge_sort(int *array, int low, int high) {

if (low < high) {

int mid = low + (high - low) / 2;

merge_sort(array, low, mid);

merge_sort(array, mid + 1, high);

merge(array, low, mid, high);

}

}

 

 

 

// Helper function for heap sort

void heapify(int *array, int size, int root) {

int largest = root;

int left = 2 * root + 1;

int right = 2 * root + 2;

 

// If left child is larger than root

if (left < size && array[left] > array[largest]) {

largest = left;

}

 

// If right child is larger than largest so far

if (right < size && array[right] > array[largest]) {

largest = right;

}

 

// If largest is not root

if (largest != root) {

int temp = array[root];

array[root] = array[largest];

array[largest] = temp;

// Recursively heapify the affected sub-tree

heapify(array, size, largest);

}

print_array(array, size); // Print the array after each pass

}

 

// Heap sort implementation

void heap_sort(int *array, int size) {

// Build heap (rearrange array)

for (int i = size / 2 - 1; i >= 0; i--) {

heapify(array, size, i);

}

 

// Extract elements one by one

for (int i = size - 1; i >= 0; i--) {

// Move current root to end

int temp = array[0];

array[0] = array[i];

array[i] = temp;

// Call max heapify on the reduced heap

heapify(array, i, 0);

}

}
