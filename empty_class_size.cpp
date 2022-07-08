#include <iostream>
#include <vector>

using namespace std;

class A {
	public :
		//int a;
		virtual void fun() {
			cout<<"inside virtual\n";
		}
};

struct TreeNode {
	vector<TreeNode *>childs;
};

int fun(TreeNode *root, int im) {
	if(root == NULL)
		return 0;
	
	if(root->childs.size() == 0)
		return im ? 1:0;
	
	int with_im = 1, without_im = 0;
	
	if(im) {
		for(auto child : root->childs)
			with_im += fun(child, 0);
	} else {
		for(auto child : root->childs)
			without_im += fun(child,1);
	}
	return max(with_im, without_im);
}


int main() {
	
	struct TreeNode *root = new TreeNode();
	struct TreeNode *t1 = new TreeNode();
	struct TreeNode *t2 = new TreeNode();
	struct TreeNode *t3 = new TreeNode();
	struct TreeNode *t4 = new TreeNode();
	struct TreeNode *t5 = new TreeNode();
	struct TreeNode *t6 = new TreeNode();
	struct TreeNode *t7 = new TreeNode();
	struct TreeNode *t8 = new TreeNode();
	struct TreeNode *t9 = new TreeNode();
	
	root->childs.push_back(t1);
	root->childs.push_back(t2);
	root->childs.push_back(t3);
	
	t1->childs.push_back(t4);
	t1->childs.push_back(t5);
	
	t2->childs.push_back(t6);
	t2->childs.push_back(t7);
	t2->childs.push_back(t8);
	
	
	cout<<"max : "<<max(fun(root, 0), fun(root, 1))<<"\n";
	return 0;
}