This repository contains an implementation of a Circular Doubly Linked List (CDLL) in CPP. The Circular Doubly Linked List is a type of linked list where each node has pointers to both its previous and next nodes, and the last node links back to the first node, forming a circle.

Features
This implementation includes the following operations:

addToTail(value)
Adds a new node with the specified value at the end of the list.

addToHead(value)
Adds a new node with the specified value at the beginning of the list.

deleteFromHead()
Removes the node at the head of the list.

deleteFromTail()
Removes the node at the tail of the list.

deleteNode(value)
Deletes the first occurrence of a node with the specified value from the list.

deleteNthNode(position)
Removes the node at the specified position (1-based index).
