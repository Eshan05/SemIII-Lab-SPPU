#include <iostream>
#include <string>
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
  cout << "Enter " << n << " elements:\n";
  for(int i = 0; i < n; i++) {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
}

template <class T>
void printArray(T a[], int n) {
  cout << "Sorted array:\n";
  for(int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}

int main() {
  int choice;
  cout << "Choose type of sorting:\n";
  cout << "1. Integer sorting\n";
  cout << "2. Float sorting\n";
  cout << "3. String sorting\n";
  cout << "Enter your choice: ";
  cin >> choice;
  switch(choice) {
    case 1: {
      int n;
      cout << "Enter number of elements: ";
      cin >> n;
      int *intArray = new int[n];
      inputArray(intArray, n);
      selectionSort(intArray, n);
      printArray(intArray, n);
      delete[] intArray;
      break;
    }
    case 2: {
      int n;
      cout << "Enter number of elements: ";
      cin >> n;
      float *floatArray = new float[n];
      inputArray(floatArray, n);
      selectionSort(floatArray, n);
      printArray(floatArray, n);
      delete[] floatArray;
      break;
    }
    case 3: {
      int n;
      cout << "Enter number of elements: ";
      cin >> n;
      string *stringArray = new string[n];
      inputArray(stringArray, n);
      selectionSort(stringArray, n);
      printArray(stringArray, n);
      delete[] stringArray;
      break;
    }
  }
}
