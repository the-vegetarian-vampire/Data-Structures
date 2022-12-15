"""
python -i single_linked_list.py
l = LinkedList()
l.add(1)
l.add(2)
l.add(3)
l.add(4)
n = l.search(4)

 N1 = Node(10)
 l.head = N1
 l.size ()

  N2 = Node(20)
  prepend adds node to head
  append adds node to tail
  insert is anywhere
"""

class Node:
    data = None
    next_node = None
    """
    An object for storing node of a linked list.
    Models two attributes - data and the link to the next node in list
    """

    def __init__(self, data):
        self.data = data

    def __repr__(self):
        return "<Node data: %s>" % self.data

class LinkedList:
    """
    Singly linked list
    """

    def __init__(self):
        # list traversal, head models only node list has reference to, new lists created are always empty
        self.head = None

    def is_empty(self):
        return self.head == None

    def size(self):
        """
        Returns number of nodes in the list
        Takes O(n) [linear] time as opposed to (len) in Python which is constant time
        """
        current = self.head
        count = 0

        while current:
            count += 1
            current = current.next_node

        return count

    def add(self, data):
        """
        Method adds new node containing data at head of list
        Takes O(1) constant time
        """
        new_node = Node(data)
        new_node.next_node = self.head
        self.head = new_node

    def search(self, key):
        """
        Search for the first node containing data that matches the key
        Return the node or 'None' if not found
        Takes O(n) linear time
        """
        current = self.head

        while current:
            if current.data == key:
                return current
            else:
                current = current.next_node
        return None

    def insert(self, data, index):
        """
        Inserts a new node containing data at index position
        Insertion takes O(1) time but finding the node at insertion point takes O(n)
        Takes O(n) time
        """

        if index == 0:
            self.add(data)

        if index > 0:
            new = Node(data)

            position = index
            current = self.head

            while position > 1:
                current = node.next_node
                position -= 1

            prev_node = current
            next_node = current.next_node

            prev_node.next_node = new
            new.next_node = next_node

    def __repr__(self):
        """
        Return a string representation of the list.
        Takes O(n) linear time.
        """
        nodes = []
        current = self.head
        while current:
            if current is self.head:
                nodes.append("[Head: %s]" % current.data)
            elif current.next_node is None:
                nodes.append("[Tail: %s]" % current.data)
            else:
                nodes.append("[%s]" % current.data)
            current = current.next_node
        return  '-> '.join(nodes)



