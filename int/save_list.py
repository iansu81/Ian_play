#!/usr/bin/env python3

class LinkedListNode:
	"""A simple implementation of a doubly-linked list"""
	def __init__(self):
		self.prev = None
		self.next = None

	def insert(self, node):
		"""Insert another node before us in the list"""
		if node.prev is not None or node.next is not None:
			raise NotImplementedError("don't support inserting full lists right now")
		node.prev = self.prev
		node.next = self
		self.prev = node
		return node

	def insert_after(self, node):
		"""Insert another node after us in the list"""
		if node.prev is not None or node.next is not None:
			raise NotImplementedError("don't support inserting full lists right now")
		node.next = self.next
		node.prev = self
		self.next = node
		return node


def create_long_list(n: int) -> LinkedListNode:
	if n <= 0:
		raise ValueError("Must be positive number of nodes")
	# Create the first node
	n = n-1
	head = LinkedListNode()
	tail = head
	# Add additional nodes until we have enough
	while n > 0:
		tail = tail.insert_after(LinkedListNode())
		n -= 1
	return head


if __name__ == '__main__':
	import pickle
	import sys
	# Get number of list nodes from command line
	n = 1000
	if len(sys.argv) > 1:
		n = int(sys.argv[1])

	# Create the list and pickle it
	l = create_long_list(n)
	with open('tmpfile', 'wb') as pf:
		pickle.dump(l, pf)
