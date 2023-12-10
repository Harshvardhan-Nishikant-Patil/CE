def quicksort(arr):

    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        left = [x for x in arr[1:] if x < pivot]
        right = [x for x in arr[1:] if x >= pivot]
        return quicksort(left) + [pivot] + quicksort(right)


n = int(input("enter total number of elements: "))
sorted_list = [ ]
for i in range (n):
    element = int(input("enter elements: "))
    sorted_list.append(element)


sorted_arr = quicksort(sorted_list)

print("Sorted array:", sorted_arr)