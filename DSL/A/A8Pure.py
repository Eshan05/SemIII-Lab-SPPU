"""
* Eshan Nahar
8. WAPP that determines the location of a saddle point of matrix if one exists. An m*n matrix is said to have a saddle point if some entry `a[i][j]` is the smallest value in row i and the largest value in j.
"""

def findSaddlePoint(M):
	n = len(M)
	for i in range(n):
		min_row = M[i][0]
		colidx = 0
		for j in range(1, n):
			if min_row > M[i][j] :
				min_row = M[i][j]
				colidx = j
		
		k = 0
		# Check if minimum in row I is maximum in its column
		for k in range(n):
			if(min_row < M[k][colidx]):
				break
			k += 1
		if(k == n):
			print("Value of Saddle Point ", min_row)
			return True
	return False

M = [
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, 9] # Output: 7
]

if(findSaddlePoint(M) == False):
	print("No Saddle Point")
