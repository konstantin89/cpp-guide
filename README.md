# cpp-guide

[My CPP templates notes](https://github.com/konstantin89/cpp-templates)  

[CPP insights - C++ generated code explorer](https://cppinsights.io/)  

## C++ features by version
[Full list -  CPP features by standard](https://github.com/AnthonyCalandra/modern-cpp-features)

### C++11
#### Variadic length templates

### C++14
#### Generic lambda expressions
#### Lambda capture initializers
#### Return type deduction
#### Variable templates (variables that are templates)
#### std::make_unique

### C++ 17
#### std::pmr::polymorphic_allocator (with std::pmr::memory_resource)
#### std::optional
#### std::filesystem
#### Class template argument deduction
#### constexpr if (SFINAE feature - compile time if statement)
#### constexpr lambda
#### std::not_fn (function that returns NOT of its param)

### C++ 20
#### concepts (Concepts are named compile-time predicates which constrain types)
#### coroutines (special functions that can have their execution suspended and resumed)
#### Template lambdas
#### Constraints and concepts (for templates)
#### typename is implicit in some cases (From template meta programming with C++)
#### std::jthread (joinable thread)
#### std::atomic wait and notify
#### std::atomic_ref atomic reference object. std::atomic can't hold T& types.
#### std::atomic<shared_ptr<T>> We can store shared_ptr in atomic variable.

## Containers

### Sequence Containers
```
std::array
std::vector
std::deque
std::list
std::forward_list
```

### Ordered Associative Containers (based on trees)
```
std::set
std::map
std::multiset
std::multimap
```

### Unordered Associative Containers (based on hash tables)
```
std::unordered_set
std::unordered_map
std::unordered_multiset
std::unordered_miltimap
```

### Container Adaptors
Container adaptors are abstract data types that can be implemented by underlying
sequence container.  

For example: stack can be implemented by std::vector, std::list, std::deque or other container  
that supports back() and push_back().

```
std::stack
std::queue
std::priority_queue
```


### Choosing Containers
![](./cpp_containers.png)