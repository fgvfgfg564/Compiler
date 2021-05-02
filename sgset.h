#ifndef _SGSET_H_
#define _SGSET_H_

#include <set>
#include <vector>
using namespace std;

#define PRESET_SIZE 20

class SGSet
{
	/*
	 * 数据结构维护一个集合，支持求最小的不在集合中的元素并将其插入集合，以及从集合中删除元素
	 */
public:
	SGSet()
	{
		for (int i = 0; i < PRESET_SIZE; i++)S.insert(i);
		back.clear();
	}
	int get()
	{
		if (S.empty()) {
			for (int i = PRESET_SIZE;; i++) {
				if (back.find(i) != back.end()) {
					back.insert(i);
					return i;
				}
			}
		} else {
			int u = *S.begin();
			S.erase(S.begin());
			return u;
		}
	}
	void recover(int x)
	{
		if (x < PRESET_SIZE) {
			assert(S.find(x) == S.end());
			S.insert(x);
		} else {
			assert(back.find(x) != back.end());
			back.erase(x);
		}
	}
	bool isClean()
	{
		return back.size() == 0 && S.size() == PRESET_SIZE;
	}
private:
	set<int> S;
	set<int> back;
};

#endif