#include "../common/cc.h"

class StrVec
{
    string *elements;
    string *first_free;
    string *cap;
    allocator<string> alloc;

    void chk_n_alloc();
    void reallocate();
    void free();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    pair<string *, string *> alloc_n_copy(const string *b, const string *e);
    void alloc_n_move(size_t sz);
    void range_initialize(const string *bg, const string *ed);

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string> il);
    ~StrVec() { free(); }
    StrVec(const StrVec &s);
    StrVec &operator=(const StrVec &s);
    void push_back(const string &s);
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const string &s);
};

void StrVec::range_initialize(const string *bg, const string *ed)
{
    auto newAddr = alloc_n_copy(bg, ed);

    // 指针修改
    elements = newAddr.first;
    first_free = newAddr.second;
    cap = newAddr.first + (ed - bg);
}

StrVec::StrVec(const StrVec &s)
{
    range_initialize(s.begin(), s.end());
}

StrVec::StrVec(initializer_list<string> il)
{
    range_initialize(il.begin(), il.end());
}

void StrVec::resize(size_t n, const string &s)
{
    if (n < size())
    {
        while (first_free != elements + n)
        {
            alloc.destroy(--first_free);
        }
    }
    else if (n > size())
    {
        if (n > capacity())
            reserve(n * 2);
        while (first_free != elements + n)
        {
            alloc.construct(first_free++, s);
        }
    }
}

void StrVec::resize(size_t n)
{
    resize(n, "");
}
void StrVec::reserve(size_t n)
{
    if (n <= capacity())
        return;

    alloc_n_move(n);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    // 元素拷贝
    auto new_elements = alloc.allocate(e - b);
    return {new_elements, uninitialized_copy(b, e, new_elements)};
}

StrVec &StrVec::operator=(const StrVec &s)
{
    if (this == &s)
        return *this;
    // 缓存s
    // 元素拷贝
    auto newAddr = alloc_n_copy(s.begin(), s.end());

    free();

    // 指针修改
    elements = newAddr.first;
    first_free = newAddr.second;
    cap = newAddr.first + s.size();
    return *this;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::chk_n_alloc()
{
    if (first_free == cap)
    {
        reallocate();
    }
};

void StrVec::free()
{
    // 释放空间
    if (elements)
    {
        for (auto p = elements; p != first_free; ++p)
        {
            alloc.destroy(p);
        }

        // 
        for_each(elements, first_free, [this](string &s) { alloc.destroy(&s); });

        alloc.deallocate(elements, capacity());
    }
}

// 1或者2倍扩容
void StrVec::reallocate()
{
    size_t sz = size() ? 2 * size() : 1;
    alloc_n_move(sz);
}

void StrVec::alloc_n_move(size_t sz)
{
    auto new_elements = alloc.allocate(sz);
    auto dest = new_elements;

    // 复制元素
    for (auto p = elements; p != first_free; ++p)
    {
        alloc.construct(dest++, std::move(*p));
    }
    free();

    // 修改指针
    elements = new_elements;
    first_free = dest;
    cap = elements + sz;
}

int main()
{
    StrVec sv;
    sv.push_back("hello");
    sv.push_back("world");
    for (auto it = sv.begin(); it != sv.end(); ++it)
        cout << *it << endl;
    return 0;
}