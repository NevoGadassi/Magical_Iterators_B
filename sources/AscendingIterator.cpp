
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator = (const AscendingIterator& other) {
    if (&container != &other.container) {
        throw runtime_error("cant build with the same container");
    }
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: begin () const {
    return AscendingIterator(container, 0);
}
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end () const {
    return AscendingIterator (container, container.sorted.size());
}

bool MagicalContainer :: AscendingIterator :: operator == (const AscendingIterator& other) const {
    if (&container != &other.container) {
        throw runtime_error("comparing  different containers");
    }
    return (index == other.index);
}
bool MagicalContainer :: AscendingIterator :: operator != (const AscendingIterator& other) const {
    return !(*this == other);
}
bool MagicalContainer :: AscendingIterator :: operator > (const AscendingIterator& other) const {
    if (&container != &other.container) {
        throw runtime_error("comparing  different containers");
    }
    return (index > other.index);
}
bool MagicalContainer :: AscendingIterator :: operator < (const AscendingIterator& other) const {
     if (&container != &other.container) {
        throw runtime_error("comparing  different containers");
    }
    return (index < other.index);
}
const int& MagicalContainer :: AscendingIterator :: operator * () const {
    return container.sorted.at(index);
}

MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator ++ () {
    if (index == container.sorted.size()) {
        throw runtime_error ("overflow");
    }
    index++;
    return *this;
}


