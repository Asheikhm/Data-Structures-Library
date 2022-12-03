
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <cstddef>

const int DEFAULT_CAPACITY = 10;

// template <class T>
class vector {

public:

    using T = int;
    using value_type = T;
    using iterator = int*;
    using const_iterator = const int*;

    /* ----- Constructors ----- */
    vector()
    {
        m_size = 0;
        m_capacity = DEFAULT_CAPACITY;
        m_buffer = new std::byte[m_capacity];
    }

    // copy constructor
    vector(const vector& other)
    {
        m_capacity = other.capacity();
        m_size = other.size();
        auto const nbytes = sizeof(T) * m_capacity;
        m_buffer = new std::byte[nbytes];

        std::uninitialized_copy_n(other.m_buffer, other.m_size, m_buffer);
        // for (size_t i = 0; i < m_size; ++i)
        // {
        //     new (m_buffer + i) T(other[i]);
        // }    
    }

    vector(size_t init_size)
    {
        resize(init_size);
    }

    /* ----- Destructor ----- */
    ~vector()
    {
        std::destroy(m_buffer, m_buffer + m_size);
        delete [] m_buffer;
        m_buffer = nullptr;
    }

    /* ----- Assign operators ----- */
    vector&& operator=(const vector&);

    /* ----- Element access ----- */ 
    T& at(size_t pos) const
    {
        try {
            return m_buffer[pos];
        }
        catch (const std::out_of_range& oor) {
            std::cerr << "Out of Range error: " << oor.what() << '\n';
        }
    }

    T& operator[](size_t pos) const
    {
        return m_buffer[pos];
    }
    T& front();
    T& back();

    /* ----- Iterators ----- */ 
    iterator begin() noexcept;
    // reverse_iterator rbegin() noexcept;
    iterator end() noexcept;
    // reverse_iterator rend() noexcept;

    /* ------ Capacity ----- */
    [[nodiscard]] bool empty() const noexcept
    {
        return (m_size == 0);
    }

    size_t size() const noexcept
    {
        return m_size;
    }
    
    void reserve(size_t new_cap)
    {

    }

    size_t capacity() const noexcept
    {
        return m_capacity;
    }

    /* ------ Modifiers ----- */
    void clear() noexcept
    {
        std::destroy(m_buffer, m_buffer + m_size);
        m_size = 0;
    }

    // inserts value before position
    iterator insert(const_iterator pos, const T& value);

    // inserts value before position
    iterator insert(const_iterator pos, T&& value);
    
    // inserts count copies of the value before pos
    iterator insert(const_iterator pos, size_t count, const T& value);
    
    template <class InputIt>
    // inserts elements from range [ first, last ) before pos
    iterator insert(const_iterator pos, InputIt first, InputIt last);

    // inserts elements from initializer list ilist before pos
    iterator insert(const_iterator pos, std::initializer_list<T> ilist);

    // removes the element at pos
    iterator erase(const_iterator pos);

    // removes the elements in the range [first, last)
    iterator erase(const_iterator first, const_iterator last);
    
    // the new element is initialized as a copy of value
    void push_back(const T& value)
    {
        if (m_size + 1 > m_capacity)
        {
            resize(m_size + 1);
        }
        m_buffer[m_size] = value;
        ++m_size;
    }

    // value is moved into the new element
    void push_back(T&& value)
    {
        if (m_size + 1 > m_capacity)
        {
            resize(m_size + 1);
        }
        // At the address m_buffer + m_size, call T constructor and give it the argument "value".
        // can be a copy or a move constructor, depending of how T is implemented.
        // std::forward
        new (m_buffer + m_size) T(value);
        ++m_size;
    }

    // removes the last element of the container
    void pop_back()
    {
        if (!empty())
        {
            std::destroy_at(std::addressof(m_buffer[m_size - 1]));
            --m_size;
        }
    }

    // Resizes the container to contain count elements
    void resize(size_t count)
    {
        if (m_size > count)
        {
            T* new_buffer = new T[m_capacity];

            for (size_t i = 0; i < count; ++i)
            {
                new_buffer[i] = m_buffer[i];
            }

            delete [] m_buffer;
            m_buffer = new_buffer;
        }
        
        if (m_size < count && m_capacity < count)
        {
            m_capacity = 2 * count;
            T* new_buffer = new T[m_capacity];

            for (size_t i = 0; i < m_size; ++i)
            {
                new_buffer[i] = m_buffer[i];
            }

            delete [] m_buffer;
            m_buffer = new_buffer;            
        }
        else if (m_size < count && m_capacity > count)
        {
            T* new_buffer = new T[m_capacity];

            for (size_t i = 0; i < m_size; ++i)
            {
                new_buffer[i] = m_buffer[i];
            }

            for (size_t i = count - m_size - 1; i < count; ++i)
            {
                new_buffer[i] = 0;
            }

            delete [] m_buffer;
            m_buffer = new_buffer;
        }
    }

private:
    std::byte* m_buffer;
    size_t m_size;
    size_t m_capacity;
};