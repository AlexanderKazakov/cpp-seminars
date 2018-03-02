#include <iostream>
#include <cassert>

using namespace std;


struct Holder {
    virtual ~Holder() = default;
    virtual Holder* clone() const = 0;
};

struct A : Holder {
    virtual ~A() = default;
    virtual Holder* clone() const override {
        return new A();
    }
};

struct B : Holder {
    virtual ~B() = default;
    virtual Holder* clone() const override {
        return new B();
    }
};


///////////////////////////////////////////////////////


struct Any {
    Any() = default;
    ~Any() { delete holder; }
    
    template <typename T>
    Any(const T& t) : holder(new HolderImpl<T>(t)) {}
    
    Any(const Any& orig) : holder(orig.holder->clone()) {}
    
    Any& operator=(const Any& orig) {
        delete holder;
        holder = orig.holder->clone();
    }
    
    template<typename T>
    T& as() {
        auto hi = dynamic_cast<HolderImpl<T>*>(holder);
        assert(hi != nullptr);
        return hi->t;
    }

private:
    struct Holder {
        virtual ~Holder() = default;
        virtual Holder* clone() const = 0;
    };
    
    template<typename T>
    struct HolderImpl : Holder {
        HolderImpl(const T& data) : t(data) {}
        virtual ~HolderImpl() = default;
        virtual Holder* clone() const override {
            return new HolderImpl(t);
        }
        T t;
    };
    
    Holder* holder = nullptr;
};

int main() {
    Any any(777);
    cout << any.as<int>() << endl << flush;
    cout << any.as<double>() << endl << flush;
    return 0;
}
