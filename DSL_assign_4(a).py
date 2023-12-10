n = int(input("enter number of total elements: "))
numbers = []
for i in range (n):
    element = int(input("enter elements: "))
    numbers.append(element)
print(numbers)

key = int(input("enter the element to be searched: "))

def linearsearch(list1):
    for i in range (len(list1)):
        if (numbers[i] == key):
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



print(
        """
            enter 1 for linear search
            enter 2 for sentinal search
            enter 0 for stop getting output
""")
while (True):
    
    
    choice = int(input("enter your choice: "))

    if (choice == 1):
        result = linearsearch(numbers)
        if result != -1:
            print(f"Element {key} found at index {result}")
        else:
            print(f"Element {key} not found.")
    
    elif (choice == 2):
        result = sentinel_search(numbers, key)
        if result != -1:
            print(f"Element {key} found at index {result}")
        else:
            print(f"Element {key} not found.")
    
    elif (choice == 0):
        break

    else:
        print("enter valid choice")