#ifndef _HEAP_SORT_HPP_INCLUDE_
#define _HEAP_SORT_HPP_INCLUDE_
#include <cstdlib>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
namespace algorithm {

template<typename Key> 
class Heap {
public:
	Heap() : keyList(NULL), heapSize(0), arraySize(0) {};
	~Heap() {
 		std::free(keyList);
	}
	void set(const Key* key, size_t size);
	void sort();
	void list();
	Key operator[](size_t pos) {
		return *(keyList + pos);
	}
private:
	Key* keyList;
	size_t heapSize;
	size_t arraySize;
	void maxHeapify(size_t pos);
	void build();
};

template<typename Key>
void Heap<Key>::list() {
	for(size_t size = 0; size < arraySize; ++size) {
		cout << operator[](size) << ' ';
	}
	cout << endl;
}

template<typename Key>
void Heap<Key>::sort() {
	for(size_t size = heapSize - 1; size >= 1; size--) {
		Key tmp = *keyList;
		*keyList = operator[](size);
		*(keyList + size) = tmp;
		heapSize -= 1;
		maxHeapify(0);
	}
}

template<typename Key> 
void Heap<Key>::set(const Key* key, size_t size) {
	heapSize = size;
	arraySize = size;
	keyList = (Key*)std::calloc(size, sizeof(Key));
	std::memcpy(keyList, key, size * sizeof(Key));
	build();
	sort();
}

template<typename Key>
void Heap<Key>::maxHeapify(size_t pos) {
	size_t leftPos = pos * 2 + 1;
	size_t rightPos = pos * 2 + 2;
	size_t maxPos = pos;
	if (leftPos < heapSize && operator[](leftPos) > operator[](pos)) {
		maxPos = leftPos;
	}
	if (rightPos < heapSize && operator[](rightPos) > operator[](maxPos)) {
		maxPos = rightPos;
	}
	if (maxPos != pos) {
		Key tmp = operator[](maxPos);
		*(keyList + maxPos) = operator[](pos);
		*(keyList + pos) = tmp;
		maxHeapify(maxPos);
	}
}

template<typename Key>
void Heap<Key>::build() {
	for (ssize_t begin = arraySize / 2; begin >= 0; begin--) {
		maxHeapify(begin);
	}
}

}//namespace algorithm

#endif 
