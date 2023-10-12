# cpp-guide

[My CPP templates notes](https://github.com/konstantin89/cpp-templates)  

[CPP insights - C++ generated code explorer](https://cppinsights.io/)  

## C++ features by version

### C++11
#### Variadic length templates

### C++ 17
#### std::pmr::polymorphic_allocator
#### std::optional
#### Class template argument deduction
#### constexpr if (SFINAE feature - compile time if statement)

### C++ 20
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