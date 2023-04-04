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

def _partition(array, start, end):
    left = start
    right = end
    pivot = array[start]
    while (left < right):
        while (left <= end and array[left] <= pivot):
            left += 1
            print(f'left {left}')
        while (array[right] >= pivot and right >= start):
            right -= 1
            print(f'right {right}')
        if left < right:
            array[left], array[right] = array[right], array[left]
        else:
            break
    array[start], array[right] = array[right], array[start]
    return right
        

def __quickSort(array, start, end):
    if ():
        split = partition(array, start, end)
        __quickSort(array, start, split - 1)
        __quickSort(array, split + 1, end)

def _quickSort(array):
    array = __quickSort(array, 0, len(array) - 1)
    return array

def quickSort(alist):
   quickSortHelper(alist,0,len(alist)-1)
   return alist


def quickSortHelper(alist,first,last):
   if first<last:
       splitpoint = partition(alist,first,last)
       quickSortHelper(alist,first,splitpoint-1)
       quickSortHelper(alist,splitpoint+1,last)


def partition(array, first, last):
   pivotvalue = array[first]
   leftmark = first+1
   rightmark = last

   done = False
   while not done:
       while leftmark <= rightmark and array[leftmark] <= pivotvalue:
           leftmark = leftmark + 1

       while array[rightmark] >= pivotvalue and rightmark >= leftmark:
           rightmark = rightmark -1

       if rightmark < leftmark:
           done = True
       else:
           array[leftmark], array[rightmark] = array[rightmark], array[leftmark]

   array[first], array[rightmark] = array[rightmark], array[first]
   return rightmark