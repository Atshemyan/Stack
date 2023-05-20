#include <stddef.h>
#include <utility>
#include <algorithm>
#include <initializer_list>

template <typename T>
class Vector
{
    public:
        Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

        Vector(std::initializer_list<T> init_list)
        {
            for (const T& item : init_list)
            {
                push_back(item);
            }
        }

        ~Vector()
        {
            delete[] m_data;
        }

        Vector& operator=(const Vector& vec)
        {
            if (this != &vec)
            {
                m_size = vec.m_size;
                m_capacity = vec.m_capacity;
                delete[] m_data;
                m_data = new T[m_capacity];
                std::copy(vec.m_data, vec.m_data + vec.m_size, m_data);
            }
            return *this;
        }

        
        void push_back(const T& value)
        {
            if (m_size == m_capacity)
            {
                reserve(m_capacity == 0 ? 1 : m_capacity * 2);
            }
            m_data[m_size++] = value;
        }

        void pop_back()
        {
            if (m_size > 0)
            {
                --m_size;
                m_data[m_size].~T(); 
            }
        }

        size_t size() const
        {
            return m_size;
        }

        size_t capacity() const
        {
            return m_capacity;
        }


        T& operator[](size_t index)
        {
            return m_data[index];
        }

        T back()
        {
            return m_data[size() - 1];
        }

        const T& operator[](size_t index) const
        {
            return m_data[index];
        }

        void reserve(size_t capacity)
        {
            if (capacity > m_capacity) {
                T* new_data = new T[capacity];
                std::copy(m_data, m_data + m_size, new_data);
                delete[] m_data;
                m_data = new_data;
                m_capacity = capacity;
            }
        }


        void clear()
        {
            delete[] m_data; 
            m_data = nullptr;
            m_size = 0;
            m_capacity = 0;
        }

        bool empty() const
        {
            return m_size == 0;
        }

        T* begin()
        {
            return m_data;
        }

        const T* begin() const
        {
            return m_data;
        }

        T* end()
        {
            return m_data + m_size;
        }

        const T* end() const
        {
            return m_data + m_size;
        }

        private:
            T* m_data;      
            size_t m_size;  
            size_t m_capacity;
};