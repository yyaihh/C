#pragma once
namespace myNode {
	template<class T>
	class ListNode {
	public:
		T m_data;
		ListNode* m_prev;
		ListNode* m_next;
	};
}

template<class T>
class ListIterator {
	typedef myNode::ListNode<T>* PNode;
	typedef ListIterator<T> Iterator;//类名太长,起个别名
public:
	//
	PNode m_pnode;
	//
	ListIterator(const PNode p = nullptr) :m_pnode(p) {}
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
	bool operator==(const Iterator& x)const{
		return m_pnode == x.m_pnode;
	}
	bool operator!=(const Iterator& x)const{
		return m_pnode != x.m_pnode;
	}
};


template<class T, class Iterator>
class ListReverseIterator {
	typedef myNode::ListNode<T>* PNode;
	typedef ListReverseIterator<T,Iterator> ReverseIterator;
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
		return m_pnode == x.m_pnod;
	}
	bool operator!=(ReverseIterator& x) {
		return m_pnode != x.m_pnode;
	}
};


template<class T>
class List {
	typedef myNode::ListNode<T> Node;
	typedef ListIterator<T> Iterator;
	typedef ListIterator<T> const_Iterator;
	typedef ListReverseIterator<T, Iterator> ReverseIterator;
	typedef ListReverseIterator<T, const_Iterator> constReverseIterator;
	Node* m_phead;
	inline void createhead(const T& val = T()) {
		m_phead = new Node;
		m_phead->m_data = val;
		m_phead->m_prev = m_phead;
		m_phead->m_next = m_phead;
		m_size = 0;
	}
	size_t m_size;
public:
	List(){
		createhead();
	}
	List(size_t n, const T& val = T()) {
		createhead();
		insert(m_phead, n, val);
	}
	List(List<T>& x) {
		createhead();
		insert(m_phead, x.begin(), x.end());
	}
	List(Iterator first, Iterator last) {
		createhead();
		insert(m_phead, first, last);
	}
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
		/*Node* tmp;
		for (Node* i = m_phead->m_next; i != m_phead; i = tmp) {
			tmp = i->m_next;
			tmp->m_prev = i->m_prev;
			i->m_prev->m_next = tmp;
			i->m_next = i->m_prev = nullptr;
			delete i;
		}
		m_size = 0;*/
		erase(begin(), end());
	}
	Iterator insert(Iterator pos, const T& val) {
		Iterator Pos = pos.m_pnode->m_prev;
		dealinsert(pos, val);
		return Pos;
	}
	Iterator insert(Iterator pos, size_t n, const T& val = T()) {
		Iterator Pos = pos.m_pnode->m_prev;
		while (n--) {
			insert(pos, val);
		}
		return Pos;
	}
	Iterator insert(Iterator pos, Iterator first, Iterator last) {
		Iterator Pos = pos.m_pnode->m_prev;
		for (Iterator val = first; val != last; ++val) {
			insert(pos, *val);
		}
		return Pos;
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
		/*Node* newnode = new Node;
		newnode->m_data = val;
		newnode->m_prev = m_phead->m_prev;
		newnode->m_next = m_phead;
		m_phead->m_prev->m_next = newnode;
		m_phead->m_prev = newnode;
		++m_size;*/
		dealinsert(--begin(), val);
	}
	void pop_back() {
		/*Node* tmp = m_phead->m_prev;
		m_phead->m_prev->m_prev->m_next = m_phead;
		m_phead->m_prev = m_phead->m_prev->m_prev;
		delete tmp;
		--m_size;*/
		erase(--end());
	}
	void push_front(const T& val) {
		/*Node* newnode = new Node;
		newnode->m_data = val;
		newnode->m_prev = m_phead;
		newnode->m_next = m_phead->m_next;
		m_phead->m_next->m_prev = newnode;
		m_phead->m_next = newnode;
		++m_size;*/
		dealinsert(++end(), val);
	}
	void pop_front() {
		/*Node* tmp = m_phead->m_next;
		m_phead->m_next = tmp->m_next;
		tmp->m_next->m_prev = m_phead;
		delete tmp;
		--m_size;*/
		erase(begin());
	}
	Iterator erase(Iterator position) {
		Node* tmp = position.m_pnode;
		++position;
		tmp->m_prev->m_next = tmp->m_next;
		tmp->m_next->m_prev = tmp->m_prev;
		delete tmp;
		--m_size;
		return position;
	}
	Iterator erase(Iterator first, Iterator last) {
		/*Node* tmp;
		for (Node* i = first.m_pnode; i != last.m_pnode; i = tmp) {
			tmp = i->m_next;
			tmp->m_prev = i->m_prev;
			i->m_prev->m_next = tmp;
			i->m_next = i->m_prev = nullptr;
			delete i;
			--m_size;
		}*/
		for (; first != last;) {
			first = erase(first);
		}
		return ++last;
	}
	void swap(List<T>& x) {
		Node* tmp;
		tmp = x.m_phead;
		x.m_phead = m_phead;
		m_phead = tmp;
	}
private:
	inline void dealinsert(Iterator& pos, const T& val) {
		Node* tmp = pos.m_pnode->m_prev;
		Node* newnode = nullptr;
		newnode = new Node;
		newnode->m_data = val;
		newnode->m_prev = tmp;
		newnode->m_next = pos.m_pnode;
		pos.m_pnode->m_prev = newnode;
		tmp->m_next = newnode;
		tmp = newnode;
		++m_size;
	}
};
