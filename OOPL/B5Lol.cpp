#include <iostream>
#include <string>
#define Cio cout <<
#define Iio cin >>
#define E   endl
using namespace std;

template <class T>
void selectionSort(T a[], int n) {
  for(int i = 0; i < n; i++) {
    int minIdx = i;
    for(int j = i + 1; j < n; j++)
      if(a[j] < a[minIdx]) minIdx = j;
    swap(a[i], a[minIdx]);
  }
}

template <class T>
void inputArray(T a[], int n) {
  Cio "Enter " << n << " elements:\n";
  for(int i = 0; i < n; i++) Cio "a[" << i << "] = ", Iio a[i], Cio;
}

template <class T>
void printArray(T a[], int n) {
  Cio "Sorted array:\n";
  for(int i = 0; i < n; i++) Cio a[i] << " " << E;
}

int main() {
  int choice;
  Cio "Choose type of sorting:\n1. Integer sorting\n2. Float sorting\n3. "
      "String sorting\nEnter your choice: ",
      Iio choice;
  switch(choice) {
    case 1: {
      int n;
      Cio "Enter number of elements: ", Iio n;
      int *intArray = new int[n];
      inputArray(intArray, n);
      selectionSort(intArray, n);
      printArray(intArray, n);
      delete[] intArray;
      break;
    }
    case 2: {
      int n;
      Cio "Enter number of elements: ", Iio n;
      float *floatArray = new float[n];
      inputArray(floatArray, n);
      selectionSort(floatArray, n);
      printArray(floatArray, n);
      delete[] floatArray;
      break;
    }
    case 3: {
      int n;
      Cio "Enter number of elements: ", Iio n;
      string *stringArray = new string[n];
      inputArray(stringArray, n);
      selectionSort(stringArray, n);
      printArray(stringArray, n);
      delete[] stringArray;
      break;
    }
  }
}
