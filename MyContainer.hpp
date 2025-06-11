// liorbrown@outlook.co.il

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

#define ITERATOR_OPERATORS \


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

            class AscendingOrder
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::const_iterator iterator;

                public:
                    AscendingOrder(const vector<T>& rawData):
                        sortedData(rawData),  
                        index(0)
                    {
                        sort(this->sortedData.begin(), this->sortedData.end());
                        iterator = this->sortedData.cbegin();
                    }

                    AscendingOrder(size_t size):index(size){}

                    T operator*() {return *this->iterator;}

                    AscendingOrder& operator++()
                    {
                        ++this->index;
                        ++this->iterator;

                        return *this;
                    }                    

                    AscendingOrder operator++(int)
                    {
                        AscendingOrder temp = *this;
                        ++*this;
                        return temp;
                    }

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
                    vector<T>::const_reverse_iterator iterator;

                public:
                    DescendingOrder(const vector<T>& rawData):
                        sortedData(rawData),  
                        index(0)
                    {
                        sort(this->sortedData.begin(), this->sortedData.end());
                        iterator = this->sortedData.crbegin();
                    }

                    DescendingOrder(size_t size):index(size){}

                    T operator*() {return *this->iterator;}

                    DescendingOrder& operator++()
                    {
                        ++this->index;
                        ++this->iterator;

                        return *this;
                    }

                    DescendingOrder operator++(int)
                    {
                        DescendingOrder temp = *this;
                        ++*this;
                        return temp;
                    }

                    bool operator==(DescendingOrder other) const 
                    {
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    bool operator!=(DescendingOrder other) const 
                        {return !(*this == other);}
            };

            class SideCrossOrder
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::const_iterator iterator;

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

                        iterator = this->sortedData.cbegin();
                    }

                    SideCrossOrder(size_t size):index(size){}

                    T operator*() {return *this->iterator;}

                    SideCrossOrder& operator++()
                    {
                        ++this->index;
                        ++this->iterator;

                        return *this;
                    }

                    SideCrossOrder operator++(int)
                    {
                        SideCrossOrder temp = *this;
                        ++*this;
                        return temp;
                    }

                    bool operator==(SideCrossOrder other) const 
                    {
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    bool operator!=(SideCrossOrder other) const 
                        {return !(*this == other);}
            };

            class ReverseOrder
            {
                private:
                     vector<T>::const_reverse_iterator iterator; 

                public:
                    ReverseOrder(vector<T>::const_reverse_iterator iterator):
                        iterator(iterator){}

                    T operator*() {return *this->iterator;}

                    ReverseOrder& operator++()
                    {
                        ++this->iterator;
                        return *this;
                    }

                    ReverseOrder operator++(int)
                    {
                        ReverseOrder temp = *this;
                        ++*this;
                        return temp;
                    }

                    bool operator==(ReverseOrder other) const 
                        {return (this->iterator == other.iterator);}

                    bool operator!=(ReverseOrder other) const 
                        {return (this->iterator != other.iterator);}
            };

            class Order
            {
                private:
                    vector<T>::const_iterator iterator;

                public:
                    Order(vector<T>::const_iterator iterator):
                        iterator(iterator){}

                    T operator*() {return *this->iterator;}

                    Order& operator++()
                    {
                        ++this->iterator;
                        return *this;
                    }
                    
                    Order operator++(int)
                    {
                        Order temp = *this;
                        ++*this;
                        return temp;
                    }

                    bool operator==(Order other) const {return (this->iterator == other.iterator);}
                    bool operator!=(Order other) const {return this->iterator != other.iterator;}
            };          

            class MiddleOutOrder 
            {
                private:
                    size_t index;
                    vector<T> sortedData;
                    vector<T>::const_iterator iterator;

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

                        iterator = this->sortedData.cbegin();
                    }

                    MiddleOutOrder(size_t size):index(size){}

                    T operator*() {return *this->iterator;}

                    MiddleOutOrder& operator++()
                    {
                        ++this->index;
                        ++this->iterator;

                        return *this;
                    }

                    MiddleOutOrder operator++(int)
                    {
                        MiddleOutOrder temp = *this;
                        ++*this;
                        return temp;
                    }

                    bool operator==(MiddleOutOrder other) const 
                    {
                        return (this->index == other.index ||
                                this->iterator == other.iterator);
                    }

                    bool operator!=(MiddleOutOrder other) const 
                        {return !(*this == other);}
            };

            
            Order cbegin(){return this->data.cbegin();}
            Order cend(){return this->data.cend();}

            ReverseOrder crbegin(){return this->data.crbegin();}
            ReverseOrder crend(){return this->data.crend();}

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

        for
        (
            auto item = container.cbegin();
            item != container.cend();
            ++item
        )
        {
            stream << seperator << *item;
            seperator = ",";
        }
            
        stream << ']';

        return stream;
    }
}