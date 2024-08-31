"""
* Eshan Nahar
10. WAPP for sparse M realization and operations on it- Transpose, Fast Transpose and addition of two matrices
"""
def display(M):
	for row in M:
		for element in row:
			print(element, end=" ")
		print()

def convert(M):
	SP = []
	# Search values non-zero
	for i in range(len(M)):
		for j in range(len(M[0])):
			if M[i][j] != 0:
				temp = []
				temp.append(i)
				temp.append(j)
				temp.append(M[i][j])
				SP.append(temp)
	SP.insert(0, [len(M), len(M[0]), len(SP)]) # R, C, V
	return SP

def addition(s1, s2):
	i, j, k = 1, 1, 1
	s3 = []
	# If dimensions match
	if((s1[0][0] == s2[0][0]) and (s1[0][1] == s2[0][1])):
		while((i <= s1[0][2]) and (j <= s2[0][2])):
			if(s1[i][0] == s2[j][0]):
				temp = []
				if(s1[i][1] == s2[j][1]):
					temp.append(s1[i][0])
					temp.append(s1[i][1])
					temp.append(s1[i][2] + s2[j][2])
					s3.append(temp)
					i, j, k = i+1, j+1, k+1
				elif(s1[i][1] < s2[j][1]):
					temp.append(s1[i][0])
					temp.append(s1[i][1])
					temp.append(s1[i][2])
					s3.append(temp)	
					i, k = i+1, k+1
				else:
					temp.append(s2[j][0])
					temp.append(s2[j][1])
					temp.append(s2[j][2])
					s3.append(temp)
					j, k = j+1, k+1
			elif(s1[i][0] < s2[j][0]):
				temp = []
				temp.append(s1[i][0])
				temp.append(s1[i][1])
				temp.append(s1[i][2])
				s3.append(temp)
				i, k = i+1, k+1
			else:
				temp = []
				temp.append(s1[j][0])
				temp.append(s1[j][1])
				temp.append(s1[j][2])
				s3.append(temp)
				j, k = j+1, k+1
		while(i <= s1[0][2]):
			temp = []
			temp.append(s1[i][0])
			temp.append(s1[i][1])
			temp.append(s1[i][2])
			s3.append(temp)
			i, k = i+1, k+1
		while(j <= s2[0][2]):
			temp = []
			temp.append(s2[j][0])
			temp.append(s2[j][1])
			temp.append(s2[j][2])
			s3.append(temp)
			j, k = j+1, k+1
	else:
		print("\n Addition not possible")
		return
	print("Addition of Matrices:")
	for row in s3:
		print(row)

def transpose(M):
	rows, cols, count = M[0]
	transposed = []
	for i in range(1, count+1):
		r, c, v = M[i]
		transposed.append([c, r, v])
	transposed.insert(0, [cols, rows, len(transposed)])
	return transposed

def fast_transpose(M):
	rows, cols, elements = M[0]
	row_terms, start = [0]*cols, [0]*cols
	for _, c, _ in M[1:]: # From index 1
		row_terms[c] += 1

	start[0] = 0
	for i in range(1, cols):
		start[i] = start[i-1] + row_terms[i-1]
	transposed = []
	transposed.append([cols, rows, elements])
	temp = [[] for _ in range(cols)]
	for r, c, v in M[1:]:
		pos = start[c]
		temp[c].append((r,v))
		start[c] += 1

	for c in range(cols):
		for r, v in temp[c]:
			transposed.append([c, r, v])
	return transposed

def main_menu():
	denseM1, denseM2, S1, S2 = None, None, None, None
	while True:
		print("\n Menu:")
		print("1. Input dense matrix 1")
		print("2. Input dense matrix 2")
		print("3. Transpose of matrix 1")
		print("4. Fast transpose of matrix 1.")
		print("5. Addition of both matrices (Sparse)")
		print("6. Exit")
		choice = input("Enter your choice: ").strip()
		if choice == '1':
			print("\nEnter elements for Matrix 1 row by row.")
			denseM1 = []
			while True:
				row = input().strip()
				if row == "":
					break
				denseM1.append(list(map(int, row.split())))
			S1 = convert(denseM1)
			print("\n Dense Matrix 1:")
			for row in denseM1:
				print(row)
			print("\n Sparse Matrix 1:")
			display(S1)
		elif choice == '2':
			print("\nEnter elements for Matrix 2 row by row.")
			denseM2 = []
			while True:
				row = input().strip()
				if row == "":
					break
				denseM2.append(list(map(int, row.split())))
			S2 = convert(denseM1)
			print("\n Dense Matrix 2:")
			for row in denseM2:
				print(row)
			print("\n Sparse Matrix 2:")
			display(S2)
		elif choice == '3':
			if S1:
				transposeM1 = transpose(S1)
				print("\n Transposed Sparse Matrix 1:")
				display(transposeM1)
			else:
				print("\n Dense matrix 1 is not added yet")
		elif choice == '4':
			if S1:
				fast_transposeM1 = fast_transpose(S1)
				print("\n Fast transposed Sparse Matrix 1:")
				display(fast_transposeM1)
			else:
				print("\n Dense matrix 1 is not added yet")
		elif choice == '5':
			if S1 and S2:
				result = addition(S1, S2)
				if result:
					print("\nAddition of Sparse Matrices:")
					display(result)
				else:
					print("\nDense matrices aren't added yet")
		elif choice == '6':
			print("\nExiting...")
			break
		else:
			print("\nInvalid choice.")

if __name__ == "__main__":
	main_menu()

"""
if __name__ == "__main__":
    M1 = [[1, 0], [0, 2]]
    M2 = [[3, 0, 5],[0, 7, 0]]
    sparse_M1 = convert(M1)
    sparse_M2 = convert(M2)
    print("Sparse Matrix 1:")
    display(sparse_M1)
    print("\nSparse Matrix 2:")
    display(sparse_M2)
    addition(sparse_M1, sparse_M2)

    transposed_sparse_M1 = transpose(sparse_M1)
    print("\nTransposed Sparse Matrix 1:")
    display(transposed_sparse_M1)
    transposed_sparse_M2 = transpose(sparse_M2)
    print("\nTransposed Sparse Matrix 2:")
    display(transposed_sparse_M2)

    transpose_M2 = fast_transpose(sparse_M2)
    print("\n Fast transpose of 2:")
    display(transpose_M2)
"""