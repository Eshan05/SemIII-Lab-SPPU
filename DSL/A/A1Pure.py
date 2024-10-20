# Define functions to compute various student activities

def cricket_badminton(cricket, badminton):
  # Returns a list of students who play both cricket and badminton.
  result = []
  for i in range(len(cricket)):
    for j in range(len(badminton)):
      if cricket[i] == badminton[j]:
        result.append(cricket[i])
        break  # No need to check further in badminton
  return result

def either_not_both(cricket, badminton):
  # Returns a list of students who play either cricket or badminton but not both.
  result = []
  for i in range(len(cricket)):
    found = False
    for j in range(len(badminton)):
      if cricket[i] == badminton[j]:
        found = True
        break
    if not found:
      result.append(cricket[i])
  
  for i in range(len(badminton)):
    found = False
    for j in range(len(cricket)):
      if badminton[i] == cricket[j]:
        found = True
        break
    if not found:
      result.append(badminton[i])
  
  return result

def neither(cricket, badminton, football):
  # Returns the number of students who play neither cricket nor badminton.
  all_students = []
  
  # Collect all students from cricket
  for i in range(len(cricket)):
    if cricket[i] not in all_students:
      all_students.append(cricket[i])
  
  for i in range(len(badminton)):
    if badminton[i] not in all_students:
      all_students.append(badminton[i])
  
  for i in range(len(football)):
    if football[i] not in all_students:
      all_students.append(football[i])
  
  count_neither = 0
  for i in range(len(all_students)):
    if all_students[i] not in cricket and all_students[i] not in badminton:
      count_neither += 1

  return count_neither

def cricket_football_not_badminton(cricket, badminton, football):
  # Returns the number of students who play cricket and football but not badminton.
  count = 0
  for i in range(len(cricket)):
    if cricket[i] in football:
      found = False
      for j in range(len(badminton)):
        if cricket[i] == badminton[j]:
          found = True
          break
      if not found:
        count += 1
  return count

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
