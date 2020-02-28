#include <iostream>
#include <vector>

using namespace std;

template <class T>
class PriorityQueue {

	struct element {
		T obj;
		int priority;
	};

	size_t size = 0;
	vector<element> heap;

	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }
	int parent(int i) { return (i - 1) / 2; }

	void swap(element* x, element* y) {
		element temp = *x;
		*x = *y;
		*y = temp;
	}
public:
	PriorityQueue() {}

	
	void insert(const T& obj, int priority) {

		element e{ obj, priority };

		if (heap.empty()) {
			heap.push_back(e);
			return;
		}

		heap.push_back(e);
		int i = (int)heap.size() - 1;
		
		while (i > 0) {
			if (heap[i].priority < heap[parent(i)].priority) {
				swap(&heap[i], &heap[parent(i)]);
				
			}
			i = parent(i);
		}
	}


	
};

int main() {
	PriorityQueue<int> pq;


	pq.insert(4, 4);
	pq.insert(2, 2);
	pq.insert(8, 8);
	pq.insert(3, 3);
	pq.insert(7, 7);
	pq.insert(1, 1);
	


	cout << endl;

	cin.get();
	return 0;
}
