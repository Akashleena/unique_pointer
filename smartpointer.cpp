// Design and implement a custom Smart Pointer (e.g., a
// simplified unique_ptr) that manages dynamic memory allocation and deallocation for
// an object. Ensure it handles ownership correctly and prevents memory leaks

#include <iostream>

using namespace std;

template <typename T>

class UniqueArrayPtr
{
    T* ptr;
    public:
        explicit UniqueArrayPtr(size_t size){
            ptr = new T[size];
        }
    
    ~UniqueArrayPtr(){
        delete[] ptr;
    }

    UniqueArrayPtr(const UniqueArrayPtr&) = delete;
    UniqueArrayPtr& operator=(const UniqueArrayPtr&) = delete;

    T& operator[](size_t i) { return ptr[i]; }
};

int main() {
    size_t n;
    std::cout << "Enter array size: ";
    std::cin >> n;

    UniqueArrayPtr<int> arr(n);  // Allocate memory for array of ints

    std::cout << "Enter " << n << " integers:\n";
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];  // Input using overloaded []
    }

    std::cout << "You entered:\n";
    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";  // Memory automatically freed here
}
