# Function to display the word with the longest length
def longest_word(string):
	words = []
	current_word = ""
	
	# Split the string into words
	for char in string:
		if char != ' ':
			current_word += char
		else:
				if current_word:
					words.append(current_word)
					current_word = ""
	if current_word:  # Add the last word if any
		words.append(current_word)

	longest = ""
	for word in words:
		if len(word) > len(longest):
			longest = word
	return longest

# Function to determine the frequency of occurrence of a character
def character_frequency(string, char):
	count = 0
	for i in range(len(string)):
		if string[i] == char:
			count += 1
	return count

# Function to check whether the given string is a palindrome
def is_palindrome(string):
	left = 0
	right = len(string) - 1
	while left < right:
		if string[left] != string[right]:
			return False
		left += 1
		right -= 1
	return True

# Function to display the index of the first appearance of a substring
def first_appearance(string, substring):
	n = len(string)
	m = len(substring)
	
	for i in range(n - m + 1):
		match = True
		for j in range(m):
			if string[i + j] != substring[j]:
				match = False
				break
		if match:
			return i
	return -1  # Return -1 if not found

# Function to count occurrences of each word in a given string
def word_occurrences(string):
	words = []
	current_word = ""
	
	# Split the string into words
	for char in string:
		if char != ' ':
			current_word += char
		else:
			if current_word:
				words.append(current_word)
				current_word = ""
	if current_word:  # Add the last word if any
		words.append(current_word)

	occurrences = {}
	for word in words:
		if word in occurrences:
			occurrences[word] += 1
		else:
			occurrences[word] = 1
	return occurrences

# Main program
input_string = input("Enter a string: ")

# Display the longest word
print(f"The longest word is: '{longest_word(input_string)}'")

# Frequency of a particular character
char_to_check = input("Enter a character to check its frequency: ")
print(f"The character '{char_to_check}' appears {character_frequency(input_string, char_to_check)} times.")

# Check if the string is a palindrome
print(f"Is the string a palindrome? {'Yes' if is_palindrome(input_string) else 'No'}")

# First appearance of a substring
substring_to_find = input("Enter a substring to find its first appearance: ")
index = first_appearance(input_string, substring_to_find)
if index != -1:
	print(f"The first appearance of the substring '{substring_to_find}' is at index {index}.")
else:
	print(f"The substring '{substring_to_find}' is not found in the string.")

# Count occurrences of each word
occurrences = word_occurrences(input_string)
print("Occurrences of each word:")
for word, count in occurrences.items():
	print(f"'{word}': {count} time(s)")
