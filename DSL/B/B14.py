"""
* Eshan Nahar
14. WAPP to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
		
	a) Selection Sort 
	b) Bubble sort and display top five scores

"""

def selectionsort(arr):
	n = len(arr)
	for i in range(n-1):
		min_idx = i
		for j in range(i+1, n):
			if arr[j] > arr[min_idx]:
				min_idx = j
		arr[i], arr[min_idx] = arr[min_idx], arr[i]

def bubblesort(arr):
	n = len(arr)
	for i in range(n-1):
		for j in range(n-1-i):
			if arr[j] < arr[j+1]:
				arr[j], arr[j+1] = arr[j+1], arr[j]

def main():
	student_count = int(input("Enter the number of students: "))
	percentages = []
	for i in range(student_count):
		percentage = float(input(f"Enter the percentage for student {i + 1}: "))
		percentages.append(percentage)
	ch = int(input("=== Choose a sorting method ===\n1. Selection Sort\n2. Bubble Sort\n"))
	if ch == 1:
		selectionsort(percentages)
	elif ch == 2:
		bubblesort(percentages)
	else:
		print("Invalid choice")
	print("Top 5 scores are:")
	for i, percentage in enumerate(percentages[:5], 1):
		print(f"{i}: {percentage:.2f}%")

if __name__ == "__main__":
	main()
