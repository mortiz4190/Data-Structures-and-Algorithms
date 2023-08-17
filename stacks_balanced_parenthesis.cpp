#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX 100

//LOGIC TO TEST: Change all string declarations back to char


class Stack {
public:
	int a[MAX]; //Max size of stack
	int top;
	string exp; //char exp[100]
	Stack() { top = -1; }
	// functions prototypes
	bool push(char item);
	char pop();
};

//Define Nodes Structure
struct Node {
	char data;
	Node* next;
};

// Function to push an item to stack
void push(Node** topRef, int newData);
// Function to pop an item from stack
char pop(Node** topRef);


//Function that determines whether a character is a matching pair
int isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

//Fucntion that checks whether the parenthesis are balanced
int areParenthesisBalanced(string exp)
{
	int i = 0;
	// Declare an empty character stack
	Node* stack = NULL;
	// Traverse the given expression to check matching
	// brackets
	while (exp[i]) 
	{
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(&stack, exp[i]); 
		if (exp[i] == '}' || exp[i] == ')'
			|| exp[i] == ']') 
      {
			if (stack == NULL)
        return 0;
			else if (!isMatchingPair(pop(&stack), exp[i]))
        return 0;
        //cout << i+1;
		  }
		i++;
	}
  cout << i;
	// If stack is empty (NULL) = Balanced
  // If stack is not empty, there is an unpair parenthesis left = unbalanced
  if (stack == NULL)
		return 1; //Balanced 1 = true
	else 
    return 0;  //Unbalanced 0 = false
  
  } 


void push(Node** topRef, int newData)
{
	// allocate node
	Node* newNode = new Node();
	if (newNode == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}
	newNode->data = newData;
	newNode->next = *topRef;
	*topRef = newNode;
}


// Function to pop an item from stack
char pop(Node** topRef)
{
	char res;
	Node* top;
	// If stack is empty then error
	if (*topRef == NULL) {
		printf("Stack underflow n");
		exit(0);
	}
	else {
		top = *topRef;
		res = top->data;
		*topRef = top->next;
		return res;
	}
}







//Main function 
int main() {
	string exp;
	cout << "enter the expression : \n";
	cin >> exp;
	if (areParenthesisBalanced(exp))
		cout <<" :position" <<endl << "Success";
	else 
		cout <<" :position" <<endl <<"Not Balanced";
	return 0;
}