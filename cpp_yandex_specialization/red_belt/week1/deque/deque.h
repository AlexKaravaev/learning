#include <vector>
#include <exception>
#include <memory>


template<typename T>
class Deque
{

public:
    Deque()
    {
        front_.resize(0);
        back_.resize(0);
    }

    bool Empty() const
    {
        return front_.empty() && back_.empty();
    }

    size_t Size() const
    {
        return front_.size() + back_.size();
    }

    const T& operator[](size_t index) const
    {
        return index < front_.size() ? front_[front_.size() - index - 1] : back_[index - front_.size()];
    }

    T& operator[](size_t index)
    {
        return const_cast<T&>(static_cast<const Deque&>(*this)[index]);
    }

    const T& At(size_t index) const
    {
        if (index >= (front_.size() + back_.size()) || index<0)
            throw std::out_of_range("Out of range");
        return (*this)[index];
    }

    T& At(size_t index)
    {
        return const_cast<T&>(static_cast<const Deque&>(*this).At(index));
    }
    
    const T& Front() const
    {

        if (front_.size() == 0)
            return back_.front();
        return front_.back();
    }

    T& Front()
    {
        return const_cast<T&>(static_cast<const Deque&>(*this).Front());
    }


    const T& Back() const
    {
        if (back_.size() == 0)
            return front_.front();
        return back_.back();
    }

    T& Back()
    {
        return const_cast<T&>(static_cast<const Deque&>(*this).Back());
    }

    void PushBack(const T& elem)
    {
        back_.push_back(elem);
    }

    void PushFront(const T& elem)
    {
        front_.push_back(elem);
    }

    
private:
    std::vector<T> front_;
    std::vector<T> back_;

};