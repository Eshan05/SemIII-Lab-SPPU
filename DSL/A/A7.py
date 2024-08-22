"""
7. Write a Python Program for magic square. A magic square is an n*n matrix of the integers 1 to n^2 such that the sum of each row, column, and diagonal is the same. The figure given below is an example of magic square for case n=5. In this example, the common sum is 65.
"""

def construct_magic_square(n):
    """Constructs an n x n magic square for odd n using the Siamese method."""
    if n % 2 == 0:
        raise ValueError("This method only works for odd-sized magic squares.")
    
    # Initialize an n x n matrix with zeros
    M = [[0] * n for _ in range(n)]

    # Starting position
    i, j = 0, n // 2
    for num in range(1, n * n + 1):
        M[i][j] = num
        # Compute new position
        new_i, new_j = (i - 1) % n, (j + 1) % n
        
        if M[new_i][new_j]:  # If the new position is occupied
            new_i, new_j = (i + 1) % n, j  # Move down
        
        i, j = new_i, new_j

    return M

def scale_magic_square(M, desired_sum):
    """Scale the magic square so that the sum of each row, column, and diagonal equals the desired sum."""
    n = len(M)
    current_sum = n * (n * n + 1) // 2
    factor = desired_sum / current_sum
    
    # Scale each element in the matrix
    scaled_matrix = [[int(round(factor * M[i][j])) for j in range(n)] for i in range(n)]

    return scaled_matrix

def display_matrix(M):
    """Display the matrix and the magic sum."""
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

if __name__ == "__main__":
    main()
