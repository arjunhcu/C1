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

void fun(Node* head) {
	
	if(head->next == head) {
		head->next = NULL;
		return;
	}
	
	Node* slow, *fast;
	
	slow = fast = head;
	
	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
			break;
	}
	
	//Loop found
	cout<<"loop found at :"<<slow->val<<"\n";
	if(slow == fast){
		
		cout<<"loop found\n";
		slow = head;
		while(fast->next != slow->next) {
			slow = slow->next;
			fast = fast->next;
		}
		
		cout<<"common :"<<slow->next->val<<"\n";
		fast->next = NULL;
		
		printl(head);
	}
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
	n7->next = n4;
	
	fun(n1);
	
	return 0;
}