#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>


#define MAX_SIZE 100

char stack[MAX_SIZE];

int top;


void Stack_Init(void);
bool isEmpty(void);
bool isFull(void);
int size(void);
char peek(void);
void push(char item);
char pop(void);
void display(void);
bool isLeftParanthesis(char ch);
bool isRightParanthesis(char ch);
char matchingRight(char ch);

int main() {	
	
	char popped_item;

	char exp[100];

	Stack_Init();
	
		
	printf("Enter an expression: ");

	fgets(exp, 100, stdin);

	for (int i = 0; exp[i] != '\0'; i++) {
		if (isLeftParanthesis(exp[i])) {
			push(exp[i]);
		}

		if (isRightParanthesis(exp[i])) {
			popped_item = pop();
			
			if ((popped_item == -1) || exp[i] != matchingRight(popped_item)) {
				printf("Invalid expression...\n");
				return 0;
			} 

		}
	}

	if (isEmpty()) {
		printf("Valid expression...\n");
	} else {
		printf("Invalid expression...\n");
	}

	
	printf("\n");
	
	return 0;
}


char matchingRight(char ch)
{
	switch (ch) {
		case '{':
			return '}';
		case '(':
			return ')';
		case '[':
			return ']';
		default :
			return 'I';
	}
	
}



bool isLeftParanthesis(char ch)
{
	switch (ch) {
		case '{':
		case '(':
		case '[':
			return true;
		default :
			return false;
	}
}


bool isRightParanthesis(char ch)
{
	switch (ch) {
		case '}':
		case ')':
		case ']':
			return true;
		default :
			return false;
	}
}




void Stack_Init(void)
{
	top = -1;
}





bool isEmpty(void)
{
	return top == -1;
}




bool isFull(void)
{
	return (top == MAX_SIZE - 1);
}




int size(void)
{
	return top + 1;
}




char peek(void)
{
	if (isEmpty()) {
		printf("Empty Stack\n");
		return -1;
	} else{
		return stack[top];
	}

}




void push(char item)
{
	if (isFull()) {
		printf("Stack is Full\n");
		return;
	} 

	stack[++top] = item;

}




char pop(void)
{
	if (isEmpty()) {
		printf("Stack is Empty\n");
		return -1;
	} 
	
	return stack[top--];

}




void display(void)
{
	if (isEmpty()) {
		printf("Stack is Empty\n");
		return;
	} 


	for (int i = 0; i <= top; i++) {
		printf("%d --> ", stack[i]);
	}

	printf("\n");

}






