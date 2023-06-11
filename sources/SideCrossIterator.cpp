
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator = (const SideCrossIterator& other) {
    if (&container != &other.container) {
        throw runtime_error("cant build with the same container");
    }
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: begin () const {
    return SideCrossIterator (container, 0);
}
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: end () const {
    return SideCrossIterator (container, container.sorted.size());
}
const int& MagicalContainer :: SideCrossIterator :: operator * () const {
    if (!(index % 2)) {
        return container.sorted.at(index / 2);
    }
    else {
        return container.sorted.at((container.sorted.size() - 1 - (index - 1 ) / 2));
    }
}

MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator ++ () {
    if (index == container.sorted.size()) {
        throw runtime_error ("overflow");
    }
    index++;
    return *this;
}

bool MagicalContainer :: SideCrossIterator :: operator == (const SideCrossIterator& other) const {
    if (&container != &other.container) {
        throw runtime_error("comparing  different containers");
    }
    return (index == other.index);
}
bool MagicalContainer :: SideCrossIterator :: operator != (const SideCrossIterator& other) const {
    return !(*this == other);
}
bool MagicalContainer :: SideCrossIterator :: operator > (const SideCrossIterator& other) const {
    if (&container != &other.container) {
        throw runtime_error("Comparing iterators from different containers.\n");
    }
    int first = index;
    int second = other.index;
    if (index != container.sorted.size()) {
        if((index % 2) ==0){
            first=index / 2;
        }else{
            first=container.sorted.size() - 1 - (index - 1 ) / 2;
        }
      
    }
    if (other.index != container.sorted.size()) {
        if((other.index % 2)==0){
            second=other.index / 2;
        }else{ second=(container.sorted.size() - 1 - (other.index - 1) / 2);}
    }
    return (first > second);
}
bool MagicalContainer :: SideCrossIterator :: operator < (const SideCrossIterator& other) const {
    return !(*this > other) && (*this != other);
}

