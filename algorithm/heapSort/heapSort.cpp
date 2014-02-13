#include <iostream>
#include <heapSort.hpp>

using namespace algorithm;

int main() {
	int array[] = { 78, 23, 16, 55, 32, 2, 18, 1};
	int arraySize = sizeof(array) / sizeof(array[0]);
	Heap<int>* heap = new Heap<int>();
	heap->set(array, arraySize);
	heap->sort();
	heap->list();
	delete heap;
	return 0;
}
