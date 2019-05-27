
#ifndef DUOMENUAPDOROJIMASCPP_NITERATOR_H
#define DUOMENUAPDOROJIMASCPP_NITERATOR_H

#include <iterator>

template<class T>
class NIterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
    T* ptr;
public:
    NIterator(): ptr(nullptr){};
    NIterator(T * item) : ptr(item){}

    NIterator<T> & operator=(const NIterator<T> & iter) = default;
    ~NIterator() = default;

    NIterator operator+(int add);
    NIterator operator-(int sub);
    ptrdiff_t operator-(const NIterator &it) const { return ptr - it.ptr; }

    bool operator!=(const NIterator<T> & iter) const;
    bool operator==(const NIterator<T> & iter) const;
    bool operator<(const NIterator<T> & iter) const;
    bool operator<=(const NIterator<T> & iter) const;
    bool operator>(const NIterator<T> & iter) const;
    bool operator>=(const NIterator<T> & iter) const;

    NIterator & operator++();
    NIterator operator++(int);
    NIterator & operator--();
    NIterator operator--(int);

    T & operator[](int n);
    T & operator*();
};

template<class T>
bool NIterator<T>::operator==(const NIterator<T> & iter) const {
    return ptr == iter.ptr;
}

template<class T>
bool NIterator<T>::operator!=(const NIterator<T> & iter) const {
    return ptr != iter.ptr;
}

template<class T>
bool NIterator<T>::operator<(const NIterator<T> & iter) const{
    return ptr < iter.ptr;
}

template<class T>
bool NIterator<T>::operator<=(const NIterator<T> & iter) const{
    return ptr <= iter.ptr;
}

template<class T>
bool NIterator<T>::operator>(const NIterator<T> &iter) const {
    return ptr > iter.ptr;
}

template<class T>
bool NIterator<T>::operator>=(const NIterator<T> &iter) const {
    return ptr >= iter.ptr;
}

template<class T>
T & NIterator<T>::operator[](int n) {
    return *(ptr + n);
}

template<class T>
NIterator<T> NIterator<T>::operator+(int add) {
    NIterator<T> temp(ptr + add);
    return temp;
}
template<class T>
NIterator<T> NIterator<T>::operator-(int sub){
    NIterator<T> temp(ptr - sub);
    return temp;
}

template<class T>
NIterator<T> operator+(int add, const NIterator<T> & iter){
    return iter + add;
}

template<class T>
NIterator<T> & NIterator<T>::operator++(){
    ptr++;
    return *this;
}

template<class T>
NIterator<T> NIterator<T>::operator++(int){
    NIterator<T> temp = *this;
    ptr++;
    return temp;
}

template<class T>
NIterator<T> & NIterator<T>::operator--(){
    ptr--;
    return *this;
}

template<class T>
NIterator<T> NIterator<T>::operator--(int){
    NIterator<T> temp = *this;
    ptr--;
    return temp;
}

template<class T>
T & NIterator<T>::operator*(){
    return *ptr;
}



#endif //DUOMENUAPDOROJIMASCPP_NITERATOR_H
