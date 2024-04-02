#include <iostream>


using namespace std;

class Object{
    private:
        int a;
};


class allocator{
		
    static char * heap;
    static size_t reserved = 0;
	

    static void* init(size_t size){
        heap = malloc(size);
        
        return reinterpret_cast<void*>(heap);
    }


        return reinterpret_cast<void*>(p);
    }

    void* free(void* ptr){

    }


    template<typename T>
    void* allocate(T t){

    }
};

int main() {
    auto ptr = allocator::init(1024*1024*8);
    
		SomeDataType* p = reinterpret_cast<SomeDataType*>(ptr);
    
    allocator alloc = ??;
    
} 