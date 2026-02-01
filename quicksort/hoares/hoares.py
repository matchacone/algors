def QuickSort(array, low, high):
    if low < high:
        pivot = partition(array, low, high)     # find pivot
        QuickSort(array, low, pivot)          
        QuickSort(array, pivot+1, high)         

def partition(array, low, high):
    pivot = array[(low+high)/2] # make pivot the middle of the array
    
    i = low - 1
    j = high + 1
    
    while(True):
        i += 1
        while array[i] < pivot:
            i += 1
        j -= 1
        while array[j] > pivot:
            j -= 1
        
        if i >= j:
            return j
        array[i], array[j] = array[j], array[i]     # swap

test_list = [10,9,4,5,3,2,6,7,8,1]
QuickSort(test_list, 0, len(test_list)-1)
print(test_list)

