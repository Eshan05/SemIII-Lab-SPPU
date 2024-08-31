class Matrices:
	def __init__(self):
		self.rows = 0
		self.columns = 0
		self.rowsOther = 0
		self.columnsOther = 0
		self.matrix = []
		self.matrix2 = []
		self.matrix3 = []
		self.matrix4 = []
		self.matrix5 = []

	def inputM(self):
		self.rows = int(input("Enter number of rows: "))
		self.columns = int(input("Enter number of columns: "))
		print(f"You will enter {self.rows*self.columns} elements individually in Row by Row fashion")
		for i in range(self.rows):
			row = []
			for j in range(self.columns):
				m = int(input(f"Enter element ({i}, {j}): "))
				row.append(m)
			self.matrix.append(row)

	def displayM(self):
		print("==========")
		for i in range(self.rows):
			for j in range(self.columns):
				print(self.matrix[i][j], end=" ")
			print()

	def transpose(self):
		print("==========")
		print("Tranpose: ")
		for i in range(self.columns):
			for j in range(self.rows):
				print(self.matrix[j][i], end=" ")
			print()
		print("==========")

	def inputM2(self):
		self.rowsOther = int(input("Enter number of rows: "))
		self.columnsOther = int(input("Enter number of columns: "))
		print(f"You will enter {self.rowsOther*self.columnsOther} elements individually in Row by Row fashion")
		self.matrix2 = []
		for i in range(self.rowsOther):
			rowOther = []
			for j in range(self.columnsOther):
				m = int(input(f"Enter element ({i}, {j}): "))
				rowOther.append(m)
			self.matrix2.append(rowOther)
				
	def displayM2(self):
		print("==========")
		print("Second Matrix:")
		for i in range(self.rowsOther):
			for j in range(self.columnsOther):
				print(self.matrix2[i][j], end=" ")
			print()

	def addition(self):
		if self.rows != self.rowsOther or self.columns != self.columnsOther:
			print("Matrices cannot be added.")
		else:
			for i in range(self.rows):
				M3 = []
				for j in range(self.columns):
					c = self.matrix[i][j] + self.matrix2[i][j]
					M3.append(c)
				self.matrix3.append(M3)
			print("==========")
			print("Addition is: ")
			for i in range(self.rowsOther):
				for j in range(self.columnsOther):
					print(self.matrix3[i][j], end=" ")
				print()
			print("==========")

	def subtraction(self):
		if self.rows != self.rowsOther or self.columns != self.columnsOther:
			print("Matrices cannot be subtracted.")
		else:
			for i in range(self.rows):
				M3 = []
				for j in range(self.columns):
					c = self.matrix[i][j] - self.matrix2[i][j]
					M3.append(c)
				self.matrix3.append(M3)
			print("==========")
			print("Subtraction is: ")
			for i in range(self.rowsOther):
				for j in range(self.columnsOther):
					print(self.matrix3[i][j], end=" ")
				print()
			print("==========")

	def multiplication(self):
		if self.rowsOther != self.columns:
			print("Matrices cannot be multiplied.")
			return 
		else: 
			for i in range(self.rows):
				row = []
				for i in range(self.columnsOther):
					row.append(0)
				self.matrix5.append(row)
			# Or self.matrix5 = [[0] * self.columnsOther for _ in range(self.rows)]
			# self.matrix5 = [[0 for _ in range(self.columnsOther)] for _ in range(self.rows)]
			for i in range(self.rows): 
				for j in range(self.columnsOther):
					for k in range(self.rowsOther):
						# Or can iterate over self.columns
						self.matrix5[i][j] += self.matrix[i][k]*self.matrix2[k][j]
			print("==========")
			print("Multiplication is:")
			for i in range(self.rows):
				for j in range(self.columnsOther):
					print(self.matrix5[i][j], end=" ")
				print()
			"""
			for row in self.matrix5:
				for value in row:
					print(value, end=" ")
				print()
			"""
			print("==========")

def main():
	while True:
		ops = Matrices()
		print("Make your choice!\n 1. Addition\n 2. Subtraction\n 3. Tranpose\n 4. Multiplication\n 5. Exit")
		try: 
			choice = int(input("Enter your choice: "))
		except ValueError:
			print("Invalid input! Please enter a number")
			continue

		if choice == 1:
			print("Enter first matrix")
			ops.inputM()
			ops.displayM()
			print("Now enter second matrix")
			ops.inputM2()
			ops.displayM2()
			ops.addition()
		elif choice == 2:
			print("Enter first matrix")
			ops.inputM()
			ops.displayM()
			print("Now enter second matrix")
			ops.inputM2()
			ops.displayM2()
			ops.subtraction()
		elif choice == 3:
			ops.inputM()
			ops.displayM()
			ops.transpose()
		elif choice == 4:
			ops.inputM()
			ops.displayM()
			ops.inputM2()
			ops.displayM2()
			ops.multiplication()
		elif choice == 5:
			print("The program ended!")
			break
		else:
			print("Invalid choice! Select a valid option.")

if __name__ == '__main__':
	main()

