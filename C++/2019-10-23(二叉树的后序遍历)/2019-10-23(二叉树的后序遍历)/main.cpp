#include<iostream>
#include<stack>
#include<vector>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}TreeNode;

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		stack<bool> tag;
		vector<int> res;
		TreeNode* cur = root;
		while (cur||!st.empty()) {
			for (; cur; cur = cur->left) {
				st.push(cur);
				tag.push(false);
			}
			while (!st.empty() && tag.top()) {
				res.push_back(st.top()->val);
				st.pop();
				tag.pop();
			}
			if (!st.empty()) {
				tag.top() = true;
				cur = st.top()->right;
			}
			else {
				break;
			}
		}
		return res;
	}
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
	for (auto i : p.postorderTraversal(&root)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}