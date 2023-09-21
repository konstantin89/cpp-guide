#include <iostream>
#include <experimental/vector>
#include <experimental/memory_resource>

// On this GCC version, pmr is still experimental. 
// gcc version 8.3.0 (Raspbian 8.3.0-6+rpi1)

// std output:
//   allocate: 4
//   allocate: 8
//   deallocate: 4
//   allocate: 16
//   deallocate: 8
//   deallocate: 16


class PrintingResource : public std::experimental::pmr::memory_resource 
{
public:
  PrintingResource() : mResource{std::experimental::pmr::get_default_resource()} 
  {

  }

private:
  void* do_allocate(std::size_t bytes, std::size_t alignment) override 
  {
    std::cout << "allocate: " << bytes << '\n';
    return mResource->allocate(bytes, alignment);
  }

  void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override 
  {
    std::cout << "deallocate: " << bytes << '\n';
    return mResource->deallocate(p, bytes, alignment);
  }

  bool do_is_equal(const std::experimental::pmr::memory_resource& other) const noexcept override 
  {
    return (this == &other);
  }

  std::experimental::pmr::memory_resource* mResource;  // Default resource
};


int main()
{
    // The advantage of pmr::vector over std::vector is that if you create
    // std::vector with custom constructor, function that accepts std::vector<int> will not accept
    // std::vector<int, MyAllocator>. The size of the class is different and the class is considered different.
    // 
    // To solve that, pmr adds another abstraction layer that hides the resource that handles 
    // the memory from the allocator.
    //
    // From C++ high Performance: Master the art of optimizing the functioning of your C++ code (page 234).


    auto resource = PrintingResource{};

    auto vec = std::experimental::pmr::vector<int>{&resource};

    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(1);

    return 0;
}