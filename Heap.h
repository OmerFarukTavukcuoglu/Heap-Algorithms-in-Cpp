#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

#include "Heap.h"
#include "HeapType.h"

template <typename T>
class Heap
{
public:
    Heap(HeapType type);
    ~Heap();

    void insert(const T &value);
    T extractTop();
    bool isEmpty() const;
    T peekTop() const;
    void remove(const T &value);

private:
    std::vector<T> elements;
    HeapType heapType;

    void heapifyUp(int index);
    void heapifyDown(int index);
};
