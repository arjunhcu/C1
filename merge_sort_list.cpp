#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	struct Node* next;
	
	Node(int v):val(v),next(NULL){}
};


Node* merge(Node* l1, Node* l2) {
	
	Node* tail = NULL, *head;
	
	while(l1 && l2) {
		
		if(tail == NULL) {
			if(l1->val <= l2->val) {
				head = tail = l1;
				l1 = l1->next;
			} else {
				head = tail = l2;
				l2 = l2->next;
			}
		} else {
			if(l1->val <= l2->val) {
				tail->next = l1;
				tail = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				tail = l2;
				l2 = l2->next;
			}
		}	
	}
	if(l1)
		tail->next = l1;
	else
		tail->next = l2;
	
	return head;
}

Node *mid(Node* head) {
	if(head == NULL || head->next == NULL)
		return head;
	
	Node* slow = head, *fast = head;
	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
}


Node *sort(Node* head) {
	if(head == NULL || head->next == NULL)
		return head;
	
	Node* m = mid(head);
	Node *h2 = m->next;
	m->next = NULL;
	
	Node* l1 = sort(head);
	Node* l2 = sort(h2);
	
	return merge(l1, l2);
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
	Node *n9 = new Node(9);
	
	n1->next = n3;
	n3->next = n5;
	n5->next = n7;
	n7->next = n9;
	n9->next = n2;
	n2->next = n4;
	n4->next = n6;
	n6->next = n8;
	//n8->next = n9;
	
	
	Node *head = sort(n1);
	while(head) {
		cout<<" "<<head->val;
		head = head->next;
	}
	
	return 0;
}
 