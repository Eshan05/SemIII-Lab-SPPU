def accept():
    search_list = []
    original_list = []
    list_length = int(input("Enter the number of elements in list: "))
    for i in range(list_length):
        t = int(input(f"Enter element a[{i}]: "))
        search_list.append(t)
        original_list.append(t)
    return search_list, original_list, list_length

def linear(search_list, list_length, key):
    for i in range(list_length):
        if search_list[i] == key:
            return i
    return -1

def sentinel(search_list, list_length, key):
    last = search_list[list_length - 1]
    search_list[list_length - 1] = key
    i = 0
    while search_list[i] != key:
        i += 1
    search_list[list_length - 1] = last
    if (i < list_length - 1) or (search_list[list_length-1] == key):
        return i
    return -1

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def binary(original_list, key):
    sorted_list = original_list.copy()
    insertion_sort(sorted_list)
    low = 0
    high = len(sorted_list) - 1
    while low <= high:
        mid = (high + low) // 2
        if sorted_list[mid] < key:
            low = mid + 1
        elif sorted_list[mid] > key:
            high = mid - 1
        else:
            return mid
    return -1

def fibonacci(original_list, key, list_length):
    n = list_length
    sorted_list = original_list.copy()
    insertion_sort(sorted_list)
    fibM2, fibM1 = 0, 1
    fibM = fibM2 + fibM1
    while(fibM < n):
        fibM2, fibM1  = fibM1, fibM
        fibM = fibM1 + fibM2
    offset = -1
    while(fibM > 1):
        i = min(offset + fibM2, n-1)
        if(sorted_list[i] < key):
            fibM, fibM1 = fibM1, fibM - fibM1
            fibM2 = fibM - fibM1
            offset = i
        elif(sorted_list[i] > key):
            fibM, fibM1 = fibM1, fibM1 - fibM2
            fibM2 = fibM - fibM1
        else:
            return original_list.index(key)
    if(fibM1 and offset < n-1 and sorted_list[n-1] == key):
        return original_list.index(key)
    return -1

def print_list(search_list):
    print(search_list)

# Main program
search_list, original_list, list_length = accept()
print_list(search_list)

while True:
    print("1. Linear Search\n2. Sentinel Search\n3. Binary Search\n4. Fibonacci Search\n5. Exit")
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        print("Selected Linear Search")
        key = int(input("Enter the element to be searched: "))
        index = linear(search_list, list_length, key)
        if index == -1:
            print("Element not found")
        else:
            print("Element found at index", index)
    
    if choice == 2:
        print("Selected Sentinel Search")
        key = int(input("Enter the element to be searched: "))
        index = sentinel(search_list, list_length, key)
        if index == -1:
            print("Element not found")
        else:
            print("Element found at index", index)
    
    if choice == 3:
        print("Selected Binary Search")
        print("Sorting the array...")
        key = int(input("Enter the element to be searched: "))
        index = binary(original_list, key)
        if index == -1:
            print("Element not found")
        else:
            print("Element found at index", index)
    
    if choice == 4:
        print("Selected Fibonacci Search")
        print("Sorting the array...")
        key = int(input("Enter the element to be searched: "))
        index = fibonacci(original_list, key, list_length)
        if index == -1:
            print("Element not found")
        else:
            print("Element found at index", index)
    
    if choice == 5:
        break
