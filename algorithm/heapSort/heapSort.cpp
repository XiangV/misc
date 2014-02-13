#include <iostream>
#include <memory>
#include <heapSort.hpp>

using namespace algorithm;

int main() {
	int array[] = { 78, 23, 16, 55, 32, 2, 18, 1};
	int arraySize = sizeof(array) / sizeof(array[0]);
	std::shared_ptr<Heap<int> > heap(new Heap<int>());
	heap->set(array, arraySize);
	heap->sort();
	heap->list();
	return 0;
}
