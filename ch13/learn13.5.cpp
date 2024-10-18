#include "../common/cc.h"

// 自己实现一个vector
class StrVec
{
    string *elements;
    string *first_free;
    string *cap;
    allocator<string> alloc;

    void chk_n_alloc()
    {
        if (first_free == cap)
        {
            reallocate();
        }
    }

    pair<string *, string*>  alloc_n_copy(const string *b, const string *e);
    void free();
    void reallocate();
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    ~StrVec() { free(); }
    void push_back(const string &s);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
};

void StrVec::reallocate()
{
    auto newcap = size() ? size() * 2 : 1;
    auto newdata = alloc.allocate(newcap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcap;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
};
pair<string *, string *> StrVec::alloc_n_copy( const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
    for (auto p = first_free; p != elements;)
    {
        alloc.destroy(--p);
    }
    alloc.deallocate(elements, cap - elements);
}

int main()
{
    StrVec v;
    v.push_back("hello");
    v.push_back("world");
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    return 0;
}