

class vector {

public:

    /* ----- Constructors ----- */
    vector();
    vector(const Vector& other);
    vector(size_t size);

    /* ----- Destructor ----- */
    ~vector();

    /* ----- Assign operators ----- */
    vector&& operator=(const vector&);

    /* ----- Element access ----- */ 
    constexpr reference at(size_t pos);
    constexpr reference operator[](size_t pos);
    constexpr reference front();
    constexpr reference back();

    /* ----- Iterators ----- */ 
    constexpr iterator begin() noexcept;
    constexpr reverse_iterator rbegin() noexcept;
    constexpr iterator end() noexcept;
    constexpr reverse_iterator rend() noexcept;

    /* ------ Capacity ----- */
    [[nodiscard]] constexpr bool empty() const noexcept;
    constexpr size_t size() const noexcept;
    constexpr void reserve(size_t new_cap);
    constexpr size_t capacity() const noexcept;

    /* ------ Modifiers ----- */
    constexpr void clear() noexcept;

    // inserts value before position
    constexpr iterator insert(const_iterator pos, const int& value);

    // inserts value before position
    constexpr iterator insert(const_iterator pos, int&& value);
    
    // inserts count copies of the value before pos
    constexpr iterator insert(const_iterator pos, size_t count, const int& value);
    
    template <class InputIt>
    // inserts elements from range [ first, last ) before pos
    constexpr iterator insert(const_iterator pos, InputIt first, InputIt last);

    // inserts elements from initializer list ilist before pos
    constexpr iterator insert (const_iterator pos, std::initializer_list<int> ilist);


    // removes the element at pos
    constexpr iterator erase(const_iterator pos);

    // removes the elements in the range [first, last)
    constexpr iterator erase(const_iterator first, const_terator last);
    
    // the new element is initialized as a copy of value
    constexpr void push_back(const int& value);

    // value is moved into the new element
    constexpr void push_back(int&& value);

    // removes the last element of the container
    constexpr void pop_back();

    // Resizes the container to contain count elements
    constexpr void resize(size_t count);

    // Exchanges the contents of the container with those of other
    constexpr void swap(vector& other) noexcept(std::allocator_traits<Allocator>::propagate_on_container_swap::value
        || std::allocator_traits<Allocator>::is_always_equal::value);
private:
    int value_type;
    value_type& reference;
    int* buffer;
    size_t size;
    size_t capacity;
};