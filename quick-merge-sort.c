#include <stdio.h>
// Swap function
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Print array
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}
// Partition function
int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j < high; j++) {
if (arr[j] <= pivot) {
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
int main() {
int n, choice;
printf("Enter number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter %d elements: ", n);
for (int i = 0; i < n; i++)
scanf("%d", &arr[i]);
do {
printf("\nMenu:\n");
printf("1. Quick Sort\n");
printf("2. Display Array\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
quickSort(arr, 0, n - 1);
printf("Array sorted using Quick Sort.\n");
break;
case 2:
printf("Array: ");
printArray(arr, n);
break;
case 3:
printf("Exiting program...\n");
break;
default:
printf("Invalid choice!\n");
}
} while (choice != 3);
return 0;
}

#include <stdio.h>
// Print array
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}
// Merge two halves
void merge(int arr[], int left, int mid, int right) {
int n1 = mid - left + 1;
int n2 = right - mid;
int L[n1], R[n2];
for (int i = 0; i < n1; i++)
L[i] = arr[left + i];
for (int j = 0; j < n2; j++)
R[j] = arr[mid + 1 + j];
int i = 0, j = 0, k = left;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}
}
// Merge Sort function
void mergeSort(int arr[], int left, int right) {
if (left < right) {
int mid = left + (right - left) / 2;
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
merge(arr, left, mid, right);
}
}
int main() {
int n, choice;
printf("Enter number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter %d elements: ", n);
for (int i = 0; i < n; i++)
scanf("%d", &arr[i]);
do {
printf("\nMenu:\n");
printf("1. Merge Sort\n");
printf("2. Display Array\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
mergeSort(arr, 0, n - 1);
printf("Array sorted using Merge Sort.\n");
break;
case 2:
printf("Array: ");
printArray(arr, n);
break;
case 3:
printf("Exiting program...\n");
break;
default:
printf("Invalid choice!\n");
}
} while (choice != 3);
return 0;
}