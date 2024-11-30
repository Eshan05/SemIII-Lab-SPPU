"""
* Eshan Nahar
13. WAPP to maintain club members, sort on roll numbers in ascending order. Write function “Ternary_Search” to search whether particular student is member of club or not. Ternary search is modified binary search that divides array into 3 halves instead of two.
"""

def accept():
	rollno = []
	n = int(input("Enter the number of students: "))
	for i in range(n):
		rollno.append(int(input(f"Enter roll number of student {i+1}: ")))
	return rollno

def printroll(rollno):
	if not rollno:
		print("No roll numbers available.")
	else:
		for i in rollno:
			print(i, end=" ")
		print()

def insertionSort(rollno):
	for i in range(1, len(rollno)):
		key = rollno[i]
		j = i - 1
		while j >= 0 and rollno[j] > key:
			rollno[j + 1] = rollno[j]
			j -= 1
		rollno[j + 1] = key
	return rollno

def NRT(roll, rollFind):
	left = 0
	right = len(roll) - 1
	while left <= right:
		mid1 = left + (right - left) // 3
		mid2 = left + 2 * (right - left) // 3
		if rollFind == roll[mid1]:
			return mid1
		if rollFind == roll[mid2]:
			return mid2
		
		if rollFind < roll[mid1]:
			right = mid1 - 1
		elif rollFind > roll[mid2]:
			left = mid2 + 1
		else:
			left = mid1 + 1
			right = mid2 - 1
	
	return -1

def ternarySearch(roll, left, right, rollFind):
	if right >= left:
		mid1 = left + (right - left) // 3
		mid2 = right - (right - left) // 3
		if roll[mid1] == rollFind:
			return mid1
		if roll[mid2] == rollFind:
			return mid2

		if rollFind < roll[mid1]:
			return ternarySearch(roll, left, mid1 - 1, rollFind)
		elif rollFind > roll[mid2]:
			return ternarySearch(roll, mid2 + 1, right, rollFind)
		else:
			return ternarySearch(roll, mid1 + 1, mid2 - 1, rollFind)
	
	return -1

def main():
	unsortednos = []
	sortednos = []
	flag = 1
	while flag == 1:
		print("=== Menu ===")
		print("1. Add student roll number")
		print("2. Display all roll numbers")
		print("3. Sort roll numbers")
		print("4. Perform Non-Recursive Ternary Search")
		print("5. Perform Recursive Ternary Search")
		print("6. Exit\n")
		ch = int(input("Enter your choice: "))
		
		if ch == 1:
			unsortednos = accept()
			sortednos = []  # Clear sortednos since we have new data
		elif ch == 2:
			printroll(unsortednos)
		elif ch == 3:
			if unsortednos:
				print("After sorting: ")
				sortednos = insertionSort(unsortednos)
				printroll(sortednos)
			else:
				print("No roll numbers to sort.")
		elif ch == 4:
			if sortednos:
				findRoll = int(input("Enter roll number to search: "))
				index = NRT(sortednos, findRoll)
				if index != -1:
					print(f"The roll number {findRoll} is present at index {index}")
				else:
					print(f"Roll number {findRoll} not found!")
			else:
					print("No sorted roll numbers to search.")
		elif ch == 5:
			if sortednos:
				findRoll = int(input("Enter roll number to search: "))
				left = 0
				right = len(sortednos) - 1
				index = ternarySearch(sortednos, left, right, findRoll)
				if index != -1:
					print(f"The roll number {findRoll} is present at index {index}")
				else:
					print(f"Roll number {findRoll} not found!")
			else:
				print("No sorted roll numbers to search.")
		elif ch == 6:
			print("Exiting...")
			flag = 0
		else:
			print("Invalid choice")

main()
