"""
* Eshan Nahar
18. Write Python program to store 10th class percentage of students in array. Write function for sorting array of floating point numbers in ascending order using radix sort and display top five scores
"""

def countingsort(num, k):
    n = len(num)
    res = [0] * n
    c = [0] * 10 # Count 
    for i in range(0, n):
        temp = num[i] // k # Index
        c[temp % 10] += 1 # Populate count array
    for i in range(1,10):
        c[i] += c[i-1] # Cumulative count array
    i = n-1 # Start from end
    while i>=0: # Assign numbers
        temp = num[i] // k
        res[c[temp % 10] - 1] = num[i]
        c[temp % 10] -= 1
        i = i-1
    for i in range(0, n):
        num[i] = res[i] # Copy to original array
    print(num)
    # Top Five Scores
    for i in range(len(num)):
        x = num[i]
        x /= 10
        num2[i] = x
    print(num2)
    
def radixsort(num):
    print(num)
    maximum = max(num)
    print(maximum)
    n = 1
    while maximum // n > 0:
        countingsort(num, n)
        n *= 10 # Increase exponent 
        
def countDigits(n): # Helper function (Unused)
	cnt = 0
	countAfterDecimal = str(n)[::-1].find('.')
	while n>0:
		cnt += 1
		n = n // 10
	return cnt + countAfterDecimal

num = []
num1 = []
num2 = []

M = int(input("Enter the number of students "))
for i in range(M):
    num2.append(0)
    per = float(input("Enter the percentage marks "))
    num.append(per)

num1 = [0] * len(num)
for i in range(0, len(num)):
    num1[i] = int(num[i]*10) # Convert to integer

print(num1)
print("Before sorting")
print(num)
print("After sorting")
radixsort(num1)
num3 = num2[::-1]
print("Top 5 scores are: ")
for i in range(0,5):
	print(num3[i])
