"""
* Eshan Nahar
11. 
  a) WAPP to store roll numbers of student in array who attended training program in random order. Write function for searching whether particular student attended training program or not, using Linear search and Sentinel search. \
  b) WAPP to store roll numbers of student array who attended training program in sorted order. Write function for searching whether particular student attended training program or not, using Binary search and Fibonacci search
"""

class Searching:
  def __init__(self):
    self.__listLength = 0
    self.__searchList = []
    self.__originalList = [] # For binary and fibonacci

  def accept(self):
    self.__listLength = int(input("Enter the number of elements in list: "))
    for i in range(self.__listLength):
      t = int(input(f"Enter element a[{i}]: "))
      self.__searchList.append(t)
      self.__originalList.append(t)

  def linear(self, key):
    for i in range(self.__listLength):
      if self.__searchList[i] == key:
        return i
    return -1
  
  def sentinel(self, key):
    last = self.__searchList[self.__listLength - 1]
    self.__searchList[self.__listLength - 1] = key
    i = 0
    while self.__searchList[i] != key:
      i += 1
    self.__searchList[self.__listLength - 1] = last
    if (i < self.__listLength - 1) or (self.__searchList[self.__listLength-1] == key):
      return i
    return -1

  def insertionSort(self, arr):
    for i in range(1, len(arr)):
      key = arr[i]
      j = i - 1
      while j >= 0 and key < arr[j]:
        arr[j + 1] = arr[j]
        j -= 1
      arr[j + 1] = key

  def binary(self, key):
    sorted_list = self.__originalList.copy()
    self.insertionSort(sorted_list)
    low = 0
    high = sorted_list - 1
    mid = 0
    while low <= high:
      mid = (high + low) // 2
      if sorted_list[mid] < key:
        low = mid + 1
      elif sorted_list[mid] > key:
        high = mid - 1
      else:
        return mid
    return -1
  
  def fibonacci(self, key):
    n = self.__listLength
    sortedList = self.__originalList.copy()
    self.insertionSort(sortedList) 
    fibM2, fibM1 = 0, 1
    fibM = fibM2 + fibM1
    while(fibM < n):
      fibM2, fibM1  = fibM1, fibM
      fibM = fibM1 + fibM2
    offset = -1
    while(fibM > 1):
      i = min(offset + fibM2, n-1)
      if(sortedList[i] < key):
        # Key greater: Move third variable one down and reset offset to index
        fibM, fibM1 = fibM1, fibM - fibM1
        fibM2 = fibM - fibM1
        offset = i
      elif(sortedList[i] > key):
        # Key less than element: Move third variable two down
        fibM, fibM1 = fibM1, fibM1 - fibM2
        fibM2 = fibM - fibM1
      else: # First condition
        # return i
        return self.__originalList.index(key)
      
    if(fibM1 and offset < n-1 and sortedList[n-1] == key):
      # return offset + 1
      return self.__originalList.index(key)
    return -1
  
  def printList(self):
    print(self.__searchList)

obj = Searching()
obj.accept()
obj.printList()
while True:
  print("1. Linear Search\n2. Sentinel Search\n3. Binary Search\n4. Fibonacci Search\n5. Exit")
  choice = int(input("Enter your choice: "))
  if choice == 1:
    print("Selected Linear Search")
    key = int(input("Enter the element to be searched: "))
    if obj.linear(key) == -1:
      print("Element not found")
    else:
      print("Element found at index", obj.linear(key))
  if choice == 2:
    print("Selected Sentinel Search")
    key = int(input("Enter the element to be searched: "))
    if obj.sentinel(key) == -1:
      print("Element not found")
    else:
      print("Element found at index", obj.sentinel(key))
  if choice == 3:
    print("Selected Binary Search")
    print("Sorting the array...")
    obj.insertionSort()
    # obj.printList()
    key = int(input("Enter the element to be searched: "))
    if obj.binary(key) == -1:
      print("Element not found")
    else:
      print("Element found at index", obj.binary(key))
  if choice == 4:
    print("Selected Fibonacci Search")
    print("Sorting the array...")
    key = int(input("Enter the element to be searched: "))
    if obj.fibonacci(key) == -1:
      print("Element not found")
    else:
      print("Element found at index", obj.fibonacci(key))
  if choice == 5:
    break
