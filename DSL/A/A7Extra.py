"""

7. Write a Python Program for magic square. A magic square is an n*n matrix of the integers 1 to n^2 such that the sum of each row, column, and diagonal is the same. The figure given below is an example of magic square for case n=5. In this example, the common sum is 65.
"""

def construct_magic_square(n):
	if n % 2 == 0:
		raise ValueError("This method only works for odd-sized magic squares.")
	M = [[0] * n for _ in range(n)]
	i, j = 0, n // 2 # Starting
	for num in range(1, n * n + 1):
		M[i][j] = num
		# Compute new position
		new_i, new_j = (i - 1) % n, (j + 1) % n
		if M[new_i][new_j]:  # If the new position is occupied
			new_i, new_j = (i + 1) % n, j  # Move down
		i, j = new_i, new_j
	return M

"""
As per PDF, we if take position via decrementing row number of previous by 1
and incrementing the column number of previous by 1. If -1 it wrap to n-1 and column becomes n then it wraps to 0. If occupied column decrements by 2 and row increments by 1. If i=-1 and 
def generateMagicSquare(size):
	magicSquare=[[0 for x in range(size)] for y in range(size)]
	i = size // 2 # Middle 
	j = size - 1
	num = 1
	while num <= (size*size):
		if i == -1 and j == size: # Outside
			j = size - 2
			i = 0
		else: 
			if j == size: # Wrap for column
				j = 0
			if i < 0:
				i = size - 1
		if magicSquare[i][j] != 0: # Occupied
			j -= 2
			i += 1
			continue
		
		magicSquare[i][j] = num
		num += 1
		# Next position
		j += 1
		i -= 1
		sum = size * (size*size+1)//2
		print("Magic Sum is: ",sum)
		print(f"{size} x {size} Magic Square is: \n")
		for i in range(0, size):
			for j in range(0, size):
				print(' %2d ' % (magicSquare[i][j]), end=' | ')
				# Right aligned with width 2
				if j == size - 1:
					print()
"""

def scale_magic_square(M, desired_sum):
	n = len(M)
	current_sum = n * (n * n + 1) // 2
	factor = desired_sum / current_sum
	# Scale each element in the matrix
	scaled_matrix = [[int(round(factor * M[i][j])) for j in range(n)] for i in range(n)]
	return scaled_matrix

def display_matrix(M):
	# Display the matrix and the magic sum.
	n = len(M)
	magic_sum = sum(M[0])
	print(f"Magic Square Matrix ({n} x {n}):")
	for row in M:
		print(" ".join(f"{num:2d}" for num in row))
	print(f"Sum in each row, column & diagonal = {magic_sum}")

def main():
	while True:
		print("\n1: Find Magic Square")
		print("2: Exit")
		choice = input("Enter your choice: ").strip()
		if choice == '2':
			print("End of Program")
			break
		elif choice == '1':
			try:
				n = int(input("\nEnter the order of the square matrix (odd number): ").strip())
				if n % 2 == 0 or n <= 0:
					print("The size must be a positive odd number.")
					continue
				desired_sum = int(input("\nEnter the desired sum for each row, column, and diagonal: ").strip())
				M = construct_magic_square(n)
				M_scaled = scale_magic_square(M, desired_sum)
				display_matrix(M_scaled)
			except ValueError as e:
								print(f"Error: {e}")
		else:
			print("Invalid choice. Try again.")

main()
