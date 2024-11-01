#include "../common/cc.h"

template <typename T>
class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
class BlobPtr
{
    friend bool operator== <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
public:
BlobPtr():curr(0){}
BlobPtr(Blob<T> &a, size_t sz=0):wptr(a.data), curr(sz){}
T& operator*() const{
    auto p = check(curr, "dereference past end of BlobPtr");
    return (*p)[curr];
}
BlobPtr &operator++();
BlobPtr &operator--();
BlobPtr operator++(int);
BlobPtr operator--(int);
private:
    shared_ptr<vector<T>> check(size_t, const string &) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr<T> ret = *this;
    ++*this;
    return ret;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr<T> ret = *this;
    --*this;
    return ret;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    // curr有什么用?
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    // curr有什么用?
    --curr;
    return *this;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    if(lhs.wptr.lock() != rhs.wptr.lock()){
        throw runtime_error("cannot compare pointers to different Blobs");
    }
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    if(lhs.wptr.lock() != rhs.wptr.lock()){
        throw runtime_error("cannot compare pointers to different Blobs");
    }
    return lhs.curr < rhs.curr;
}
