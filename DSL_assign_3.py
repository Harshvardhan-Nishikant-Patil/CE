row_num = int(input("row: "))
col_num = int(input("col: "))

arr1 = [[0 for col in range (col_num)]for row in range(row_num)]
for row in range(row_num):
    for col in range (col_num):
        item = int(input("element: "))
        arr1[row][col] = item
print(arr1)

arr2 = [[0 for col in range (col_num)]for row in range(row_num)]
for row in range(row_num):
    for col in range (col_num):
        item = int(input("element: "))
        arr2[row][col] = item
print(arr2)


def addition(arr1,arr2):
    result = [[arr1[i][j] + arr2[i][j] for j in range (len(arr1[0]))] for i in range(len(arr1))]
    print(result)
addition(arr1,arr2)

def substaction(arr1,arr2):
    result = [[arr1[i][j] - arr2[i][j] for j in range (len(arr1[0]))] for i in range(len(arr1))]
    print(result)


def multiplication(arr1,arr2):
    result = [[0,0,0],[0,0,0],[0,0,0]]
    for i in range (len(arr1)):
        for j in range (len(arr2[0])):
            for k in range (len(arr2)):
                result[i][j] = arr1[i][k] * arr2[k][j]
    for r in result:
        print (r)



def transpose(arr1):
    result = [[0,0,0],[0,0,0],[0,0,0]]
    for i in range (len(arr1)):
        for j in range (len(arr1[0])):
            result[j][i] = arr1[i][j]
    for r in result:
        print(r)




print("""
1.Addition of matrix
2.substarction of matrix
3.multiplicationof matrix
4.transpose of matrix
0.stop getting output
""")

while(True):
    choice = int(input("enter your choice: "))

    if (choice==1):
        addition(arr1,arr2)
    
    elif (choice == 2):
        substaction(arr1,arr2)

    elif (choice == 3):
        multiplication(arr1,arr2)

    elif (choice == 4):
        transpose(arr1)

    elif(choice == 0):
        break

    else:
        print("enter valid choice")