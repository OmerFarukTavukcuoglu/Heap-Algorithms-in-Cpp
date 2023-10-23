#include "Heap.h"
#include "utils.h"

template <typename T>
Heap<T>::Heap(HeapType type) : heapType(type)
{
}

template <typename T>
Heap<T>::~Heap()
{
}

template <typename T>
void Heap<T>::insert(const T &value)
{
    elements.push_back(value);
    heapifyUp(elements.size() - 1);
}

template <typename T>
T Heap<T>::extractTop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Heap is empty");
    }

    T topElement = elements[0];
    std::swap(elements[0], elements[elements.size() - 1]);
    elements.pop_back();
    heapifyDown(0);

    return topElement;
}

template <typename T>
bool Heap<T>::isEmpty() const
{
    return elements.empty();
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Heap<T> &heap)
{
    for (const T &element : heap.elements)
    {
        os << element << " ";
    }
    return os;
}

template <typename T>
void Heap<T>::heapifyUp(int index)
{
    int parentIndex = (index - 1) / 2;

    while (index > 0)
    {
        if (heapType == HeapType::MAX_HEAP && elements[index] <= elements[parentIndex])
        {
            break;
        }
        else if (heapType == HeapType::MIN_HEAP && elements[index] >= elements[parentIndex])
        {
            break;
        }

        std::swap(elements[index], elements[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

template <typename T>
void Heap<T>::heapifyDown(int index) {
    
    int rightChild = 2 * index + 2;
    int leftChild = 2 * index + 1;
    int topSideI = index;

    if (leftChild < elements.size() && ((heapType == HeapType::MAX_HEAP && elements[leftChild] > elements[topSideI]) || (heapType == HeapType::MIN_HEAP && elements[leftChild] < elements[topSideI]))) {
        topSideI = leftChild;
    }

    if (rightChild < elements.size() && ((heapType == HeapType::MAX_HEAP && elements[rightChild] > elements[topSideI]) || (heapType == HeapType::MIN_HEAP && elements[rightChild] < elements[topSideI]))) {
        topSideI = rightChild;
    }

    if (topSideI != index) {
        std::swap(elements[index], elements[topSideI]);
        heapifyDown(topSideI);
    }
}



template <typename T>
T Heap<T>::peekTop() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Heap is empty");
    }

    return elements[0];
}

template <typename T>
void Heap<T>::remove(const T &value)
{
    auto it = std::find_if(elements.begin(), elements.end(),
                           [&](const T &element)
                           {
                               return element == value;
                           });

    if (it != elements.end())
    {
        std::iter_swap(it, elements.end() - 1);
        elements.pop_back();
        heapifyDown(std::distance(elements.begin(), it));
        heapifyUp(std::distance(elements.begin(), it));
    }
}

// Explicit instantiation of the templates
template class Heap<int>;
template class Heap<Node>;
