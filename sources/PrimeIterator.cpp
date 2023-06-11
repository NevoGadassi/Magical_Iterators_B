
#include "MagicalContainer.hpp"
#include <cmath>
using namespace std;
using namespace ariel;

MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator = (const PrimeIterator& other) {
    if (&container != &other.container) {
        throw runtime_error("cant build with the same container");
    }
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: begin () const {
    return PrimeIterator (container, 0);
}
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: end () const {
    return PrimeIterator (container, container.prime.size());
}


const int& MagicalContainer :: PrimeIterator :: operator * () const {
    return *container.prime.at(index);
}

MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator ++ () {
    if (index == container.prime.size()) {
        throw runtime_error ("overflow");
    }
    index++;
    return *this;
}

bool MagicalContainer :: PrimeIterator :: operator == (const PrimeIterator& other) const {
    if (&container != &other.container) {
        throw runtime_error("comparing  different containers");
    }
    return (index == other.index);
}
bool MagicalContainer :: PrimeIterator :: operator != (const PrimeIterator& other) const {
    return !(*this == other);
}
bool MagicalContainer :: PrimeIterator :: operator > (const PrimeIterator& other) const {
     if (&container != &other.container) {
        throw runtime_error("comparing  different containers");
    }
    return (index > other.index);
}
bool MagicalContainer :: PrimeIterator :: operator < (const PrimeIterator& other) const {
    if (&container != &other.container) {
        throw runtime_error("comparing  different containers");
    }
    return (index < other.index);
}


bool MagicalContainer :: PrimeIterator :: isPrime (int n) {
   if (n <= 1) {
        return false;
    }
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}