
#include <bits/stdc++.h>

using namespace std;


struct Node {
	int val;
	Node *next;
	
	Node(int v):val(v), next(NULL){}
};



void printl(Node *head) {
	while(head) {
		cout<<" "<<head->val;
		head = head->next;
	}
}

Node* fun(Node *head, Node** lhead) {
	
	if(head->next == NULL) {
		*lhead = head;
		return head;
	}
	
	Node* temp = fun(head->next, lhead);
	temp->next = head;
	head->next = NULL;
	return head;
}

int main() {
	
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	Node *n6 = new Node(6);
	Node *n7 = new Node(7);
	
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	
	printl(n1);
	
	Node *head = n1;
	fun(n1, &head);
	
	printl(head);
	
	return 0;
}