def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def sentinel_search(arr, target):
    n = len(arr)
    last_element = arr[n - 1]
    arr[n - 1] = target
    i = 0
    while arr[i] != target:
        i += 1
    arr[n - 1] = last_element
    if i < n - 1 or arr[n - 1] == target:
        return i
    else:
        return -1

def binary_search(arr, x):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1

def fibonacci_search(arr, x, n):
    a, b = 0, 1
    c = a + b
    while c < n:
        a, b = b, c
        c = a + b
    offset = -1
    while c > 1:
        i = min(offset + a, n - 1)
        if arr[i] < x:
            c, b, a = b, a, c - b
            offset = i
        elif arr[i] > x:
            c, b, a = a, b - a, c - b
        else:
            return i
    if b and arr[n - 1] == x:
        return n - 1
    return -1

# Input for the list of numbers
numbers = []
n = int(input("Enter the number of elements: "))
for i in range(n):
    number = int(input("Enter number: "))
    numbers.append(number)
print(numbers)

# Input for the element to be searched
key = int(input("Enter the element to be searched: "))

# Menu for search options
while True:
    print('''
    Enter 1 for linear search
    Enter 2 for sentinel search
    Enter 3 for binary search
    Enter 4 for Fibonacci search
    Enter 0 to stop getting output
    ''')

    choice = int(input("Enter your choice: "))

    if choice == 1:
        result = linear_search(numbers, key)
        print(f"Element {key} found at index {result}" if result != -1 else f"Element {key} not found.")

    elif choice == 2:
        result = sentinel_search(numbers, key)
        print(f"Element {key} found at index {result}" if result != -1 else f"Element {key} not found.")

    elif choice == 3:
        result = binary_search(numbers, key)
        print(f"Element {key} found at index {result}" if result != -1 else f"Element {key} not found.")

    elif choice == 4:
        result = fibonacci_search(numbers, key, n)
        print(f"Element {key} found at index {result}" if result != -1 else f"Element {key} not found.")

    elif choice == 0:
        break

    else:
        print("Enter a valid choice")
