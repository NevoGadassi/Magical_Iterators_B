#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <stdexcept>
#include <vector>
#include <iostream>

namespace ariel {
    class MagicalContainer {
       std::vector <int*> prime;
        std::vector <int> sorted;

    public:
        MagicalContainer () {};

        void addElement (int);
        size_t size() const;
         void removeElement (int);

        class AscendingIterator {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            AscendingIterator (MagicalContainer& container, size_t index = 0) : container(container), index(index) {

                if (index > container.sorted.size()) { throw std :: invalid_argument("index bigger than container"); }
            }
            AscendingIterator (const AscendingIterator& other) : container(other.container), index(other.index) {}
            ~AscendingIterator () = default;

            AscendingIterator begin () const;
            AscendingIterator end () const;
            AscendingIterator& operator = (const AscendingIterator&);
        

        
            bool operator == (const AscendingIterator&) const;
            bool operator != (const AscendingIterator&) const;
            bool operator < (const AscendingIterator&) const;
            bool operator > (const AscendingIterator&) const;
            const int& operator * () const;
            AscendingIterator& operator ++ ();

        };

       class SideCrossIterator {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            SideCrossIterator (MagicalContainer& container, size_t index = 0) : container(container), index(index) {
                if (index > container.sorted.size()) { throw std :: invalid_argument("index bigger than container"); }
            }
            SideCrossIterator (const SideCrossIterator& other) : container(other.container), index(other.index) {}
            ~SideCrossIterator () = default;

            SideCrossIterator begin () const;
            SideCrossIterator end () const;
            SideCrossIterator &operator = (const SideCrossIterator&);

            bool operator == (const SideCrossIterator&) const;
            bool operator != (const SideCrossIterator&) const;
            bool operator > (const SideCrossIterator&) const;
            bool operator < (const SideCrossIterator&) const;
            const int& operator * () const;
            SideCrossIterator& operator ++ ();

        };

        class PrimeIterator {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            PrimeIterator (MagicalContainer& container, size_t index = 0) : container(container), index(index) {
                if (index > container.prime.size()) { throw std :: invalid_argument("index bigger than container"); }
            }
            PrimeIterator (const PrimeIterator& other) : container(other.container), index(other.index) {}
            ~PrimeIterator () = default;

            PrimeIterator begin () const;
            PrimeIterator end () const;
            PrimeIterator& operator = (const PrimeIterator&);


            bool operator == (const PrimeIterator&) const;
            bool operator != (const PrimeIterator&) const;
            bool operator > (const PrimeIterator&) const;
            bool operator < (const PrimeIterator&) const;
            const int& operator * () const;
            PrimeIterator &operator ++ ();
            static bool isPrime (int);

        };
    };
}
#endif //MAGICALCONTAINER_H