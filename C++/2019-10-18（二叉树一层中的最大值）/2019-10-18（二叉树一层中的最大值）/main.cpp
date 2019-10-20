#include<iostream>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> tq;
		vector<int> max;
		TreeNode* cur;
		if (root) tq.push(root);
		int size, tmpmax;
		while (!tq.empty()) {
			size = tq.size();
			for (tmpmax = tq.front()->val; size > 0; --size) {
				cur = tq.front();
				if (cur->val > tmpmax)tmpmax = cur->val;
				if (cur->left)tq.push(cur->left);
				if (cur->right)tq.push(cur->right);
				tq.pop();
			}
			max.push_back(tmpmax);
		}
		return max;
	}
	/*vector<int> largestValues(TreeNode* root) {
		vector<TreeNode*> tq1, tq2;
		vector<int> max;
		TreeNode* cur;
		if (root) tq1.push_back(root);
		int tmpmax;
		while (!tq1.empty() || !tq2.empty()) {
			for (tmpmax = tq1.front()->val;tq1.size() > 0;) {
				cur = tq1.back();
				if (cur->val > tmpmax)tmpmax = cur->val;
				if (cur->left)tq2.push_back(cur->left);
				if (cur->right)tq2.push_back(cur->right);
				tq1.pop_back();
			}
			max.push_back(tmpmax);
			tq1 = tq2;
			tq2.clear();
		}
		return max;
	}*/
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
	for (auto i : p.largestValues(&root)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}