#include <stdbool.h>
#include <stdio.h>
#define size(name, type) sizeof(name) / sizeof(type)
void selection_sort(int *arr, int lim);
void bubble_sort(int *arr, int lim);
void swap(int *, int *);
void insertion_sort(int *arr, int lim);
void merge_sort(int *arr, int lim);
void merge(int *arr, int *left, int left_lim, int *right, int right_lim);
void quick_sort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void display(int *arr, int lim);
int main(void) {
  int arr[] = {9, 6, 2, 3, 6, 8, 2, 1, 4, 5};
  size_t lim = size(arr, int);
  display(arr, lim);
  quick_sort(arr, 0, lim - 1);
  display(arr, lim);
  return 0;
}
void selection_sort(int *arr, int lim) {
  int i, j;
  for (i = 0; i < lim - 1; ++i) {
    int min = i;
    for (j = i + 1; j < lim - 1; ++j) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(&arr[i], &arr[min]);
  }
}
void bubble_sort(int *arr, int lim) {
  int i, j;
  for (i = 0; i < lim - 1; ++i) {
    bool flag = false;
    for (j = 0; j < lim - i - 1; ++j) {
      if (arr[j + 1] < arr[j]) {
        swap(&arr[j + 1], &arr[j]);
        flag = true;
      }
    }
    if (!flag) {
      break;
    }
  }
  return;
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}
void insertion_sort(int *arr, int lim) {
  int i, j;
  for (i = 1; i < lim; ++i) {
    int value = arr[i];
    for (j = i; j > 0 && arr[j - 1] > value; --j) {
      arr[j] = arr[j - 1];
    }
    arr[j] = value;
  }
  return;
}
void merge_sort(int *arr, int lim) {
  if (lim < 2) {
    return;
  }
  int mid, left_lim, right_lim;
  mid = lim / 2;
  left_lim = mid - 0;
  right_lim = lim - mid;
  int left[left_lim];
  int right[right_lim];
  for (int i = 0; i < left_lim; ++i) {
    left[i] = arr[i];
  }
  for (int i = 0; i < right_lim; ++i) {
    right[i] = arr[mid + i];
  }
  merge_sort(left, left_lim);
  merge_sort(right, right_lim);
  merge(arr, left, left_lim, right, right_lim);
  return;
}
void merge(int *arr, int *left, int left_lim, int *right, int right_lim) {
  int i, j, k;
  i = j = k = 0;
  while (i < left_lim && j < right_lim) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }
  while (i < left_lim) {
    arr[k++] = left[i++];
  }
  while (j < right_lim) {
    arr[k++] = right[j++];
  }
  return;
}
void quick_sort(int *arr, int low, int high) {
  if (low < high) {
    int part_i = partition(arr, low, high);
    quick_sort(arr, low, part_i - 1);
    quick_sort(arr, part_i + 1, high);
  }
  return;
}
int partition(int *arr, int low, int high) {
  int pivot_i = high;
  int part_i = low;
  for (int i = low; i < high; ++i) {
    if (arr[i] < arr[pivot_i]) {
      swap(&arr[part_i], &arr[i]);
      ++part_i;
    }
  }
  swap(&arr[part_i], &arr[pivot_i]);
  return part_i;
}
void display(int *arr, int lim) {
  for (int i = 0; i < lim; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return;
}
