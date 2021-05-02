#ifndef _NESTED_TRIE_H_
#define _NESTED_TRIE_H_

#define NCHAR 128

template<class T>
struct TrieTreeNode {
	T val;
	bool isItem;
	TrieTreeNode *next[NCHAR];

	TrieTreeNode(): val(0), isItem(false)
	{
		memset(next, 0, sizeof(next));
	}
};

template<class T>
class LinkedTrieTree
{
public:
	LinkedTrieTree(): root(new TrieTreeNode<T>), prev(NULL), next(NULL) {}
	int insert(string key, T val)
	{
		TrieTreeNode<T> *cur = root;
		for (char u : key) {
			if (cur->next[u] == NULL)
				cur->next[u] = new TrieTreeNode<T>();
			cur = cur->next[u];
		}
		if (cur->isItem) return 0;
		cur->isItem = true;
		cur->val = val;
		return 1;
	}
	T getItem(string key)
	{
		TrieTreeNode<T> *cur = root;
		for (char u : key) {
			assert(cur->next[u] != NULL);
			cur = cur->next[u];
		}
		assert(cur->isItem);
		return cur->val;
	}
	bool find(string s)
	{
		TrieTreeNode<T> *cur = root;
		for (char u : s) {
			if (cur->next[u] == NULL) return false;
			cur = cur->next[u];
		}
		return cur->isItem;
	}
	TrieTreeNode<T> *root;
	LinkedTrieTree<T> *prev, *next;
};

template<class T>
class NestedTrie
{
	/* 具有层次结构的Map，将std::string映射到int
	 * 操作：insert插入 delete删除 newEnvironment() 新建一层 outer() 移除最新的一层
	 * find() 查找
	 */
public:
	NestedTrie(): head(new LinkedTrieTree<T>), tail(head)
	{
		newEnvironment();
	}

	void clear()
	{
		head->prev = head->next = NULL;
		tail = head;
		newEnvironment();
	}
	void newEnvironment()
	{
		LinkedTrieTree<T> *next = new LinkedTrieTree<T>();
		tail->next = next;
		next->prev = tail;
		tail = next;
	}
	int outer()
	{
		if (tail == head) return 0;
		tail = tail->prev;
		tail->next = NULL;
		return 1;
	}
	int insert(string key, T val)
	{
		return tail->insert(key, val);
	}
	bool find(string key)
	{
		LinkedTrieTree<T> *cur = tail;
		while (cur != head) {
			if (cur->find(key)) return true;
			cur = cur->prev;
		}
		return false;
	}
	T getItem(string key)
	{
		LinkedTrieTree<T> *cur = tail;
		while (cur != head) {
			if (cur->find(key)) return cur->getItem(key);
			cur = cur->prev;
		}
		assert(0);
	}
	LinkedTrieTree<T> *head, *tail;
};

#endif