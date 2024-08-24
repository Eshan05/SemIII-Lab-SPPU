"""
* Eshan Nahar
3. WAPP for department library which has N books, write functions for following: 
   
	a) Delete duplicate entries 
	b) Display books in ascending order based on cost of books 
	c) Count number of books with cost more than 500 
	d) Copy books in a new list which has cost less than 500
"""

def delete_duplicates(books):
    # Deletes duplicate entries from the list of books.
    unique_books = []
    for book in books:
        if book not in unique_books:
            unique_books.append(book)
    return unique_books

def sort_by_cost(books):
    # Displays the books in ascending order based on cost.
    return sorted(books, key=lambda x: x[1]) 

def count_expensive_books(books):
    # Counts the number of books with cost more than 500.
    return sum(1 for book in books if book[1] > 500)

def copy_cheap_books(books):
    # Creates a new list of books with cost less than 500.
    return [book for book in books if book[1] < 500]

# Example usage
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
