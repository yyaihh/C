#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}TreeNode;
class Solution {
	vector<int>res;
public:
#if 0
	vector<int> preorderTraversal(TreeNode* root) {
		if (root) {
			preorderTraversal(root->left);
			preorderTraversal(root->right);
			res.push_back(root->val);
		}
		return res;
	}
#else 

	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		while () {

		}
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
	for (auto i : p.preorderTraversal(&root)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}
