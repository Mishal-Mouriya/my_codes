


import json

matrixstr1 = input("Matrix1--> ")
matrixstr2 = input("Matrix2--> ")

matrix1 = json.loads(matrixstr1)              #concept2 use of json herer converting str to pythonic object
matrix2 = json.loads(matrixstr2)

m = len(matrix1)
n = len(matrix1[0])

m2 = len(matrix2)
n2 = len(matrix2[0])

if m == m2 and n == n2:

    result = []

    for i in range(m):                        #concept1 ->creation of row every time and appending it very important
        row = []

        for j in range(n):
            row.append(matrix1[i][j] + matrix2[i][j])

        result.append(row)

    resultstr = json.dumps(result)
    print(resultstr)                              #ohohi giving backstring kola maaasu


else:
    print("Matrices cannot be added")