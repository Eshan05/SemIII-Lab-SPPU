"""
* Eshan Nahar
17. Write a Python program to store 12th class percentage of students in array. Write function for sorting array of floating point numbers in ascending order using bucket sort and display top five scores.
"""

def accept_percentages():
	perc = []
	n = int(input("Enter the number of students: "))
	for i in range(n):
		perc.append(float(input(f"Enter the percentage of student {i+1}: ")))
	return perc

def print_percentages(perc):
	for p in perc:
		print(p, end=' ')
	print()

def insertionsort(arr):
	for i in range(1, len(arr)):
		key = arr[i]
		j = i - 1
		while j >= 0 and arr[j] > key:
			arr[j + 1] = arr[j]
			j -= 1
		arr[j + 1] = key

def bucket_sort(arr):
	if len(arr) == 0:
		return arr
	
	# Create buckets
	min_value = min(arr)
	max_value = max(arr) 
	bucket_count = 10 # Number of buckets
	bucket_range = (max_value - min_value) / bucket_count
	# buckets = [[] for _ in range(bucket_count)]

	buckets = []
	for i in range(bucket_count):
		buckets.append([])
	
	for num in arr:
		index = int((num - min_value) / bucket_range)
		# If the index is out of bounds, subtract one to wrap around
		if index == bucket_count:
			index -= 1
		buckets[index].append(num)

	# Concatenate results
	sorted_array = []
	for bucket in buckets:
		insertionsort(bucket)
		sorted_array.extend(bucket)	
	return sorted_array

def top_five(perc):
	print("Top five percentages:")
	for i in range(min(5, len(perc))):
		print(perc[i], end=' ')
	print()

def main():
	percentages = accept_percentages()
	print("Original percentages:")
	print_percentages(percentages)
	sorted_percentages = bucket_sort(percentages)
	print("Sorted percentages:")
	print_percentages(sorted_percentages)	
	print("Do you want to display the top five percentages? (Y/N):")
	choice = input().strip().upper()
	if choice == 'Y':
		top_five(sorted_percentages)

if __name__ == "__main__":
    main()
