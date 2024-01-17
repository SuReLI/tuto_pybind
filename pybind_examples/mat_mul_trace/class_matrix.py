import time
import sys
sys.path.append("./build")
from c_matmultrace import Matrix as c_Matrix
import numpy as np


class p_Matrix:
    def __init__(self, data):
        self.data = data

    def multiply(self, other):
       # Initialize the result matrix with appropriate dimensions
        result = [[0] * len(other.data[0]) for _ in range(len(self.data))]

        # Perform matrix multiplication
        for i in range(len(self.data)):
            for j in range(len(other.data[0])):
                for k in range(len(other.data)):
                    result[i][j] += self.data[i][k] * other.data[k][j]
        return p_Matrix(result)
    
    def trace(self):
        result = 0
        for i in range(len(self.data)):
            result += self.data[i][i]
        return result
    
class n_Matrix:
    def __init__(self, data):
        self.data = np.array(data)
    def multiply(self, other):
        return np.dot(self.data,other.data)
    def trace(self):
        return np.trace(self)
        
def time_calculator(custom_class, config: dict)->None:
    matrix_data1 = [[10] * config["m"] for _ in range(config["l"])]
    matrix_data2 = [[10] * config["n"] for _ in range(config["m"])]
    matrix_1 = custom_class(matrix_data1)
    matrix_2 = custom_class(matrix_data2)
    begin_time = time.time()
    result = (matrix_1.multiply(matrix_2)).trace()
    end_time = time.time()
    print("Time Process  " + str(round(end_time - begin_time, 3)) + "s")
    print(f"Multiplication, trace result : {result} for l,m,n : {config['l']},{config['m']},{config['n']}\n")

if __name__=="__main__":
    config = {"l":850,"m":850,"n":850}

    print('Python powered by C++')
    time_calculator(c_Matrix,config)

    print('Python powered by Numpy')
    time_calculator(n_Matrix,config)

    print('Python')
    time_calculator(p_Matrix,config)

