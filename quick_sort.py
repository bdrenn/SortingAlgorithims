"""
Simple python quick-sort
"""

def swap(a: list, b: int, c: int):
    " Swap elements of a list"
    temp = a[b]
    a[b] = a[c]
    a[c] = temp


def quickSort(a: list , array_length: int):
    """
    array: list of numbers
    array_length: len(array)
    """
    low_index = 0
    high_index = array_length - 1

    if (low_index < high_index):

        # Partition
        i = low_index
        j = high_index
        pivot = a[i]
        print("pivot: ", pivot)

        while(i < j):
            while(a[i] <= pivot and i < high_index):
                i = i+1
            while(a[j] > pivot and j > low_index):
                j = j-1
            if (i<j):
                swap(a, i, j)
            swap(a, low_index, j)
            print("array: ", a)
            print("i: ", i)
            print("j: ", j)


        # Recursive Call
        a[low_index: j] = quickSort(a[low_index: j], len(a[low_index:j]))
        a[j+1: high_index+1] = quickSort(a[j+1: high_index+1], len(a[j+1: high_index+1]))
    return a


# main
array = [12, 2, 4, 9, 1, 8]
quickSort(array, len(array))
print(array)
