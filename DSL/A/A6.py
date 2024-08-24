"""
* Eshan Nahar
6. It is decided that weekly greetings are to be furnished to wish the students having their birthdays in that week. The consolidated sorted list with desired categorical information is to be provided to the authority. WAPP to store students PRNs with date and month of birth. Let `List_A` and `List_B` be the two list for two SE Computer divisions. Lists are sorted on date and month. Merge these two lists into third list “`List_SE_Comp_DOB`” resulting in sorted information about Date of Birth of SE Computer students
"""

def merge_sorted_lists(list_a, list_b):
    # Merge two sorted lists into a single sorted list
    merged_list = []
    i, j = 0, 0
    
    while i < len(list_a) and j < len(list_b):
        if (list_a[i][2], list_a[i][1]) < (list_b[j][2], list_b[j][1]):
            merged_list.append(list_a[i])
            i += 1
        else:
            merged_list.append(list_b[j])
            j += 1
    while i < len(list_a):
        merged_list.append(list_a[i])
        i += 1
    while j < len(list_b):
        merged_list.append(list_b[j])
        j += 1

    return merged_list

def input_list(prompt):
    # Input a sorted list of students' birthdays
    student_list = []
    print(prompt)
    while True:
        try:
            prn = input("Enter PRN (or press Enter to finish): ").strip()
            if not prn:
                break
            day = int(input("Enter day of birth (1-31): ").strip())
            month = int(input("Enter month of birth (1-12): ").strip())
            if day < 1 or day > 31 or month < 1 or month > 12:
                print("Invalid date or month. Please try again.")
                continue
            student_list.append((prn, day, month))
        except ValueError:
            print("Invalid input. Please enter numbers for day and month.")
    student_list.sort(key=lambda x: (x[2], x[1]))  # Sort by month, then by day
    return student_list

def display_list(student_list):
    # Display the sorted list of students' birthdays
    print("\nSorted List of SE Computer Students' DOB:")
    for prn, day, month in student_list:
        print(f"PRN: {prn}, Date of Birth: {day}/{month}")

def main():
    list_a = []
    list_b = []
    
    while True:
        print("\nMenu:")
        print("1 : Input data for List A")
        print("2 : Input data for List B")
        print("3 : Merge and display the sorted list")
        print("4 : Exit")
        
        choice = input("Enter your choice: ").strip()
        
        if choice == '1':
            list_a = input_list("Input data for List A")
        elif choice == '2':
            list_b = input_list("Input data for List B")
        elif choice == '3':
            merged_list = merge_sorted_lists(list_a, list_b)
            display_list(merged_list)
        elif choice == '4':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
