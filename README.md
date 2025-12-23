# Design and implement a custom Smart Pointer (e.g., a
// simplified unique_ptr) that manages dynamic memory allocation and deallocation for
// an object. Ensure it handles ownership correctly and prevents memory leaks

## Purpose of the Code

This code defines and uses a custom smart pointer class `UniqueArrayPtr` that manages dynamic memory allocation for arrays. It wraps raw pointers and automatically deallocates memory when the smart pointer goes out of scope. This demonstrates how to manage dynamic memory safely in C++.

## Key Features

- Allocates memory for a dynamic array using `new[]`.
- Automatically calls `delete[]` in the destructor to free memory.
- Disallows copying to enforce unique ownership semantics.
- Supports array access using `operator[]`.

## How Deallocation Happens

Memory is automatically freed in the destructor of the `UniqueArrayPtr` class:

```cpp
~UniqueArrayPtr() {
    delete[] ptr;
}
