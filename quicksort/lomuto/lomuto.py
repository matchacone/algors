def QuickSort(array, low, high):
    if low < high:
        pivot = partition(array, low, high)     # find pivot
        QuickSort(array, low, pivot-1)          # sort low sub-array
        QuickSort(array, pivot+1, high)         # sort high sub-array

def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    
    for j in range(low,high):
        if array[j] <= pivot:
            i += 1
            array[j], array[i] = array[i], array[j]     # swap
    array[i+1], array[high] = array[high], array[i+1]   # swap
    return i+1


test_list = [10,9,4,5,3,2,6,7,8,1]
QuickSort(test_list, 0, len(test_list)-1)
print(test_list)

