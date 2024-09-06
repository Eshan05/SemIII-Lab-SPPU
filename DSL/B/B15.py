"""
* Eshan Nahar
15. WAPP to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using

	a) Insertion sort
	b) Shell Sort and display top five scores
"""

def accept_percentages():
	percentages = []
	n = int(input("Enter the number of students: "))
	for i in range(n):
		percentage = float(input(f"Enter percentage of student {i+1}: "))
		percentages.append(percentage)
	return percentages

def insertion_sort(arr):
	for i in range(1, len(arr)):
		key = arr[i]
		j = i - 1
		while j >= 0 and arr[j] > key:
			arr[j + 1] = arr[j]
			j -= 1
		arr[j + 1] = key
	return arr

def shell_sort(arr):
	n = len(arr)
	gap = n // 2
	while gap > 0:
		for i in range(gap, n):
			temp = arr[i]
			j = i
			while j >= gap and arr[j - gap] > temp:
				arr[j] = arr[j - gap]
				j -= gap
			arr[j] = temp
		gap //= 2
	return arr

def display_top_five(arr):
	if len(arr) == 0:
		print("No percentages to display.")
	else:
		# Sort in descending order to easily get the top 5
		sorted_arr = arr.copy()
		insertion_sort(sorted_arr)
		top_five = sorted_arr[-5:][::-1]
		print("Top five scores:")
		for score in top_five:
				print(score)

def main():
	percentages = accept_percentages()
	print("\nOriginal percentages:")
	print(percentages)
	
	while True:
		print("\n=== Menu ===")
		print("1. Sort using Insertion Sort")
		print("2. Sort using Shell Sort")
		print("3. Display Top Five Scores")
		print("4. Exit\n")
		choice = int(input("Enter your choice: "))
		
		if choice == 1:
			sorted_percentages = insertion_sort(percentages.copy())
			print("Sorted percentages using Insertion Sort:")
			print(sorted_percentages)
		elif choice == 2:
			sorted_percentages = shell_sort(percentages.copy())
			print("Sorted percentages using Shell Sort:")
			print(sorted_percentages)
		elif choice == 3:
			print("Percentages:")
			display_top_five(percentages)
		elif choice == 4:
			print("Exiting...")
			break
		else:
			print("Invalid choice, please try again.")

if __name__ == "__main__":
		main()
