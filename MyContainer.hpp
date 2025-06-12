// liorbrown@outlook.co.il

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

namespace Containers
{
    /// @brief This class represent container of generic compareable types
    /// @tparam T Items type, default is int
    template <typename T = int>
    class MyContainer
    {
        // This is the member that holds all the data
        vector<T> data;

        public:

            /// @brief Adding copy of new item to end of container
            /// @param item New item copy to add 
            void add(T item){this->data.emplace_back(item);}

            /// @brief Removes from container all items that equals to this item
            /// If itenm not found throws exception
            /// @param item Item to remove
            void remove(T item)
            {
                bool isFind = false;

                // Runs on reverse because every erase change the index of items after current item
                // and not change the previous items
                for (int i = this->data.size() - 1; i >= 0; --i)
                    // Check if current item equals to given item
                    if (item == this->data[i])
                    {
                        this->data.erase(this->data.begin() + i);
                        isFind = true;
                    }
                
                // If item not found throws exception
                if (!isFind)
                    throw invalid_argument("Given item not found in my container");
            }

            /// @brief Returns container size
            /// @return Container size
            size_t size() const {return this->data.size();}

            // ---------------- Iterators -------------------

            /// @brief This class represent const iterator that iterate all items from small to big
            class AscendingOrder
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::const_iterator iterator;

                public:

                    /// @brief Standard constructor
                    /// @param rawData Vector of data to iterate on it 
                    AscendingOrder(const vector<T>& rawData):
                        sortedData(rawData),  
                        index(0)
                    {
                        // Sorting copy of given vector
                        sort(this->sortedData.begin(), this->sortedData.end());

                        // Sets const iterator to begin of sorted vector
                        iterator = this->sortedData.cbegin();
                    }

                    /// @brief Constructor using for get end of iterator
                    /// @param size Size of the current vector
                    AscendingOrder(size_t size):index(size){}

                    /// @brief Returns copy of current item
                    /// @return Current item that pointed by iterator
                    T operator*() {return *this->iterator;}

                    /// @brief Returns const pointer to current item
                    /// @return Poiner to current item
                    const T* operator->(){return this->iterator.operator->();}

                    /// @brief Forward iterator to next item - prefix
                    /// @return This iterator after forwarding
                    AscendingOrder& operator++()
                    {
                        // Increasing index for know when got to end
                        ++this->index;
                        ++this->iterator;

                        return *this;
                    }                    

                    /// @brief Forward iterator to next item - postfix
                    /// @param  Dummy param for indicate this is postfix
                    /// @return Copy of the iterator before forwarding
                    AscendingOrder operator++(int)
                    {
                        // Creates copy of iterator before forwarding
                        AscendingOrder temp = *this;

                        // Forward iterator
                        ++*this;

                        // Return copy
                        return temp;
                    }

                    /// @brief Checks if 2 iterators are equals
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are equals, False - otherwise
                    bool operator==(AscendingOrder other) const 
                    {
                        // Iterators considerd equals if they on the same index, 
                        // or their inner iterators are equals
                        // This type of logic provide us good indication when iterator got to end
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    /// @brief Checks if 2 iterators are different
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are different, False - otherwise
                    bool operator!=(AscendingOrder other) const 
                        {return !(*this == other);}
            };

            /// @brief This class represent const iterator that iterate all items from big to small
            class DescendingOrder
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::const_reverse_iterator iterator;

                public:

                    /// @brief Standard constructor
                    /// @param rawData Vector of data to iterate on it 
                    DescendingOrder(const vector<T>& rawData):
                        sortedData(rawData),  
                        index(0)
                    {
                        // Sorting copy of given vector
                        sort(this->sortedData.begin(), this->sortedData.end());

                        // Sets const reverse iterator to begin of sorted vector
                        iterator = this->sortedData.crbegin();
                    }

                    /// @brief Constructor using for get end of iterator
                    /// @param size Size of the current vector
                    DescendingOrder(size_t size):index(size){}

                    /// @brief Returns copy of current item
                    /// @return Current item that pointed by iterator
                    T operator*() {return *this->iterator;}

                    /// @brief Returns const pointer to current item
                    /// @return Poiner to current item
                    const T* operator->(){return this->iterator.operator->();}

                    /// @brief Forward iterator to next item - prefix
                    /// @return This iterator after forwarding
                    DescendingOrder& operator++()
                    {
                        // Increasing index for know when got to end
                        ++this->index;
                        ++this->iterator;

                        return *this;
                    }

                    /// @brief Forward iterator to next item - postfix
                    /// @param  Dummy param for indicate this is postfix
                    /// @return Copy of the iterator before forwarding
                    DescendingOrder operator++(int)
                    {
                        // Creates copy of iterator before forwarding
                        DescendingOrder temp = *this;

                        // Forward iterator
                        ++*this;

                        // Return copy
                        return temp;
                    }

                    /// @brief Checks if 2 iterators are equals
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are equals, False - otherwise
                    bool operator==(DescendingOrder other) const 
                    {
                        // Iterators considerd equals if they on the same index, 
                        // or their inner iterators are equals
                        // This type of logic provide us good indication when iterator got to end
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    /// @brief Checks if 2 iterators are different
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are different, False - otherwise
                    bool operator!=(DescendingOrder other) const 
                        {return !(*this == other);}
            };

            /// @brief This class represent const iterator that iterate all items in order of
            /// smallest, bigest, one above smallest, one before biggest and so on
            class SideCrossOrder
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::const_iterator iterator;

                public:

                    /// @brief Standard constructor
                    /// @param rawData Copy of vector of data to iterate on it 
                    SideCrossOrder(vector<T> rawData):index(0)
                    {
                        // Sorting copy of vector from small to big
                        sort(rawData.begin(), rawData.end());
                        
                        size_t size = rawData.size();

                        int i = 0;
                        int jump = size - 1;

                        // Runs until jump got negative
                        while (jump >= 0)
                        {
                            // Add current item to sorted vector
                            this->sortedData.emplace_back(rawData[i]);

                            // Move index into its next right place, and decrease jump size by 1
                            i += jump * pow(-1.f, size - jump-- - 1.f);
                        }

                        // Sets iterator to begin of sorted vector
                        iterator = this->sortedData.cbegin();
                    }

                    /// @brief Constructor using for get end of iterator
                    /// @param size Size of the current vector
                    SideCrossOrder(size_t size):index(size){}

                    /// @brief Returns copy of current item
                    /// @return Current item that pointed by iterator
                    T operator*() {return *this->iterator;}

                    /// @brief Returns const pointer to current item
                    /// @return Poiner to current item
                    const T* operator->(){return this->iterator.operator->();}

                    /// @brief Forward iterator to next item - prefix
                    /// @return This iterator after forwarding
                    SideCrossOrder& operator++()
                    {
                        // Increasing index for know when got to end
                        ++this->index;
                        ++this->iterator;

                        return *this;
                    }

                    /// @brief Forward iterator to next item - postfix
                    /// @param  Dummy param for indicate this is postfix
                    /// @return Copy of the iterator before forwarding
                    SideCrossOrder operator++(int)
                    {
                        // Creates copy of iterator before forwarding
                        SideCrossOrder temp = *this;

                        // Forward iterator
                        ++*this;

                        // Return copy
                        return temp;
                    }

                    /// @brief Checks if 2 iterators are equals
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are equals, False - otherwise
                    bool operator==(SideCrossOrder other) const 
                    {
                        // Iterators considerd equals if they on the same index, 
                        // or their inner iterators are equals
                        // This type of logic provide us good indication when iterator got to end
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    /// @brief Checks if 2 iterators are different
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are different, False - otherwise
                    bool operator!=(SideCrossOrder other) const 
                        {return !(*this == other);}
            };

            /// @brief This class represent const iterator that iterate all items from last to first
            class ReverseOrder
            {
                private:
                     vector<T>::const_reverse_iterator iterator; 

                public:

                    /// @brief Constructor
                    /// @param iterator const_reverse_iterator to use in this object
                    ReverseOrder(vector<T>::const_reverse_iterator iterator):
                        iterator(iterator){}

                    /// @brief Returns copy of current item
                    /// @return Current item that pointed by iterator
                    T operator*() {return *this->iterator;}

                    /// @brief Returns const pointer to current item
                    /// @return Poiner to current item
                    const T* operator->(){return this->iterator.operator->();}

                    /// @brief Forward iterator to next item - prefix
                    /// @return This iterator after forwarding
                    ReverseOrder& operator++()
                    {
                        ++this->iterator;
                        return *this;
                    }

                    /// @brief Forward iterator to next item - postfix
                    /// @param  Dummy param for indicate this is postfix
                    /// @return Copy of the iterator before forwarding
                    ReverseOrder operator++(int)
                    {
                        // Creates copy of iterator before forwarding
                        ReverseOrder temp = *this;

                        // Forward iterator
                        ++*this;

                        // Return copy
                        return temp;
                    }

                    /// @brief Checks if 2 iterators are equals
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are equals, False - otherwise
                    bool operator==(ReverseOrder other) const 
                        {return (this->iterator == other.iterator);}

                    /// @brief Checks if 2 iterators are different
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are different, False - otherwise
                    bool operator!=(ReverseOrder other) const 
                        {return (this->iterator != other.iterator);}
            };

            /// @brief This class represent const iterator that iterate all items from first to last
            class Order
            {
                private:
                    vector<T>::const_iterator iterator;

                public:

                    /// @brief Constructor
                    /// @param iterator const_iterator to use in this object
                    Order(vector<T>::const_iterator iterator):
                        iterator(iterator){}

                    /// @brief Returns copy of current item
                    /// @return Current item that pointed by iterator
                    T operator*() {return *this->iterator;}

                    /// @brief Returns const pointer to current item
                    /// @return Poiner to current item
                    const T* operator->(){return this->iterator.operator->();}

                    /// @brief Forward iterator to next item - prefix
                    /// @return This iterator after forwarding
                    Order& operator++()
                    {
                        ++this->iterator;
                        return *this;
                    }
                   
                    /// @brief Forward iterator to next item - postfix
                    /// @param  Dummy param for indicate this is postfix
                    /// @return Copy of the iterator before forwarding
                    Order operator++(int)
                    {
                        // Creates copy of iterator before forwarding
                        Order temp = *this;

                        // Forward iterator
                        ++*this;

                        // Return copy
                        return temp;
                    }

                    /// @brief Checks if 2 iterators are equals
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are equals, False - otherwise
                    bool operator==(Order other) const {return (this->iterator == other.iterator);}

                    /// @brief Checks if 2 iterators are different
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are different, False - otherwise
                    bool operator!=(Order other) const {return this->iterator != other.iterator;}
            };          

            /// @brief This class represent const iterator that iterate all items from middle to edges
            /// in order of less then middle and then greater then middle and so on
            class MiddleOutOrder 
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::const_iterator iterator;

                public:

                    /// @brief Standard constructor
                    /// @param rawData Vector of data to iterate on it 
                    MiddleOutOrder(const vector<T>& rawData):index(0)
                    {
                        size_t size = rawData.size();

                        int i = size / 2;
                        float jump = 1.f;

                        while (jump <= size)
                        {
                            this->sortedData.emplace_back(rawData[i]);
                            i += jump++ * pow(-1.f, jump - 1);
                        }

                        iterator = this->sortedData.cbegin();
                    }

                    /// @brief Constructor using for get end of iterator
                    /// @param size Size of the current vector
                    MiddleOutOrder(size_t size):index(size){}

                    /// @brief Returns copy of current item
                    /// @return Current item that pointed by iterator
                    T operator*() {return *this->iterator;}

                    /// @brief Returns const pointer to current item
                    /// @return Poiner to current item
                    const T* operator->(){return this->iterator.operator->();}

                    /// @brief Forward iterator to next item - prefix
                    /// @return This iterator after forwarding
                    MiddleOutOrder& operator++()
                    {
                        // Increasing index for know when got to end
                        ++this->index;
                        ++this->iterator;

                        return *this;
                    }

                    /// @brief Forward iterator to next item - postfix
                    /// @param  Dummy param for indicate this is postfix
                    /// @return Copy of the iterator before forwarding
                    MiddleOutOrder operator++(int)
                    {
                        // Creates copy of iterator before forwarding
                        MiddleOutOrder temp = *this;

                        // Forward iterator
                        ++*this;

                        // Return copy
                        return temp;
                    }

                    /// @brief Checks if 2 iterators are equals
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are equals, False - otherwise
                    bool operator==(MiddleOutOrder other) const 
                    {
                        // Iterators considerd equals if they on the same index, 
                        // or their inner iterators are equals
                        // This type of logic provide us good indication when iterator got to end
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    /// @brief Checks if 2 iterators are different
                    /// @param other 2nd iterator to compare to this
                    /// @return True - if they are different, False - otherwise
                    bool operator!=(MiddleOutOrder other) const 
                        {return !(*this == other);}
            };

            /// @brief Return AscendingOrder iterator on the first item
            /// @return AscendingOrder iterator on the first item
            AscendingOrder ascendingBegin(){return this->data;}

            /// @brief Return AscendingOrder iterator that represent the end of iteration
            /// @return AscendingOrder iterator that represent the end of iteration
            AscendingOrder ascendingEnd(){return this->data.size();}

            /// @brief Return DescendingOrder iterator on the first item
            /// @return DescendingOrder iterator on the first item
            DescendingOrder descendingBegin(){return this->data;}

            /// @brief Return descendingEnd iterator that represent the end of iteration
            /// @return descendingEnd iterator that represent the end of iteration
            DescendingOrder descendingEnd(){return this->data.size();}

            /// @brief Return Order iterator on the first item
            /// @return order iterator on the first item
            SideCrossOrder SideCrossBegin(){return this->data;}

            /// @brief Return SideCrossOrder iterator that represent the end of iteration
            /// @return SideCrossOrder iterator that represent the end of iteration
            SideCrossOrder SideCrossEnd(){return this->data.size();}

            /// @brief Return ReverseOrder iterator on the first item
            /// @return ReverseOrder iterator on the first item
            ReverseOrder crbegin(){return this->data.crbegin();}

            /// @brief Return ReverseOrder iterator that represent the end of iteration
            /// @return ReverseOrder iterator that represent the end of iteration
            ReverseOrder crend(){return this->data.crend();}

            /// @brief Return Order iterator on the first item
            /// @return order iterator on the first item
            Order cbegin(){return this->data.cbegin();}

            /// @brief Return Order iterator that represent the end of iteration
            /// @return Order iterator that represent the end of iteration
            Order cend(){return this->data.cend();}

            /// @brief Return MiddleOutOrder iterator on the first item
            /// @return order MiddleOutOrder on the first item
            MiddleOutOrder MiddleOutBegin(){return this->data;}

            /// @brief Return MiddleOutOrder iterator that represent the end of iteration
            /// @return MiddleOutOrder iterator that represent the end of iteration
            MiddleOutOrder MiddleOutEnd(){return this->data.size();}           
    };

    /// @brief Stream MyContainer object to output stream
    /// @tparam CT Type of items in container
    /// @param stream Output stream to stream MyContainer into it
    /// @param container The container to stream into output stream
    /// @return Given output stream
    template <typename CT>
    ostream& operator<<(ostream& stream, MyContainer<CT>& container)
    {
        stream << '[';

        // Before first item there isnwt separator so set it to empty
        const char* seperator = "";

        // Runs on all container on their order using Order iterator
        for
        (
            auto item = container.cbegin();
            item != container.cend();
            ++item
        )
        {
            // Put item into output stream
            stream << seperator << *item;

            // After first item insert comma before next items
            seperator = ",";
        }
            
        stream << ']';

        return stream;
    }
}