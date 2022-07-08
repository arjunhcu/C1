#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	struct Node *next;
	
	Node(int valu): val(valu), next(NULL){};
};

Node* fun(Node *head) {
	
	if(head == NULL)
		return NULL;
	
	Node *slow = NULL, *fast=NULL;
	slow = fast = head;
	while(fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	if(fast->next == NULL)
		return slow;
	else
		return slow->next;
}

int main() {
	
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	Node *n6 = new Node(6);
	Node *n7 = new Node(7);
	Node *n8 = new Node(8);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	
	Node *res = fun(n1);
	
	cout<<"mid :"<<res->val<<"\n";
	
	return 0;
}