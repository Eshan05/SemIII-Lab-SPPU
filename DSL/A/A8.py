"""
* Eshan Nahar
8. WAPP that determines the location of a saddle point of matrix if one exists. An m*n matrix is said to have a saddle point if some entry `a[i][j]` is the smallest value in row i and the largest value in j.
"""

def findSaddlePoint(matrix):
	if not matrix or not matrix[0]:
		return None # If empty
	
	m = len(matrix) # Rows
	n = len(matrix[0]) # Columns
	for i in range(m):
		minRowValue = min(matrix[i])
		min_row_index = matrix[i].index(minRowValue)
		is_saddle = True
		for k in range(m):
			if matrix[k][min_row_index] > minRowValue:
				is_saddle = False
				break
		if is_saddle: 
			return(i, min_row_index)
	return None

matrix = [
	[9, 8, 17],
	[2, 8, 9],
	[6, 8, 4]
]

result = findSaddlePoint(matrix)
if result:
	print(f"Saddle point found at: {result}")
else:
	print("No saddle point found")