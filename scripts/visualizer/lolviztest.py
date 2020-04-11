from lolviz import *


# test linked list node
class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

head = Node('tombu')
head = Node('parrt', head)
head = Node("xue", head)


def fact(n, result):
	if n==0:
		return result
	result *= n
	print(result)
	callsviz().view()
	fact(n-1,result)
	return result

fact(4,1)
