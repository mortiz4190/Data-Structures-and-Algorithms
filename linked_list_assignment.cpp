#include <iostream>

using namespace std;
 
// A linked list node
class Node{
public:
    int data;
    Node* next;
};

// Push function
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Delete node function
Node* deleteAll(Node *head,int x)
{
     
    // Store head node
    Node *tmp = head;
     
    while (head->data == x)
    {
        head = head->next;
    }
    while (tmp->next != NULL)
    {
        if (tmp->next->data == x)
        {
            tmp->next = tmp->next->next;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return head;
}

//insert beginning function
void insertBeg(Node** headRef, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  //initializing the next of the newNode to the  previous head
  newNode->next = (*headRef);
// updating the head of the linked list
  (*headRef) = newNode;
}


//print list code
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

//Retrives node for insertPos() function
Node* getNode(int data)
{
    // allocating space
    Node* newNode = new Node();
 
    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int size = 0;
//insertPos() function
void insertPos(Node** current, int p, int data)
{
    // This condition to check whether the
    // position given is valid or not.
    if (p < 1 || p > size + 1)
        cout << "Invalid position!" << endl;
    else {
 
        // Keep looping until the pos is zero
        while (p--) {
 
            if (p == 0) {
              Node* temp= getNode(data);
                // Making the new Node to point to
                // the old Node at the same position
                temp->next = *current;
 
                // Changing the pointer of the Node previous
                // to the old Node to point to the new Node
                *current = temp;
            }
            else
              // Assign double pointer variable to point to the
              // pointer pointing to the address of next Node
              current = &(*current)->next;
        }
        size++;
    }
}

//Driver code
int main()
{
    size = 4;
    // Start with the empty list
    Node* head = NULL;

    push(&head, 3);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);
    cout << endl;
  
    head = deleteAll(head, 3);
    cout << "\nLinked List after Deletion is:\n";
    printList(head);
    cout << endl;

    cout << endl;
    cout << "Linked list before insertion: ";
    printList(head);
    cout << endl;
  
    cout << endl;
    int data = 12, p = 2;
    insertPos(&head, p, data);
    cout << "Linked list after insertion of 12 at position 2: ";
    printList(head);

    return 0;
}