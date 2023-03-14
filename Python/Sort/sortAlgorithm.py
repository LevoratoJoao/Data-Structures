class SortAlgorithm:
    def __init__(self, array):
        self.data = array
    def bubbleSort(self):
        len(self.data)
        trade = True
        while (trade is True):
            trade = False
            for i in range(0, len(self.data) - 1):
                if self.data[i] > self.data[i+1]:
                    self.data[i], self.data[i+1] = self.data[i+1], self.data[i]
                    trade = True
        return self.data

    def selectionSort(self):
        for i in range(0, len(self.data) - 1):
            lower = i
            for j in range(i + 1, len(self.data)):
                if self.data[j] < self.data[lower]:
                    lower = j
            self.data[i], self.data[lower] = self.data[lower], self.data[i]
        return self.data
