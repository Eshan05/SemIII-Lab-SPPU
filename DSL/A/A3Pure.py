# Function to delete duplicate entries
def delete_duplicates(books):
	unique_books = []
	for i in range(len(books)):
		found = False
		for j in range(len(unique_books)):
			if books[i][0] == unique_books[j][0] and books[i][1] == unique_books[j][1]:
				found = True
				break
		if not found:
			unique_books.append(books[i])
	return unique_books

# Function to sort books in ascending order based on cost
def sort_by_cost(books):
	for i in range(len(books)):
		for j in range(len(books) - 1 - i):
			if books[j][1] > books[j + 1][1]:
				books[j], books[j + 1] = books[j + 1], books[j]
	return books

# Function to count the number of books with cost more than 500
def count_expensive_books(books):
	count = 0
	for i in range(len(books)):
		if books[i][1] > 500:
			count += 1
	return count

# Function to copy books with cost less than 500 to a new list
def copy_cheap_books(books):
	cheap_books = []
	for i in range(len(books)):
		if books[i][1] < 500:
			cheap_books.append(books[i])
	return cheap_books

# Main program
num_books = int(input("Enter the number of books: "))
books = []
for _ in range(num_books):
	book_name = input(f"Enter the name of book {_+1}: ")
	book_cost = float(input(f"Enter the cost of book {_+1}: "))
	books.append((book_name, book_cost))

print("\nBooks after removing duplicates:")
unique_books = delete_duplicates(books)
for book in unique_books:
	print(f"Name: {book[0]}, Cost: {book[1]}")

print("\nBooks sorted by cost:")
sorted_books = sort_by_cost(unique_books)
for book in sorted_books:
	print(f"Name: {book[0]}, Cost: {book[1]}")

print(f"\nNumber of books with cost more than 500: {count_expensive_books(unique_books)}")
print("\nBooks with cost less than 500:")
cheap_books = copy_cheap_books(unique_books)
for book in cheap_books:
	print(f"Name: {book[0]}, Cost: {book[1]}")
