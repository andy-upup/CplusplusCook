#ifndef FORWARD_MODULE_H__
#define FORWARD_MODULE_H__
#include <iostream>
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
    ~MsgHolder() {
        while (segs_.size() > 0) {
            Segment *seg = segs_.back();
            segs_.pop_back();
            delete seg;
        }
    }

    template<typename T>
    void Add(T&& msg) {
        segs_.push_back(new StringSegment(std::forward<T>(msg)));
    }

    void Add(int value) {
        segs_.push_back(new IntSegment(value));
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
    std::vector<Segment*> segs_;
};

inline std::ostream& operator<<(std::ostream& os, const MsgHolder& holder) {
    return holder.Output(os);
}

} // namespace cpp11
#endif