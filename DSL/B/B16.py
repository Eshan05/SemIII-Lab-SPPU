"""
* Eshan Nahar
16. WAPP to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.
"""

def inputperc():
	perc = []
	n = int(input("Enter the number of students: "))
	for i in range(n):
		perc.append(float(input(f"Enter the percentage of student {i+1}: ")))
	return perc

def printperc(perc):
	for i in range(len(perc)):
		print(perc[i], sep=' ')

def parititon(perc, start, end):
	if not perc or start < 0 or end >= len(perc):
		# raise IndexError("Invalid index for partitioning")
		print("Invalid index for partitioning")
		return -1
	pivot = perc[start]
	lower = start + 1
	upper = end
	while True:
		while lower <= upper and perc[upper] >= pivot:
			upper -= 1
		while lower <= upper and perc[lower] <= pivot:
			lower += 1
		if lower <= upper:
			perc[lower], perc[upper] = perc[upper], perc[lower]
		else:
			break
	perc[start], perc[upper] = perc[upper], perc[start]
	return upper

def quicksort(perc, start, end):
	if start < end:
		partition = parititon(perc, start, end)
		quicksort(perc, start, partition - 1)
		quicksort(perc, partition + 1, end)
	return perc

def topfive(perc):
	print("Top five percentages:")
	for i in range(5):
		print(perc[i], sep=' ')

def main():
	unsorted = []
	sorted = []
	flag = 1
	while flag == 1:
		print("=== Menu ===")
		print("1. Accept percentage of students")
		print("2. Display the percentages")
		print("3. Perform Quick Sort")
		print("4. Exit")
		ch = int(input("Enter your choice: "))
		if ch == 1:
			unsorted = inputperc()
		elif ch == 2:
			printperc(unsorted)
		elif ch == 3:
			sorted = quicksort(unsorted, 0, len(unsorted) - 1)
			print("Sorted percentages:")
			printperc(sorted)
			a = input("Do you want top five percentages? (Y/N): ")
			if a == 'Y':
				topfive(sorted)
		elif ch == 4:
			print("Exiting...")
			flag = 0
		else:
			print("Invalid choice")
			flag = 1

main()
