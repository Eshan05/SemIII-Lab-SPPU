class Matrices:
    def __init__(self):
        self.matrix = []
        self.matrix2 = []

    def input_matrix(self, prompt):
        rows = int(input(f"Enter number of rows for {prompt}: "))
        cols = int(input(f"Enter number of columns for {prompt}: "))
        matrix = []
        print(f"Enter {rows * cols} elements row by row (Space separated):")
        for i in range(rows):
            row = [int(x) for x in input(f"Enter row {i+1}: ").split()]
            matrix.append(row)
        return matrix, rows, cols

    def display_matrix(self, matrix):
        for row in matrix:
            print(" ".join(map(str, row)))
        print()

    def transpose(self, matrix, rows, cols):
        transposed = [[matrix[j][i] for j in range(rows)] for i in range(cols)]
        self.display_matrix(transposed)

    def add(self):
        if not (self.rows == self.rows2 and self.cols == self.cols2):
            print("Matrices cannot be added.")
            return
        result = [[self.matrix[i][j] + self.matrix2[i][j] for j in range(self.cols)] for i in range(self.rows)]
        self.display_matrix(result)

    def subtract(self):
        if not (self.rows == self.rows2 and self.cols == self.cols2):
            print("Matrices cannot be subtracted.")
            return
        result = [[self.matrix[i][j] - self.matrix2[i][j] for j in range(self.cols)] for i in range(self.rows)]
        self.display_matrix(result)

    def multiply(self):
        if self.cols != self.rows2:
            print("Matrices cannot be multiplied.")
            return
        result = [[sum(self.matrix[i][k] * self.matrix2[k][j] for k in range(self.cols)) for j in range(self.cols2)] for i in range(self.rows)]
        self.display_matrix(result)

def main():
    ops = Matrices()
    while True:
        print("Menu:\n1. Addition\n2. Subtraction\n3. Transpose\n4. Multiplication\n5. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            ops.matrix, ops.rows, ops.cols = ops.input_matrix("first matrix")
            ops.matrix2, ops.rows2, ops.cols2 = ops.input_matrix("second matrix")
            ops.add()
        elif choice == '2':
            ops.matrix, ops.rows, ops.cols = ops.input_matrix("first matrix")
            ops.matrix2, ops.rows2, ops.cols2 = ops.input_matrix("second matrix")
            ops.subtract()
        elif choice == '3':
            ops.matrix, ops.rows, ops.cols = ops.input_matrix("the matrix")
            ops.transpose(ops.matrix, ops.rows, ops.cols)
        elif choice == '4':
            ops.matrix, ops.rows, ops.cols = ops.input_matrix("first matrix")
            ops.matrix2, ops.rows2, ops.cols2 = ops.input_matrix("second matrix")
            ops.multiply()
        elif choice == '5':
            print("Exiting...")
            break
        else:
            print("Invalid choice! Select a valid option.")

if __name__ == "__main__":
    main()

"""
Menu:
1. Addition
2. Subtraction
3. Transpose
4. Multiplication
5. Exit
Enter your choice: 1
Enter number of rows for first matrix: 2
Enter number of columns for first matrix: 2
Enter 4 elements row by row:
Enter row 1: 1 2
Enter row 2: 3 4
Enter number of rows for second matrix: 2
Enter number of columns for second matrix: 2
Enter 4 elements row by row:
Enter row 1: 5 6
Enter row 2: 7 8
4 8
10 12
"""