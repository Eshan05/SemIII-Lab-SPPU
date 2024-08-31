"""
* Eshan Nahar
9. WAPP to compute following computation on matrix:
    
  a) Addition of two matrices 
  b) Subtraction of two matrices 
  c) Multiplication of two matrices 
  d) Transpose of a matrix
"""

import numpy
x = numpy.array([[1, 2], [4, 5]])
y = numpy.array([[7, 8], [9, 10]])
print("Addition of matrices is: ")
print(numpy.add(x,y))

print("Subtraction of the two matrices: ")
print(numpy.subtract(x,y))
print("The product of the two matrices is: ")
print(numpy.dot(x,y))
print("The transpose of given matrix is: ")
print(x.T)