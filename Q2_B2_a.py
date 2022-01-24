import numpy as np
import time
 
n=int(input("Enter size of matrix: "))

mat1=np.random.randint(low=1,high=32767,size=(n,n))/7
mat2=np.random.randint(low=1,high=32767,size=(n,n))/7

start=time.time_ns()
mat3 = np.dot(mat1,mat2)
end=time.time_ns()

# print(mat3)

print("Time taken for matrix multiplication", (end-start)*1e-9)
