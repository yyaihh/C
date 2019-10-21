#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
class Solution {
	vector<int>res;
public:
#if 0
	vector<int> preorderTraversal(TreeNode* root) {
		if (root) {
			preorderTraversal(root->left);
			res.push_back(root->val);
			preorderTraversal(root->right);
		}
		return res;
	}
#else 
	#if 1
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		do {
			if (!s.empty()) {
				root = s.top();
				s.pop();
			}
			res.push_back(root->val);
			if (root->right) s.push(root->right);
			if (root->left) s.push(root->left);
		} while (!s.empty());
		return res;
	}
	#else
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		//右孩子入栈
		do{
			if (!s.empty()) {
				root = s.top();
				s.pop();
			}
			while(root) {
				res.push_back(root->val);
				if (root->right) s.push(root->right);//有右, 右孩子入栈
				root = root->left;
			}
		} while (!s.empty());
		return res;
	}
	#endif

#endif
};

int main() {
	TreeNode root(1);
	TreeNode a(2);
	TreeNode b(3);
	TreeNode c(4);
	TreeNode d(5);
	root.left = &a;
	root.right = &b;
	a.right = &c;
	b.left = &d;
	Solution p;
	for (auto i : p.preorderTraversal(&root)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}
