#include "../common/cc.h"
template <typename>
class BlobPtr; 
template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T> &lhs, const Blob<T> &rhs);
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type; // 依赖相关, 所以需要typename
    Blob():data(make_shared<vector<T>>()) {};
    Blob(initializer_list<T> il):data(make_shared<vector<T>>(il)) {};
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &value) { data->push_back(value); }
    void push_back(T &&value) { data->push_back(std::move(value)); }
    void pop_back();
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    T &operator[](size_type n);
private:
    shared_ptr<vector<T>> data;
    void check(size_type n, const string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T &Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}
template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T &Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
const T &Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T &Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}