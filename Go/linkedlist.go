package main

import (
	"fmt"
	"math/rand"
	"time"
)

// Node represents a single node in a linked list
type Node struct {
	Info interface{} // The value stored within the node
	Next *Node       // Pointer to the next node in the list
}

// List represents a singly linked list
type List struct {
	Head *Node // Pointer to the first node in the list
}

// Insert adds a new node with the provided value to the end of the list
func (l *List) Insert(d interface{}) {
	newNode := &Node{Info: d, Next: nil} // Create a new Node with the given value
	if l.Head == nil {
		// If the list is empty, the new node becomes the head of the list
		l.Head = newNode
	} else {
		// Otherwise, iterate to the end of the list and append the new node
		p := l.Head
		for p.Next != nil {
			p = p.Next
		}
		p.Next = newNode
	}
}

// ShowList prints the contents of the list to the console
func (l *List) ShowList() {
	for p := l.Head; p != nil; p = p.Next {
		// Iterate through the list and print each node's value
		fmt.Printf("-> %v ", p.Info)
	}
	fmt.Println() // Print a newline at the end
}

func main() {
	// Seed the random number generator
	rand.Seed(time.Now().UnixNano())

	sl := List{} // Initialize an empty list
	for i := 0; i < 5; i++ {
		// Insert 5 random integers into the list
		sl.Insert(rand.Intn(100))
	}
	sl.ShowList() // Display the contents of the list
}
