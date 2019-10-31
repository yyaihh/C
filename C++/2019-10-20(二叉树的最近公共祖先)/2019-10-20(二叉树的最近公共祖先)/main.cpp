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
//class Solution {
//public:
//#if 0
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		TreeNode* gf = nullptr;
//		TreeNode* tmp = nullptr;
//		bool flagp = false;
//		bool flagq = false;
//		while (cur) {
//			for (; cur; cur = cur->left) {
//				st.push(cur);
//			}
//			do {
//				cur = st.top();
//				st.pop();
//			} while (!(cur->right) && !st.empty());
//			cur = cur->right;
//		}
//		return nullptr;
//	}
//};
//#else
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		stack<TreeNode*> st;
//		stack<bool> tag;//标志,一一对应,对应是true则说明没有左孩子了
//		TreeNode* cur = root;
//		TreeNode* gf = nullptr;
//		TreeNode* tmp = nullptr;
//		while (cur||!st.empty()) {
//			for (; cur; cur = cur->left) {//根结点入栈
//				st.push(cur);
//				tag.push(false);
//			}
//			while (!st.empty() && tag.top()) {
//				cur = st.top();
//				//cout << cur->val << endl;
//				if (cur == p || cur == q) {
//					if (tmp) {
//						return tmp;
//					}
//					else {//
//						tmp = cur;
//					}
//				}
//				st.pop();
//				tag.pop();
//			}
//			if (!st.empty()) {
//				tag.top() = true;
//				cur = st.top()->right; //右孩子节点入栈
//			}
//			else {//栈空说明根节点都出栈了, 遍历结束
//				break;
//			}
//		}
//		return nullptr;
//	}
//#endif
//};
class Solution {
	TreeNode* a;
	TreeNode* b;
	TreeNode* fun(TreeNode* root) {
		TreeNode* l;
		TreeNode* r;
		if (a == root || root == b || root== nullptr) {
			return root;
		}
		l = fun(root->left);
		r = fun(root->right);
		if (l != nullptr && r != nullptr) {
			return root;
		}
		else if (l != nullptr) {
			return l;
		}
		else if (r != nullptr) {
			return r;
		}
		return nullptr;
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) {
			return nullptr;
		}
		a = p;
		b = q;
		return fun(root);
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
	//cout << p.lowestCommonAncestor(&root, &c, &d)->val << endl;
	TreeNode* cur = p.lowestCommonAncestor(&root, &a, &a);
	cur ? cout << cur->val << endl : cout << "没有\n";
	system("pause");
	return 0;
}
