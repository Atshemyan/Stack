#include "Vector.hpp"

template<typename T>

class Stack
{
    private:
        Vector<T> vect;
    public:
        void push(const T& val)
        {
            vect.push_back(val);
        }

        void pop()
        {
            if (vect.empty())
            {
                throw std::out_of_range("Stack is empty!");
            }

            vect.pop_back();
        }

        T top()
        {
            if (vect.empty())
            {
                throw std::out_of_range("Stack is empty!");
            }

            return vect.back();
        }

        bool empty()
        {
            return vect.empty();
        }

        size_t size()
        {
            return vect.size();
        }
};