# cpp-guide

[My CPP templates notes](https://github.com/konstantin89/cpp-templates)

## C++ features by version

### C++ 17
#### std::pmr::polymorphic_allocator
#### std::optional
#### Class template argument deduction

### C++ 20
#### Template lambdas
#### Constraints and concepts (for templates)

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