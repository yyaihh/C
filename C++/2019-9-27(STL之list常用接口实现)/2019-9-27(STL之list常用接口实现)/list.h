#pragma once
//#include<iostream>

namespace myNode {
	template<class T>
	class ListNode {
	public:
		T m_data;
		ListNode* m_prev;
		ListNode* m_next;
	};
}


template<class T,class Ref, class Ptr>
class ListIterator {
	typedef myNode::ListNode<T>* PNode;
	typedef ListIterator<T, Ref, Ptr> Iterator;//ÀàÃûÌ«³¤
public:
	//
	PNode m_pnode;
	//
	ListIterator(PNode p = nullptr) :m_pnode(p) {}
	ListIterator(const Iterator& s) :m_pnode(s.m_pnode) {}
	T& operator*() {
		return m_pnode->m_data;
	}
	T* operator->() {
		return &(operator*());
	}
	Iterator& operator++() {
		m_pnode = m_pnode->m_next;
		return *this;
	}
	Iterator operator++(int) {
		Iterator tmp = *this;
		m_pnode = m_pnode->m_next;
		return tmp;
	}
	Iterator& operator--() {
		m_pnode = m_pnode->m_prev;
		return *this;
	}
	Iterator operator--(int) {
		Iterator tmp = *this;
		m_pnode = m_pnode->m_prev;
		return tmp;
	}
	bool operator==(Iterator& x) {
		return m_pnode->m_data == x.m_pnode->m_data;
	}
	bool operator!=(Iterator& x) {
		return m_pnode->m_data != x.m_pnode->m_data;
	}
};


template<class T, class Ref, class Ptr, class Iterator>
class ListReverseIterator {
	typedef myNode::ListNode<T>* PNode;
	typedef ListReverseIterator<T, Ref, Ptr, Iterator> ReverseIterator;
public:
	//
	PNode m_pnode;
	//
	ListReverseIterator(PNode p = nullptr) :m_pnode(p) {}
	ListReverseIterator(const ReverseIterator& s) :m_pnode(s.m_pnode) {}
	T& operator*() {
		return m_pnode->m_data;
	}
	T* operator->() {
		return &(operator*());
	}
	ReverseIterator& operator--() {
		m_pnode = m_pnode->m_next;
		return *this;
	}
	ReverseIterator operator--(int) {
		ReverseIterator tmp = *this;
		m_pnode = m_pnode->m_next;
		return tmp;
	}
	ReverseIterator& operator++() {
		m_pnode = m_pnode->m_prev;
		return *this;
	}
	ReverseIterator operator++(int) {
		ReverseIterator tmp = *this;
		m_pnode = m_pnode->m_prev;
		return tmp;
	}
	bool operator==(ReverseIterator& x) {
		return m_pnode->m_data == x.m_pnode->m_data;
	}
	bool operator!=(ReverseIterator& x) {
		return m_pnode->m_data != x.m_pnode->m_data;
	}
};


template<class T>
class List {
	typedef myNode::ListNode<T> Node;
	typedef ListIterator<T, T&, T*> Iterator;
	typedef ListIterator<T, const T&, const T*> const_Iterator;
	typedef ListReverseIterator<T, T&, T*, Iterator> ReverseIterator;
	typedef ListReverseIterator<T, const T&, const T*, const_Iterator> constReverseIterator;
	Node* m_phead;
	inline void Init(const T& val = T()) {
		m_phead = new Node;
		m_phead->m_data = val;
		m_phead->m_prev = m_phead;
		m_phead->m_next = m_phead;
	}
	size_t m_size;
public:
	List() :m_size(0){
		Init();
	}
	List(size_t n, const T& val = T()) {
		Init();
		m_size = n;
		Node* newnode = nullptr;
		Node* tmp = m_phead;
		for (size_t i = 0; i < n; i++) {
			newnode = new Node;
			newnode->m_data = val;
			newnode->m_prev = tmp;
			newnode->m_next = m_phead;
			tmp->m_next = newnode;
			tmp = newnode;
		}
	}
	List(List<T>& x) {
		Init();
		m_size = x.size();
		Node* newnode = nullptr;
		Node* tmp = m_phead;
		for (Node* val = x.m_phead->m_next; val != x.m_phead; val = val->m_next) { 
			newnode = new Node;
			newnode->m_data = val->m_data;
			newnode->m_prev = tmp;
			newnode->m_next = m_phead;
			m_phead->m_prev=newnode;
			tmp->m_next = newnode;
			tmp = newnode;
		}
	}
	/*List() {

	}*/
	~List() {
		clear();
		if (m_phead) {
			delete m_phead;
		}
		m_size = 0;
	}
	Iterator begin() {
		return Iterator(m_phead->m_next);
	}
	Iterator end() {
		return Iterator(m_phead);
	}
	ReverseIterator rbegin() {
		return ReverseIterator(m_phead);
	}
	ReverseIterator rend() {
		return ReverseIterator(m_phead);
	}
	bool empty() const {
		return m_phead->m_next == m_phead;
	}
	size_t size() const {
		return m_size;
	}
	void clear() {
		Node* tmp;
		for (Node* i = m_phead->m_next; i != m_phead; i = tmp) {
			tmp = i->m_next;
			tmp->m_prev = i->m_prev;
			i->m_prev->m_next = tmp;
			i->m_next = i->m_prev = nullptr;
			delete i;
		}
		m_size = 0;
	}
	T& front() {
		return m_phead->m_next->m_data;
	}
	T& back() {
		return m_phead->m_prev->m_data;
	}
	const T& front()const {
		return m_phead->m_next->m_data;
	}
	const T& back() const{
		return m_phead->m_prev->m_data;
	}
	void push_back(const T& val) {
		Node* newnode = new Node;
		newnode->m_data = val;
		newnode->m_prev = m_phead->m_prev;
		newnode->m_next = m_phead;
		m_phead->m_prev->m_next = newnode;
		m_phead->m_prev = newnode;
		++m_size;
	}

};
