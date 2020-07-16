from queue import PriorityQueue


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# @dataclass
class TimeData:
    # default constructor 
    def __init__(self, time, value): 
        self.time = time
        self.value = value


    def __lt__(self, other):
        return self.time < other.time

    def __eq__(self, other):
        return self.time == other.time


def mergeKLists(lists):
    ans = []
    q = PriorityQueue()
    for i in range(0,len(lists)):
        if lists[i]:
            print()
            q.put((lists[i][0].time, lists[i][0], i, 0))

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
        list2.append(TimeData(2.0*i, 4))
    testlist.append(list1)
    testlist.append(list2)

    ans = mergeKLists(testlist)
    # print(len(ans))
    # print("TYPE: ", type(testlist[1][2]))
    for item in ans:
        print("Time: " ,item.time)
        print("Val: ", item.value)
        print("\n")
