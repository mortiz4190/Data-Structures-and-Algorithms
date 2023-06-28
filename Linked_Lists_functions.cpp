#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	int data;
	node* next;	
};

class list
{  
  private:
  node *head, *tail;

  public:
  list()
  {
  head = NULL;
  tail = NULL;
  this->length = 0;
  this->head = NULL;
  }

  int length;

  void createnode(int value)
  {
      node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
  }

  void displayAll()
  {
    node *temp=new node;
		temp=head;
		while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
  }

  void pushFront(int value)
  {
    node* temp = new node();
    temp->data = value;
    temp->next = head;
    head = temp;
  }

  void topFront()
  {
  if (head == NULL)
    cout << "The list is empty!";
  else
    cout << head->data << " ";
    head = head->next;
  }


  

  void display_particularposition(int n)
  {
  node *new_node = this->head;
  for (int i = 0; i < n; i++) 
    new_node = new_node->next;
  cout << n <<": "<< new_node->data << "\n";
  }


  void popFront()
  {
  display_particularposition(0);
  }

  

  void addparticularposition(int pos, int n)
  {
  node *pre = new node();
  node *cur = new node();
  node *temp = new node();
  
  if(pos==0)
  {
    temp->data = n;
    temp->next = this->head;
    this->head = temp;
  }
  else
{
    cur=this->head;
    for (int i = 0; i < pos ; i++)
    {
      pre = cur;
      cur = cur->next;
    }
    temp->data = n;
    temp->next = cur;
    pre->next = temp;
}
this->length++;
  }
 


  void delete_particularposition(int pos)
  {
  node *pre = new node();
  node *cur = new node();
  cur = this->head;

  if(pos == 0)
  {
    pre = this->head;
    head = head->next;
  }
  else
  {
    for (int i = 0; i < pos; i++)
      {
	pre = cur;
	cur = cur->next;
      }
    pre->next = cur->next;
  }
  this->length--;
  }



  void popBack(){
    node* current = new node();
    node* previous = new node();
    current = head;
    while(current->next!=NULL)
    {
      previous = current;
      current = current->next;
    }
    tail = previous;
    previous->next=NULL;
    delete current;
  }


/////////////////////////////////Needs minor fixing
  void findKey(int x)
  {
    node* current = head; // Initialize current
    while(current != NULL)   
    {
      if (current->data == x)
          printf("True");
          current = current->next;
    }
      
      printf("False");
      
  }


////////////////////////////////Needs fixing
  void isEmpty(){ 
  node* newnode = head;
  if(newnode->next == NULL)
    cout << "List is empty.";
  else
    cout<< "List is not empty.";
  }



  void pushBack(int newdata){
    node* newnode = new node();
    node* last = head;

    newnode->data = newdata;
    newnode->next = NULL;

    if(head == NULL){
      head = newnode;
      return;
    }
    while(last->next != NULL){
      last = last->next;
    }
    last->next = newnode;
    return;
  }


  
  /*
  //////////////////////////////////////////NEEDS FIXING
  //void addBefore(node head, int d)
  node addBefore(node* given_ptr, int val)
  {
  
    // First check if the given pointer
    // is the address of head
    if (head == given_ptr) {
  
        // Create a new node
        node* n = new node();
  
        // Point to next to current head
        n->next = head;
  
        // Update the head pointer
        head = n;
        return n;
    }
    // Otherwise traverse the list to
    // find previous node of given node
    else {
  
        node *p, *n = head;
  
        // This loop will return p with
        // previous pointer of given node
        for (n, p; n != given_ptr;
             p = n, n = n->next)
            ;
  
        // Create a new node
        node* m = new node();
  
        // Update the m->next
        m->next = p->next;
  
        // Update previous node's next
        p->next = m;
  
        return m;
    }

  


}
*/
 
  void insertAfter(node* head, int data) {
    //1. Check if previous node is NULL
    node* current = head;

    if (current == NULL) {
      cout << "Previous can not be NULL";
      return;
    }

    //2. Prepare a new node
    node* newnode = new node();
    newnode->data = data;

    //3. Insert new node after previous
    newnode->next = head->next; //Stores address of node b
    head->next = newnode; //Node a will point to new node
  }



};



int main()
{
  list ssl;
  list *li = new list();
  ssl.createnode(25);
	ssl.createnode(50);
	ssl.createnode(90);
	ssl.createnode(40);
  ssl.createnode(60);

  puts("Created Linked List: ");
  ssl.displayAll();
  cout << endl;

  cout << endl;
  cout << "The first element of the list is: ";
  ssl.topFront();
  cout << endl;

  cout << endl;
  cout << "The list after popping the first element is: ";
  ssl.popFront();
  ssl.displayAll();
  cout << endl;


  cout << endl;
  int data = 10;
  cout << "The list after pushing "<< data <<" to the back is: ";
  ssl.pushBack(data);
  ssl.displayAll();
  cout << endl;

  cout << endl;
  cout << "The list after popping last element is: ";
  ssl.popBack(); 
  ssl.displayAll();
  cout << endl;

  //////////////////////////////////////// NEEDS MINOR FIXING
  cout << endl;
  cout << "Is 90 in our list? (0 means no, 10 means yes)" << endl;
  ssl.findKey(90); // Returns 0 if not in list, returns 10 if in list NEEDS FIXING
  cout << endl;

  cout << endl;
  cout << "The following function will add ___ before ____" << endl;
  //ssl.addBefore(head, 90); // NEEDS FIXING
  cout << endl;

  cout << endl;
  cout << "The following function will add 1 after 25" << endl;
  //ssl.insertAfter(head , 1); // NEEDS FIXING
  cout << endl;

  ssl.popBack(); 
  ssl.popBack(); 
  ssl.popBack(); 
  ssl.popBack(); 
  ssl.popBack(); 
  cout << "This list after popping all items is: ";
  //ssl.isEmpty; // NEEDS FIXING
  ssl.displayAll();

  system("pause");

  return 0;
  
}
