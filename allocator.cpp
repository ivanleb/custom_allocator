#include <iostream>
#include <vector>
#include <map>


template<typename T>
struct logging_allocator {
    using value_type = T;

    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    template<typename U>
    struct rebind {
        using other = logging_allocator<U>;
    };

    T *allocate(std::size_t n) {
        std::cout << "========================================" << std::endl;
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
        auto p = std::malloc(n * sizeof(T));
        if (!p)
            throw std::bad_alloc();
        return reinterpret_cast<T *>(p);
    }

    void deallocate(T *p, std::size_t n) {
        std::cout << "========================================" << std::endl;
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
        std::free(p);
    }

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args) {
        std::cout << "========================================" << std::endl;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        new(p) T(std::forward<Args>(args)...);
    };

    void destroy(T *p) {
        std::cout << "========================================" << std::endl;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        p->~T();
    }
};


