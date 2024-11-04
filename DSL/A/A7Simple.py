def construct_magic_square(n):
  if n % 2 == 0:
    return None
  
  # N by N Matrix with zeros
  M = []
  for i in range(n):
    row = []  # Create a new row
    for j in range(n):
      row.append(0)  # Append zero to the row
    M.append(row)  # Append the row to the matrix

  # Starting position
  i = 0
  j = n // 2

  for num in range(1, n * n + 1):
    M[i][j] = num
    new_i = (i - 1) % n
    new_j = (j + 1) % n
    
    if M[new_i][new_j]:  # If the new position is occupied
      new_i = (i + 1) % n  # Move down
      new_j = j  # Stay in the same column
    
    i, j = new_i, new_j  # Update to new position

  return M

def display_matrix(M):
  n = len(M)
  magic_sum = 0
  # Calculate the magic sum from the first row
  for j in range(n):
    magic_sum += M[0][j]
  
  print(f"Magic Square Matrix ({n} x {n}):")
  for i in range(n):
    for j in range(n):
      print(f"{M[i][j]:2d}", end=" ")
    print()  # New line after each row
  print(f"Sum in each row, column & diagonal = {magic_sum}")

while True:
  print("\n1: Find Magic Square")
  print("2: Exit")
  choice = input("Enter your choice: ").strip()
  
  if choice == '2':
    print("End of Program")
    break
  elif choice == '1':
    n = input("\nEnter the order of the square matrix (Odd number): ").strip()
    if not n.isdigit() or int(n) <= 0 or int(n) % 2 == 0:
      print("The size must be a positive odd number.")
      continue
    
    n = int(n)  # Convert to integer after validation
    M = construct_magic_square(n)
    if M is not None:
      display_matrix(M)
    else:
      print("The size must be an odd number.")
  else:
    print("Invalid choice. Try again.")
