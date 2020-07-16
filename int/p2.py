from queue import PriorityQueue


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# @dataclass
class TimeData:
    time = 0.  # in seconds
    value = 0.

    # default constructor 
    def __init__(self, time, value): 
        self.time = time
        self.value = value

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        # head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.time, l))
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next


if __name__ == '__main__':
    data1 = TimeData(5,3)
    data1 = TimeData(6,3)
    data1 = TimeData(7,3)
    data1 = TimeData(8,3)
    data1 = TimeData(9,3)
    print(data1.value)