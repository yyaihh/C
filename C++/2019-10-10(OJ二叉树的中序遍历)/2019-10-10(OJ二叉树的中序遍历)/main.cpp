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
	vector<int> inorderTraversal(TreeNode* root) {
		if (root) {
			res.push_back(root->val);
			inorderTraversal(root->left);
			inorderTraversal(root->right);
		}
		return res;
	}
#else 
	vector<int> inorderTraversal(TreeNode* root) {
		//×óº¢×ÓÈëÕ»
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (cur) {
			for (; cur; cur = cur->left) {
				s.push(cur);
			}
			do {
				cur = s.top();
				res.push_back(cur->val);
				s.pop();
			} while (cur->right == nullptr && !s.empty());
			cur = cur->right;
		}
		return res;
	}

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
	for (auto i : p.inorderTraversal(&root)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}
