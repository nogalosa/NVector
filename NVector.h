
#ifndef NVECTOR_NVECTOR_H
#define NVECTOR_NVECTOR_H

#include "NIterator.h"
#include <algorithm>
#include <exception>

template <class T>
class NVector {
private:
    T* element;
    int _size, _capacity;
public:
    using size_type = std::size_t;
    using value_type = T;

    NVector() : element(new T[0]), _size(), _capacity() {}
    explicit NVector(int size);
    NVector(int size, int val);
    NVector(const std::initializer_list<T> & v);
    NVector(const NVector<T> & v);

    NVector& operator=(const NVector<T> &v); //copy
    NVector& operator=(NVector&& v); // move

    ~NVector() {
        delete[] element;
    }

    const T& operator[](int i) const { return element[i]; }
    T& operator[](int i) { return element[i]; }
    T& at(int pos);
    T& front();
    T& back();

    int size() const { return _size; }
    int capacity() const { return _capacity;}

    bool empty() const;

    void swap(T& x, T& y);
    void swap(NVector &v) noexcept;
    void resize(int new_size);
    void reserve(int new_size);
    void pop_back();
    void push_back(const T &val);
    void shrink_to_fit();

    bool operator==(const NVector<T> & v) const;
    bool operator!=(const NVector<T> & v) const;
    bool operator<(const NVector<T> & v) const;
    bool operator<=(const NVector<T> & v) const;
    bool operator>(const NVector<T> & v) const;
    bool operator>=(const NVector<T> & v) const;

    friend class NIterator<T>;
    typedef class NIterator<T> iterator;
    NIterator<T> end();
    NIterator<T> begin();
    NIterator<T> end() const;
    NIterator<T> begin() const;
    NIterator<T> erase(NIterator<T> pos);
    NIterator<T> erase(NIterator<T> first, NIterator<T> last);
    NIterator<T> insert(NIterator<T> pos, const T & value);

    template< class NVector >
    std::back_insert_iterator<NVector> back_inserter( NVector& c )
    {
        return std::back_insert_iterator<NVector>(c);
    }
};

template<class T>
NVector<T>::NVector(int size) : _size(size), _capacity(size) {
    element = new T[size];
}

template<class T>
NVector<T>::NVector(int size, int val) : _size(size), _capacity(size){
    element = new T[_size];

    for (int i = 0; i < _size; i++)
        element[i] = val;
}

template<class T>
NVector<T>::NVector(const std::initializer_list<T> &v) : _size(v.size()), _capacity(v.size()) {
    element = new T[v.size()];

    for (int i = 0; i < v.size(); i++)
        element[i] = *(v.begin() + i);
}

template<class T>
NVector<T>::NVector(const NVector<T> &v) : _size(v.size()), _capacity(v.capacity()) {
    element = new T[_capacity];

    for (int i = 0; i < _size; i++)
        element[i] = v.element[i];
}

template <class T>
T& NVector<T>::at(int pos) {
    if(pos >= _size)
        throw std::out_of_range("Out of range");
    return element[pos];
}

template <class T>
T& NVector<T>::front() {
    return element[0];
}

template <class T>
T& NVector<T>::back() {
    return element[_size - 1];
}

template <class T>
NVector<T> &NVector<T>::operator=(const NVector<T> &v) {
    std::cout << "copy operator=" << std::endl;
    if (&v == this)
        return *this;
    T* p = new T[v._size];
    for (int i = 0; i != v._size; ++i)  // nukopijuojame v elementus
        p[i] = v.element[i];
    delete[] element;  // atlaisviname seną atmintį!
    element = p;       // elem point'ina į naują atmintį
    _size = v._size;      // atnaujiname size
    return *this;
}

template <class T>
NVector<T>& NVector<T>::operator=(NVector&& v) {
    std::cout << "move operator=" << std::endl;
    if (&v == this)
        return *this;
    delete[] element;     // atlaisviname seną atmintį!
    element = v.element;     // elem point'ina į v.elems atmintį
    _size = v._size;         // atnaujiname size
    v.element = nullptr;  // v neturi jokių elementų
    v._size = 0;
    return *this;
}

template <class T>
NVector<T> operator+(const NVector<T>& a, const NVector<T>& b) {
    if (a.size() != b.size())
        throw std::runtime_error("Vektorių dydžio neatitikimas!");
    auto size = a.size();
    NVector<T> c(a.size());
    for (auto i = 0; i != a.size(); ++i) c[i] = a[i] + b[i];
    return c;
}

template<class T>
void NVector<T>::swap(NVector &v) noexcept {
    std::swap(element, v.element);
    std::swap(_size, v._size);
    std::swap(_capacity,v._capacity);
}

template <class T>
bool NVector<T>::empty() const {
    return (_size == 0);
}

template <class T>
void NVector<T>::swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

template<class T>
NIterator<T> NVector<T>::end() const{
    NIterator<T> temp(element + _size);
    return temp;
}

template<class T>
NIterator<T> NVector<T>::begin() const{
    NIterator<T> temp(element);
    return temp;
}
template<class T>

NIterator<T> NVector<T>::end() {
    NIterator<T> temp(element + _size);
    return temp;
}

template<class T>
NIterator<T> NVector<T>::begin() {
    NIterator<T> temp(element);
    return temp;
}


template<class T>
NIterator<T> NVector<T>::erase(NIterator<T> pos) {
    int i = 0;
    auto it = (*this).begin();
    for (it; it != pos; it++, i++);
        for (auto it = pos + 1; it != (*this).end(); it++, i++)
            element[i] = element[i + 1];
    _size--;
    return pos;
}
template<class T>
NIterator<T> NVector<T>::erase(NIterator<T> first, NIterator<T> last){
    int i = 0;
    int temp = 0;
    auto it = (*this).begin();
    for (it; it != first; it++, i++);
        for (it = first; it != last; it++, temp++, i++);
            for (auto it = last; it != (*this).end(); it++, i++)
                element[i - temp] = element[i];
    _size -= temp;
    return last;
}

template<class T>
NIterator<T> NVector<T>::insert(NIterator<T> pos, const T & value){
    int i = 0;

    if (_capacity > _size){
        for(NIterator<T> it(element + _size); it != pos; it--, i++)
            element[_size - i] = element[_size - i - 1];
        *pos = value;
        _size++;
    } else{
        T * temp = new T[_size + 1];
        for (NIterator<T> it(element); it != pos; it++, i++)
            temp[i] = element[i];
        temp[i] = value;
        i++;
        for (NIterator<T> it(element + i + 1); it != element + _size + 2; it++, i++)
            temp[i] = element[i-1];
        delete [] element;
        element = temp;
        _size++;
        _capacity = _size;
    }
    return pos;
}

template<class T>
void NVector<T>::resize(int new_size) {
    if (new_size < 0)
        throw std::exception();
    else if (new_size < _size)
        _size = new_size;
    else if (new_size > _capacity) {
        T *tempElem = new T[new_size];
        for (int i = 0; i < _size; i++)
            tempElem[i] = element[i];
        delete[] element;
        element = tempElem;
        _capacity = new_size;
    }
}

template<class T>
void NVector<T>::pop_back() {
    if (_size > 0)
        _size--;
}

template<class T>
void NVector<T>::reserve(int kiek){
    resize(kiek);
}

template<class T>
void NVector<T>::push_back(const T &val) {
    if(_size == _capacity) {
        resize(std::max(2 * _size, 1));
    }
    element[_size] = val;
    _size++;
}

template<class T>
void NVector<T>::shrink_to_fit() {
    _capacity = _size;
}

template<class T>
bool NVector<T>::operator==(const NVector<T> &v) const {
    if (_size == v._size && _capacity == v._capacity) {
        for (int i = 0; i < _size; i++)
            if (element[i] != v.element[i])
                return false;
        return true;
    }
    return false;

}

template<class T>
bool NVector<T>::operator!=(const NVector<T> &v) const {
    return !operator==(v);
}

template<class T>
bool NVector<T>::operator<(const NVector<T> &v) const {
    if(_size < v._size && _capacity < v._capacity){
        for (int i = 0; i < _size; i++)
            if (element[i] < v.element[i])
                return false;
        return true;
    }
    return false;

}

template<class T>
bool NVector<T>::operator<=(const NVector<T> &v) const {
    if(_size <= v._size && _capacity <= v._capacity){
        for (int i = 0; i < _size; i++)
            if (element[i] <= v.element[i])
                return false;
        return true;
    }
    return false;

}

template<class T>
bool NVector<T>::operator>(const NVector<T> &v) const {
    if(_size > v._size && _capacity > v._capacity){
        for (int i = 0; i < _size; i++)
            if (element[i] > v.element[i])
                return false;
        return true;
    }
    return false;

}

template<class T>
bool NVector<T>::operator>=(const NVector<T> &v) const {
    if(_size >= v._size && _capacity >= v._capacity){
        for (int i = 0; i < _size; i++)
            if (element[i] >= v.element[i])
                return false;
        return true;
    }
    return false;

}


#endif //NVECTOR_NVECTOR_H
