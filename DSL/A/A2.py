"""
2. Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students in the class. Write functions to compute following:

	a) The average score of class 
	b) Highest score and lowest score of class 
	c) Count of students who were absent for the test 
	d) Display mark with highest frequency
"""

def average_score(marks):
    """
    Computes the average score of the class.
    """
    total_score = sum(score for score in marks if score >= 0)
    total_students = sum(1 for score in marks if score >= 0)
    return total_score / total_students

def highest_lowest_score(marks):
    """
    Returns the highest and lowest scores of the class.
    """
    valid_scores = [score for score in marks if score >= 0]
    return max(valid_scores), min(valid_scores)

def absent_count(marks):
    """
    Returns the count of students who were absent for the test.
    """
    return sum(1 for score in marks if score < 0)

def most_frequent_mark(marks):
    """
    Displays the mark with the highest frequency.
    """
    mark_counts = {}
    for score in marks:
        if score >= 0:
            mark_counts[score] = mark_counts.get(score, 0) + 1
    
    if not mark_counts:
        return "No valid scores recorded."
    
    max_count = max(mark_counts.values())
    for mark, count in mark_counts.items():
        if count == max_count:
            return f"The mark with the highest frequency is: {mark}"

# Example usage
num_students = int(input("Enter the number of students: "))
marks = []
for _ in range(num_students):
    score = int(input(f"Enter the score for student {_+1}: "))
    marks.append(score)

print(f"The average score of the class is: {average_score(marks):.2f}")
highest, lowest = highest_lowest_score(marks)
print(f"The highest score is: {highest}")
print(f"The lowest score is: {lowest}")
print(f"The number of students who were absent for the test is: {absent_count(marks)}")
print(most_frequent_mark(marks))
