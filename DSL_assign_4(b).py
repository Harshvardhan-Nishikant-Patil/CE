numbers = []
n = int(input("enter number of elements: "))

for i in range(0, n):
    number = int(input("enter number: "))
    numbers.append(number)

print(numbers)

x = int(input("enter numbers to be search: "))


def binary_search(numbers, x):
    low = 0
    high = len(numbers) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2

        if numbers[mid] < x:
            low = mid + 1


        elif numbers[mid] > x:
            high = mid - 1

        else:
            return mid

    return -1


def fibonaccianSearch(numbers, x, n):


    a = 0
    b = 1
    c = a + b

    while (c < n):
        a = b
        b = c
        c = a + b

    offset = -1

    while (c > 1):

        i = min(offset + a, n - 1)

        if (numbers[i] < x):
            c = b
            b = a
            a = c - b
            offset = i

        elif (numbers[i] > x):
            c = a
            b = b - a
            a = c - b

        else:
            return i

    if (b and numbers[n - 1] == x):
        return n - 1

    return -1

print(
    '''
    Enter 1 for binary search
    Enter 2 for fibonacci search
    Enter 0 for stop getting output
    ''')

while True:
    choice = int(input("Enter your choice: "))

    if (choice == 1):
        result = binary_search(numbers, x)

        if result != -1:
            print("Element is present at index", str(result))
            break
        else:
            print("Element is not present in list")

    elif (choice == 2):
        ind = fibonaccianSearch(numbers, x, n)
        if ind >= 0:
            print("Found at index:", ind)
            break
        else:
            print(x, "isn't present in the list")

    elif (choice == 0):
        break

    else:
        print("enter valid choice")

