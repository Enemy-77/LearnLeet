/*
动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。换言之，收养人不能自由挑选想收养的对象。请创建适用于这个系统的数据结构，实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和dequeueCat。允许使用Java内置的LinkedList数据结构。

enqueue方法有一个animal参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。

dequeue*方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1,-1]。

示例1:

 输入：
["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [], [], []]
 输出：
[null,null,null,[0,0],[-1,-1],[1,0]]
示例2:

 输入：
["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
 输出：
[null,null,null,null,[2,1],[0,0],[1,0]]

*/

#include <vector>
#include <list>

using namespace std;

// 一开始的版本
class AnimalShelf {
public:
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
		animals_.push_back(animal);
    }

    vector<int> dequeueAny() {
		if(animals_.empty()) {
			return {-1, -1};
		}
		vector<int> any = animals_.front();
		animals_.pop_front();
		return any;
    }

    vector<int> dequeueDog() {
		for (auto it = animals_.begin(); it != animals_.end();) {
			if(it->back() == 1) {
				vector<int> dog = *it;
				animals_.erase(it);
				return dog;
			}
			++it;
		}
		return {-1, -1};
    }

    vector<int> dequeueCat() {
        for (auto it = animals_.begin(); it != animals_.end();) {
            if (it->back() == 0) {
                vector<int> cat = *it;
				animals_.erase(it);
				return cat;
            }
			++it;
        }
        return { -1, -1 };
    }

private:
	list<vector<int>> animals_;
};


// 优化后的版本。这就是设计的好处，好的设计不仅会让代码逻辑更简单，时间空间复杂度也会降低。

class AnimalShelf {
public:
    AnimalShelf() {
    }

    void enqueue(vector<int> animal) {
		animal[1] == 0 ? cat_queue_.push(animal) : dog_queue_.push(animal);
    }

    vector<int> dequeueAny() {
		vector<int> vec;
		if (cat_queue_.empty() && dog_queue_.empty()) {
			return {-1, -1};
		}
		if(cat_queue_.empty()) {
			vec = dog_queue_.front();
			dog_queue_.pop();
			return vec;
		}
		if (dog_queue_.empty()) {
			vec = cat_queue_.front();
			cat_queue_.pop();
			return vec;
		}
		if (cat_queue_.front().front() > dog_queue_.front().front()) {
			vec = dog_queue_.front();
			dog_queue_.pop();
		} else {
			vec = cat_queue_.front();
			cat_queue_.pop();
		}
		return vec;
    }

    vector<int> dequeueDog() {
		if(dog_queue_.empty()) { 
			return { -1, -1};
		}
		vector<int> dog = dog_queue_.front();
		dog_queue_.pop();
		return dog;
    }

    vector<int> dequeueCat() {
        if (cat_queue_.empty()) {
            return { -1, -1 };
        }
        vector<int> cat = cat_queue_.front();
		cat_queue_.pop();
		return cat;
    }

private:
	queue<vector<int>> dog_queue_;
	queue<vector<int>> cat_queue_;
};

