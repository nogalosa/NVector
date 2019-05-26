
#ifndef DUOMENUAPDOROJIMASCPP_NITERATOR_H
#define DUOMENUAPDOROJIMASCPP_NITERATOR_H

#include <iterator>

template<class T>
class NIterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
    T * pointer;
public:
    NIterator(): pointer(nullptr){};
    NIterator(T * item) : pointer(item){}

    NIterator<T> & operator=(const NIterator<T> & iter) = default;
    ~NIterator() = default;

    NIterator operator+(int add);
    NIterator operator-(int sub);
    NIterator operator-(const NIterator &it) { return pointer - it.pointer; }

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
    return pointer == iter.pointer;
}

template<class T>
bool NIterator<T>::operator!=(const NIterator<T> & iter) const {
    return pointer != iter.pointer;
}

template<class T>
bool NIterator<T>::operator<(const NIterator<T> & iter) const{
    return pointer < iter.pointer;
}

template<class T>
bool NIterator<T>::operator<=(const NIterator<T> & iter) const{
    return pointer <= iter.pointer;
}

template<class T>
bool NIterator<T>::operator>(const NIterator<T> &iter) const {
    return pointer > iter.pointer;
}

template<class T>
bool NIterator<T>::operator>=(const NIterator<T> &iter) const {
    return pointer >= iter.pointer;
}

template<class T>
T & NIterator<T>::operator[](int n) {
    return *(pointer + n);
}

template<class T>
NIterator<T> NIterator<T>::operator+(int add) {
    NIterator<T> temp(pointer + add);
    return temp;
}
template<class T>
NIterator<T> NIterator<T>::operator-(int sub){
    NIterator<T> temp(pointer - sub);
    return temp;
}

template<class T>
NIterator<T> operator+(int add, const NIterator<T> & iter){
    return iter + add;
}

template<class T>
NIterator<T> & NIterator<T>::operator++(){
    pointer++;
    return *this;
}

template<class T>
NIterator<T> NIterator<T>::operator++(int){
    NIterator<T> temp = *this;
    pointer++;
    return temp;
}

template<class T>
NIterator<T> & NIterator<T>::operator--(){
    pointer--;
    return *this;
}

template<class T>
NIterator<T> NIterator<T>::operator--(int){
    NIterator<T> temp = *this;
    pointer--;
    return temp;
}

template<class T>
T & NIterator<T>::operator*(){
    return *pointer;
}



#endif //DUOMENUAPDOROJIMASCPP_NITERATOR_H
