#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> qu;
		vector<int> tmp;
		if (root) {
			qu.push(root);
		}
		else {
			return res;
		}
		int count;
		while (!qu.empty()) {
			count = qu.size();
			while (count--) {
				TreeNode*&tm = qu.front();
				tmp.push_back(tm->val);
				if (tm->left) {
					qu.push(tm->left);
				}
				if (tm->right) {
					qu.push(tm->right);
				}
				qu.pop();
			}
			res.push_back(tmp);
			tmp.clear();
		}
		return res;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		stack<queue<TreeNode*>> sq;
		queue<TreeNode*> q;
		vector<int> tmp;
		if (root) {
			q.push(root);
		}
		else {
			return res;
		}
		int count;
		while (!q.empty()) {
			count = q.size();
			sq.push(q);
			while (count--) {
				TreeNode*&tm = q.front();
				if (tm->left) {
					q.push(tm->left);
				}
				if (tm->right) {
					q.push(tm->right);
				}
				q.pop();
			}
		}
		while (!sq.empty()) {
			queue<TreeNode*>& tm = sq.top();
			while (!tm.empty()) {
				tmp.push_back(tm.front()->val);
				tm.pop();
			}
			res.push_back(tmp);
			tmp.clear();
			sq.pop();
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
	TreeNode e(-1);
	c.left = &e;
	Solution p;
	for (auto i : p.levelOrder(&root)) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	for (auto i : p.levelOrderBottom(&root)) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}