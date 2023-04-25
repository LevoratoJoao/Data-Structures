def bubbleSort(array, op):
    trade = True
    while (trade is True):
        trade = False
        for i in range(0, len(array) - 1):
            if array[i] > array[i+1] and op == 1:
                array[i], array[i+1] = array[i+1], array[i]
                trade = True
            if array[i] > array[i+1] and op == 0:
                array[i], array[i+1] = array[i+1], array[i]
                trade = True
    return array

def selectionSort(array, op):
    for i in range(0, len(array) - 1):
        lower = i
        for j in range(i + 1, len(array)):
            if array[j] < array[lower] and op == 1:
                lower = j
            if array[j] > array[lower] and op == 0:
                lower = j
        array[i], array[lower] = array[lower], array[i]
    return array

def insertionSort(array):
    for i in range(1, len(array)):
        tmp = array[i]
        index = i - 1
        while(index >= 0 and tmp < array[index]):
            array[index + 1] = array[index]
            index = index - 1
        array[index + 1] = tmp
    return array

def merge(array, first, last):
    i = j = k = 0
    while i < len(first) and j < len(last):
        if first[i] < last[j]:
            array[k] = first[i]
            i += 1
        else:
            array[k] = last[j]
            j += 1
        k += 1
    while i < len(first):
        array[k] = first[i]
        i += 1
        k += 1
    while j < len(last):
        array[k] = last[j]
        j += 1
        k += 1
    return array

def mergeSort(array):
    if len(array) > 1:
        middle = len(array) // 2
        first = array[:middle]
        last = array[middle:]
        mergeSort(first)
        mergeSort(last)
        array = merge(array, first, last)
    return array

def partition(array, start, end):
    pivot = array[start]
    left = start + 1
    right = end
    while (True):
        while (left <= right and array[left] <= pivot):
            left = left + 1
        while (array[right] >= pivot and right >= left):
            right = right - 1
        if left < right:
            array[left], array[right] = array[right], array[left]
        else:
            break
    array[start], array[right] = array[right], array[start]
    return right

def __quickSort(array, start, end):
    if (start < end):
        split = partition(array, start, end)
        __quickSort(array, split + 1, end)
        __quickSort(array, start, split - 1)

def quickSort(array):
    __quickSort(array, 0, len(array) - 1)
    return array

def maxHeapify(array, index, heapSize):
    left  = 2*index+1
    right = 2*index+2
    largest = index

    if(left <= (heapSize-1)) and (array[left] > array[index]):
        largest = left
    if (right <= (heapSize-1)) and (array[right] > array[largest]):
        largest = right

    if index != largest:
        array[index], array[largest] = array[largest], array[index]
        maxHeapify(array, largest, heapSize-1)

def buildMaxHeap(array, heapSize): #ok
    indexes = range(len(array) // 2, -1, -1) # stop at -1 and increment -1
    for index in indexes:
        maxHeapify(array, index, heapSize)

def heapSort(array):
    heapSize = len(array)
    buildMaxHeap(array, heapSize)
    indexes = range(len(array)-1, 0, -1)
    for index in indexes:
        array[0], array[index] = array[index], array[0]
        heapSize = heapSize - 1
        maxHeapify(array, 0, heapSize)
    return array