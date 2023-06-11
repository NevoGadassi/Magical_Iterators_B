
#include "MagicalContainer.hpp"
#include <algorithm>
using namespace std;
using namespace ariel;


size_t MagicalContainer :: size () const {
    return sorted.size();
}
void MagicalContainer :: addElement (int newelement) {
    for (auto item = sorted.begin(); item != sorted.end(); ++item) {
        if (*item == newelement) { return; }
    }
    auto index = lower_bound(sorted.begin(), sorted.end(), newelement);
    sorted.insert(index, newelement);
    prime.clear();
    for (size_t i = 0; i < sorted.size(); i++) {
        if (PrimeIterator :: isPrime(sorted.at(i))) {
            prime.push_back(&sorted.at(i));
        }
    }
}


void MagicalContainer :: removeElement (int oldelement) {
    bool remove = false;
    if (PrimeIterator :: isPrime(oldelement)) {
        for (auto item = prime.begin(); item != prime.end(); ++item) {
            if (**item == oldelement) {
                prime.erase(item);
                break;
            }
        }
    }
    for (auto item = sorted.begin(); item != sorted.end(); ++item) {
        if (*item == oldelement) {
            sorted.erase(item);
            remove = true;
            break;
        }
    }
    if (!remove) {
        throw runtime_error(" not in the container");
    }
}

