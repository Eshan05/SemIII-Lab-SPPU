friends = []

def insert(name, number):
    global friends
    # Insert the new contact and then sort the list
    friends.append((name, number))
    insertionSort()

def insertionSort():
    global friends
    for i in range(1, len(friends)):
        key = friends[i]
        j = i - 1
        while j >= 0 and key[0] < friends[j][0]:
            friends[j + 1] = friends[j]
            j -= 1
        friends[j + 1] = key

def binarySearch(name, low, high):
    if low <= high:
        mid = (low + high) // 2
        mid_name = friends[mid][0]
        if mid_name == name:
            return mid
        elif name < mid_name:
            return binarySearch(name, low, mid - 1)
        else:
            return binarySearch(name, mid + 1, high)
    return -1

def binarySearchIt(name):
    low, high = 0, len(friends) - 1
    while low <= high:
        mid = (low + high) // 2
        mid_name = friends[mid][0]
        if mid_name == name:
            return mid
        elif name < mid_name:
            high = mid - 1
        else:
            low = mid + 1
    return -1

def fibonacciSearch(name):
    n = len(friends)
    fibm2, fibm1 = 0, 1
    fibm = fibm2 + fibm1
    while fibm < n:
        fibm2, fibm1 = fibm1, fibm
        fibm = fibm1 + fibm2

    offset = -1
    while fibm > 1:
        i = min(offset + fibm2, n - 1)
        if friends[i][0] < name:
            fibm, fibm1 = fibm1, fibm - fibm1
            fibm2 = fibm - fibm1
            offset = i
        elif friends[i][0] > name:
            fibm, fibm1 = fibm1, fibm1 - fibm2
            fibm2 = fibm - fibm1
        else:
            return i
    if fibm1 and offset < n - 1 and friends[n - 1][0] == name:
        return n - 1
    return -1

def display():
    global friends
    if not friends:
        print("Phonebook is empty")
    else:
        for name, number in friends:
            print(f"Name: {name}, Mobile Number: {number}")

def search(name, searchType):
    if searchType == 1:
        return binarySearch(name, 0, len(friends) - 1)
    elif searchType == 2:
        return binarySearchIt(name)
    elif searchType == 3:
        return fibonacciSearch(name)
    else:
        print("Invalid search selected")
        return None

while True:
    print("\n === Phonebook ===")
    print("1. Add friend")
    print("2. Search friend")
    print("3. Display phonebook")
    print("4. Exit")
    choice = input("Enter your choice: ").strip()
    if not choice.isdigit():
        print("Invalid input. Please enter a number.")
        continue
    choice = int(choice)
    if choice == 1:
        name = input("Enter name: ").strip()
        number = input("Enter mobile number: ").strip()
        if not name or not number:
            print("Name and mobile number cannot be empty.")
            continue
        insert(name, number)
        print(f"Friend {name} was added")
    
    elif choice == 2:
        print("\n Search menu:")
        print("1. Binary Search (Recursive)")
        print("2. Binary Search (Non-Recursive)")
        print("3. Fibonacci Search")
        search_type = input("Enter the search type (1-3): ").strip()
        if not search_type.isdigit():
            print("Invalid input. Please enter a number between 1 and 3.")
            continue
        search_type = int(search_type)
        name = input("Enter friend's name to search: ").strip()
        if not name:
            print("Name cannot be empty.")
            continue
        friend_index = search(name, search_type)
        if friend_index != -1:
            print(f"Found {name}: Mobile Number: {friends[friend_index][1]}")
        else:
            print(f"{name} not found in phonebook.")
            add_friend = input("Would you like to add this friend to the phonebook? (Y/N): ").strip().lower()
            if add_friend == 'y':
                number = input("Enter mobile number: ").strip()
                if not number:
                    print("Mobile number cannot be empty.")
                    continue
                insert(name, number)
                print(f"Friend {name} was added to the phonebook.")
            else:
                print("Friend not added.")
    elif choice == 3:
        display()
    elif choice == 4:
        print("Exiting...")
        break
    else:
        print("Invalid choice")