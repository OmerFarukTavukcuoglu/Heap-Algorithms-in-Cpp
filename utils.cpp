#include "utils.h"

template <typename T>
void heapSort(std::vector<T>& myarray, HeapType heapType)
{
    Heap<T> h(heapType);
    for (const T& element : myarray)
    {
        h.insert(element);
    }
    int numb = 0;
    while (!h.isEmpty())
    {
        myarray[numb] = h.extractTop();
        numb++;
    }
}


std::vector<int> mergeSortedLists(std::vector<std::vector<int>>& mylist)
{
    Heap<Node> h(HeapType::MIN_HEAP);
    for (int x = 0; x < mylist.size(); x++)
    {
        if (!mylist[x].empty())
        {
            Node node{ mylist[x][0], x, 0 };
            h.insert(node);
        }
    }
    std::vector<int> mergedList;
    while (!h.isEmpty())
    {
        Node lowN = h.extractTop();
        mergedList.push_back(lowN.val);
        if (lowN.elementIndex + 1 < mylist[lowN.listIndex].size())
        {
            Node nextNode{ mylist[lowN.listIndex][lowN.elementIndex + 1], lowN.listIndex, lowN.elementIndex + 1 };
            h.insert(nextNode);
        }
    }
   return mergedList;
}

std::vector<int> slidingWindowMax(std::vector<int>& numeral, int y)
{
    Heap<int> high_h(HeapType::MAX_HEAP);
    std::vector<int> elementcapacity;

    for (int i = 0; i < y; i++)
    {
        high_h.insert(numeral[i]);
    }
    elementcapacity.push_back(high_h.peekTop());

    for (int x = y; x < numeral.size(); x++)
    {
        high_h.remove(numeral[x - y]);  
        high_h.insert(numeral[x]);     
        elementcapacity.push_back(high_h.peekTop());
    }

    return elementcapacity;
}
