#include<iostream>
#include<string>
using namespace std;
template <typename T>
#define DefaultCapacity 10
class Stack {
private:
	const int EMPTY = -1;
	unique_ptr<T[]>items;
	int topidx;
	int capacity;
public:
	Stack(int initCapacity = DefaultCapacity) {
		capacity = initCapacity;
		items = make_unique<T[]>(capacity);
		topidx = EMPTY;
	}
	Stack(const Stack& s) {
		capacity = s.capacity;
		topidx = s.topidx;
		items = make_unique<T[]>(capacity);
		for (int i = 0; i <= topidx; i++) {
			items[i] = s.items[i];

		}
	}
	int count() const {	return topidx + 1;} //返回大小
	int size() const { return topidx + 1; }
	bool empty() const { return topidx == EMPTY; }//判断是否空
	bool full() const { return topidx == capacity - 1; }
	void push(const T & n) {
			if (full()) EnlargeCapacity();//扩大容量
			items[++topidx] = n;
		}
		
		void EnlargeCapacity() {
			capacity += DefaultCapacity;
			auto newspace = make_unique<T[]>(capacity);
			for (int i = 0; i <= topidx; i++) {
				newspace[i] = items[i];
			}
			items.reset();
			items = move(newspace);
		}
		void pop() {//删除top
			if (!empty()) topidx--;
			else {
				throw underflow_error("Stack is empty.");
			}
		}
		const T& top()const {//仅返回
			if (!empty()) return items[topidx];
			else {
				throw underflow_error("Stack is empty.");
			}
		}
		T& top() {//修改或返回栈顶
			if (!empty()) return items[topidx];
			else {
				throw underflow_error("Stack is empty.");
			}
		}
		void show(bool showTypeName = false) {
			if (showTypeName) cout << "Sequenced stack: ";
			if (!empty()) {
				for (int i = topidx; i >= 0; i--) {
					cout << items[i] << "->";
				}
				cout << "|." << endl;
			}
		}
		string str(bool showTypeName = false) {//以string类型返回栈中元素
			ostringstream ss;
			if (showTypeName) ss << "Sequenced stack : ";
			if (!empty()) {
				for (int i = topidx; i >= 0; i--) {
					ss << items[i] << "->";
				}
				ss << "|.";
			}
			return ss.str();
		}
	};
