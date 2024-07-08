"""
5. WAPP to compute following operations on String: 

	a) To display word with the longest length 
	b) To determines the frequency of occurrence of particular character in the string 
	c) To check whether given string is palindrome or not 
	d) To display index of first appearance of the substring 
	e) To count the occurrences of each word in a given string
"""

def longest_word(string):
    """
    Displays the word with the longest length in the given string.
    
    Args:
        string (str): The input string.
    """
    words = string.split()
    longest_word = max(words, key=len)
    print(f"The word with the longest length is: {longest_word}")

def char_frequency(string, char):
    """
    Determines the frequency of occurrence of a particular character in the given string.
    
    Args:
        string (str): The input string.
        char (str): The character to find the frequency of.
    """
    count = string.count(char)
    print(f"The frequency of '{char}' in the string is: {count}")

def is_palindrome(string):
    """
    Checks whether the given string is a palindrome or not.
    
    Args:
        string (str): The input string.
    """
    if string == string[::-1]:
        print("The string is a palindrome.")
    else:
        print("The string is not a palindrome.")

def find_substring(string, substring):
    """
    Displays the index of the first appearance of the given substring in the string.
    
    Args:
        string (str): The input string.
        substring (str): The substring to search for.
    """
    index = string.find(substring)
    if index == -1:
        print(f"The substring '{substring}' is not found in the string.")
    else:
        print(f"The first appearance of the substring '{substring}' is at index {index}.")

def word_count(string):
    """
    Counts the occurrences of each word in the given string.
    
    Args:
        string (str): The input string.
    """
    word_counts = {}
    words = string.split()
    for word in words:
        if word in word_counts:
            word_counts[word] += 1
        else:
            word_counts[word] = 1
    
    print("Word counts:")
    for word, count in word_counts.items():
        print(f"{word}: {count}")

# Example usage
input_string = "The quick brown fox jumps over the lazy dog. The dog barks at the fox."

longest_word(input_string)
char_frequency(input_string, "o")
is_palindrome("racecar")
is_palindrome("hello")
find_substring(input_string, "fox")
find_substring(input_string, "cat")
word_count(input_string)
