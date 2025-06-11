// liorbrown@outlook.co.il

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

#define ITERATOR_OPERATORS \
T& operator*() {return *this->iterator;} \
T* operator->() {return &*this->iterator;} \
T operator++(int) \
{ \
    T temp = *this; \
    ++*this; \
    return temp; \
}

using namespace std;

namespace Containers
{
    template <typename T = int>
    class MyContainer
    {
            vector<T> data;

        public:
            void add(T item){this->data.emplace_back(item);}

            void remove(T item)
            {
                bool isFind = false;

                for (int i = this->data.size() - 1; i >= 0; --i)
                    if (item == this->data[i])
                    {
                        this->data.erase(this->data.begin() + i);
                        isFind = true;
                    }
                
                if (!isFind)
                    throw invalid_argument("Given item not found in my container");
            }

            size_t size() const {return this->data.size();}

            class Order
            {
                private:
                    vector<T>::iterator iterator;

                public:
                    Order(vector<T>::iterator iterator):
                        iterator(iterator){}

                    T& operator++(){return *++this->iterator;}
                    
                    ITERATOR_OPERATORS
                    
                    bool operator==(Order other) const {return (this->iterator == other.iterator);}
                    bool operator!=(Order other) const {return this->iterator != other.iterator;}
            };

            class ReverseOrder 
            {
                private:
                     vector<T>::reverse_iterator iterator; 

                public:
                    ReverseOrder(vector<T>::reverse_iterator iterator):
                        iterator(iterator){}

                    T& operator++(){return *++this->iterator;}

                    ITERATOR_OPERATORS

                    bool operator==(ReverseOrder other) const 
                        {return (this->iterator == other.iterator);}

                    bool operator!=(ReverseOrder other) const 
                        {return (this->iterator != other.iterator);}
            };

            class AscendingOrder
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::iterator iterator;

                public:
                    AscendingOrder(const vector<T>& rawData):
                        sortedData(rawData),  
                        index(0)
                    {
                        sort(this->sortedData.begin(), this->sortedData.end());
                        iterator = this->sortedData.begin();
                    }

                    AscendingOrder(size_t size):index(size){}

                    T& operator++()
                    {
                        ++this->index;
                        return *++this->iterator;
                    }

                    ITERATOR_OPERATORS

                    bool operator==(AscendingOrder other) const 
                    {
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    bool operator!=(AscendingOrder other) const 
                        {return !(*this == other);}
            };

            class DescendingOrder
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::reverse_iterator iterator;

                public:
                    DescendingOrder(const vector<T>& rawData):
                        sortedData(rawData),  
                        index(0)
                    {
                        sort(this->sortedData.begin(), this->sortedData.end());
                        iterator = this->sortedData.rbegin();
                    }

                    DescendingOrder(size_t size):index(size){}

                    T& operator++()
                    {
                        ++this->index;
                        return *++this->iterator;
                    }

                    ITERATOR_OPERATORS

                    bool operator==(DescendingOrder other) const 
                    {
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    bool operator!=(DescendingOrder other) const 
                        {return !(*this == other);}
            };

            class MiddleOutOrder 
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::iterator iterator;

                public:
                    MiddleOutOrder(const vector<T>& rawData):index(0)
                    {
                        size_t size = rawData.size();

                        float counter = 1.f;
                        int i = size / 2;
                        size_t jump = 1;

                        while (counter <= size)
                        {
                            this->sortedData.emplace_back(rawData[i]);
                            i += jump++ * pow(-1.f,counter++);
                        }

                        iterator = this->sortedData.begin();
                    }

                    MiddleOutOrder(size_t size):index(size){}

                    T& operator++()
                    {
                        ++this->index;
                        return *++this->iterator;
                    }

                    ITERATOR_OPERATORS

                    bool operator==(MiddleOutOrder other) const 
                    {
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    bool operator!=(MiddleOutOrder other) const 
                        {return !(*this == other);}
            };

            class SideCrossOrder 
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::iterator iterator;

                public:
                    SideCrossOrder(vector<T> rawData):index(0)
                    {
                        sort(rawData.begin(), rawData.end());

                        size_t size = rawData.size();

                        float counter = 0.f;
                        int i = 0;
                        int jump = size - 1;

                        while (jump >= 0)
                        {
                            this->sortedData.emplace_back(rawData[i]);
                            i += jump-- * pow(-1.f,counter++);
                        }

                        iterator = this->sortedData.begin();
                    }

                    SideCrossOrder(size_t size):index(size){}

                    T& operator++()
                    {
                        ++this->index;
                        return *++this->iterator;
                    }

                    ITERATOR_OPERATORS

                    bool operator==(SideCrossOrder other) const 
                    {
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    bool operator!=(SideCrossOrder other) const 
                        {return !(*this == other);}
            };

            Order begin(){return this->data.begin();}
            Order end(){return this->data.end();}

            ReverseOrder rbegin(){return this->data.rbegin();}
            ReverseOrder rend(){return this->data.rend();}

            AscendingOrder ascendingBegin(){return this->data;}
            AscendingOrder ascendingEnd(){return this->data.size();}

            DescendingOrder descendingBegin(){return this->data;}
            DescendingOrder descendingEnd(){return this->data.size();}

            MiddleOutOrder MiddleOutBegin(){return this->data;}
            MiddleOutOrder MiddleOutEnd(){return this->data.size();}

            SideCrossOrder SideCrossBegin(){return this->data;}
            SideCrossOrder SideCrossEnd(){return this->data.size();}
    };

    template <typename CT>
    ostream& operator<<(ostream& stream, MyContainer<CT>& container)
    {
        stream << '[';
        const char* seperator = "";

        for (const CT& item : container)
        {
            stream << seperator << item;
            seperator = ",";
        }
            
        stream << ']';

        return stream;
    }
}