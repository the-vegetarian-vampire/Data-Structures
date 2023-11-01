#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "empty";
        }
        else
        {
            while (temp != nullptr)
            {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr)
                {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    int getLength()
    {
        return length;
    }

    void makeEmpty()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        tail = nullptr;
        length = 0;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // LL: Has Loop ( ** Interview Question)
    // Implement a function called hasLoop to detect if a given singly - linked list contains a loop(a cycle) or not  and false otherwise.
    // Function Signature :bool hasLoop(); You are required to use the Floyd's cycle-finding algorithm (also known as the "tortoise and the hare" algorithm) to detect the loop.
    // This algorithm uses two pointers, a slow pointer, and a fast pointer.The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.If there is a loop in the linked list, the two pointers will eventually meet at some point.If there is no loop, the fast pointer will reach the end of the list.bool hasLoop()
    bool hasLoop()
    {
        if (!head)
        {
            return false;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // Move 'slow' one step
            fast = fast->next->next; // Move 'fast' two steps

            if (slow == fast)
            {
                // If 'slow' and 'fast' meet, then a loop exists.
                return true;
            }
        }
        return false; // Moved outside of the while loop
    }
};