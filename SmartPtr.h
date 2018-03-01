template<typename T>
class SmartPtr {
public:
    template<typename U>
    SmartPtr(U* p);
    template<typename U>
    SmartPtr(const SmartPtr<U>& other);
    ~SmartPtr();
    T* get() const {return ptr;}
    template<typename U>
    SmartPtr<T>& operator=(const SmartPtr<U>& other);
    T operator*() {return *ptr;}
    T* operator->() {return ptr;}
    int* getCount() const {return count;}
private:
    T* ptr;
    int* count;
};

template<typename T>
template<typename U>
SmartPtr<T>::SmartPtr(U* p): ptr(p)
{
    count = new int(1);
    printf("init a SmartPtr\n");
}

template<typename T>
template<typename U>
SmartPtr<T>::SmartPtr(const SmartPtr<U>& other): ptr(other.get()), count(other.getCount())
{
    printf("init a SmartPtr by copy\n");
}

template<typename T>
SmartPtr<T>::~SmartPtr()
{
    --(*count);
    if (*count == 0) {
        delete ptr;
        delete count;
        printf("delete a SmartPtr\n");
    }
}

template<typename T>
template<typename U>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<U>& other)
{
    printf("copy a SmartPtr\n");
    ++(*(other.count));
    --(*count);
    if (*count == 0) {
        delete ptr;
        delete count;
    }
    ptr = other.get();
    count = other.getCount();
    return *this;
}
