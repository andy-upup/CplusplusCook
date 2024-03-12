#ifndef FORWARD_MODULE_H__
#define FORWARD_MODULE_H__
#include <iostream>
#include <memory>
#include <vector>

namespace cpp11 {

class Segment {
 public:
    Segment() = default;
    virtual ~Segment() = default;
    virtual std::ostream& Output(std::ostream& os) const = 0;
};

class StringSegment : public Segment {
 public:
    StringSegment(std::string& str) : msg_(str) {}
    StringSegment(std::string&& str) : msg_(std::move(str)) {}
    virtual ~StringSegment() = default;

    std::ostream& Output(std::ostream& os) const {
        os << msg_;
        return os;
    }
 private:
    std::string msg_;
};

inline std::ostream& operator<<(std::ostream& os, const Segment& seg) {
    return seg.Output(os);
}

class IntSegment : public Segment {
 public:
    IntSegment(int t) : value_(t) {}
    virtual ~IntSegment() = default;

    std::ostream& Output(std::ostream& os) const {
        os << value_;
        return os;
    }
 private:
    int value_;
};

class MsgHolder {
 public:
    MsgHolder() = default;
    ~MsgHolder() = default;

    template<typename T>
    void Add(T&& msg) {
        segs_.push_back(std::make_shared<StringSegment>(std::forward<T>(msg)));
    }

    void Add(int value) {
        segs_.push_back(std::make_shared<IntSegment>(value));
    }

    template<typename T, typename... Args>
    void Add(T&& t, Args&&... rest) {
        Add(std::forward<T>(t));
        Add(std::forward<Args>(rest)...);
    }

    std::ostream& Output(std::ostream& os) const {
        for (auto seg: segs_) {
            // seg->Output(os);
            os << (*seg);
        }
        return os;
    }
 private:
    std::vector<std::shared_ptr<Segment>> segs_;
};

inline std::ostream& operator<<(std::ostream& os, const MsgHolder& holder) {
    return holder.Output(os);
}

template<typename T>
static void Print(T& t) {
    std::cout << "Lvalue ref." << std::endl;
}

template<typename T>
static void Print(T&& t) {
    std::cout << "Rvalue ref." << std::endl;
}

template<typename T>
void TestForward(T&& v) {
    // v is lvalue, always call Print(T& t)
    Print(v);
    // Determined by input parameters
    Print(std::forward<T>(v));
    // v is rvalue, always call Print(T&& t)
    Print(std::move(v));
}

} // namespace cpp11
#endif