"""
* Eshan Nahar
In second year computer engineering class, group A student's play cricket, group B 
students play badminton and group C students play football. 
Write a Python program using functions to compute following: 
a) List of students who play both cricket and badminton 
b) List of students who play either cricket or badminton but not both 
c) Number of students who play neither cricket nor badminton 
d) Number of students who play cricket and football but not badminton. 
"""

def cricket_badminton(cricket, badminton):
    # Returns a list of students who play both cricket and badminton.
    result = []
    for student in cricket:
        if student in badminton:
            result.append(student)
    return result

def either_not_both(cricket, badminton):
    # Returns a list of students who play either cricket or badminton but not both.
    result = []
    for student in cricket:
        if student not in badminton:
            result.append(student)
    for student in badminton:
        if student not in cricket:
            result.append(student)
    return result

def neither(cricket, badminton, football):
    # Returns the number of students who play neither cricket nor badminton.
    all_students = set()
    for student in cricket:
        all_students.add(student)
    for student in badminton:
        all_students.add(student)
    for student in football:
        all_students.add(student)
    
    cricket_badminton_students = set(cricket_badminton(cricket, badminton))
    neither_cricket_nor_badminton = all_students - cricket_badminton_students - set(cricket) - set(badminton)
    return len(neither_cricket_nor_badminton)


def cricket_football_not_badminton(cricket, badminton, football):
    # Returns the number of students who play cricket and football but not badminton.
    result = 0
    for student in cricket:
        if student in football and student not in badminton:
            result += 1
    return result


# Sample data
cricket = ['A1', 'A2', 'A3', 'A4', 'A5']
badminton = ['B1', 'B2', 'B3', 'A3', 'C2']
football = ['B1', 'B2', 'A2', 'C1', 'C2']
print("Students who play both cricket and badminton:")
print(cricket_badminton(cricket, badminton))
print("\nStudents who play either cricket or badminton but not both:")
print(either_not_both(cricket, badminton))
print(f"\nNumber of students who play neither cricket nor badminton: {neither(cricket, badminton, football)}")
print(f"\nNumber of students who play cricket and football but not badminton: {cricket_football_not_badminton(cricket, badminton, football)}")

"""
Summary
1. We have to find intersection,
2. We have to find symmetric difference,
3. We have to find union(A,B)-C (or U) 
4. we have to find intersection(A,C)-B.

Thus, if we just define intersection(), union() and difference() we will also get the answer.
"""
