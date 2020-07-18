from queue import PriorityQueue

# @dataclass
class TimeData:
    # default constructor 
    def __init__(self, time, value): 
        self.time = time
        self.value = value

    # Comparator
    def __lt__(self, other):
        return self.time < other.time

    def __eq__(self, other):
        return self.time == other.time


def mergeKLists(lists):
    ans = []
    # Create a priority queue which its size is equivalent to the length of the list
    # ex: if we are going to merge 3 lists, the size of queue is 3
    q = PriorityQueue()

    # Put the first element in each lists to the queue
    for i in range(0,len(lists)):
        if lists[i]:
            print()
            q.put((lists[i][0].time, lists[i][0], i, 0))

    # Pop the first element in the queue (smallest) out and put it in the ans list
    # Then push the next element which that element originated from into the queue 
    # -time data: the object we want to sort
    # -listt_index: record where the object is originated from
    # -index_in_list: record the object's index in its original list
    while not q.empty():
        _, time_data, list_index, index_in_list = q.get()
        ans.append(time_data)
        next_time_data_index = index_in_list + 1
        if next_time_data_index < len(lists[list_index]):
            q.put((lists[list_index][next_time_data_index].time, lists[list_index][next_time_data_index],
                   list_index, next_time_data_index))
    return ans


if __name__ == '__main__':

    list1 = []
    list2 = []
    testlist = []
    for i in range(3,10):
        list1.append(TimeData(float(i), 3))
        list2.append(TimeData(5.0*i, 4))
    testlist.append(list1)
    testlist.append(list2)

    ans = mergeKLists(testlist)
    for item in ans:
        print("Time: " ,item.time)
        print("Val: ", item.value)
        print("\n")
