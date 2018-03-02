#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct A1;
struct A2;

struct Visitor {
    virtual void visit(A1&) = 0;
    virtual void visit(A2&) = 0;
};

struct A1 {
    virtual void acceptVisit(Visitor& visitor) {visitor.visit(*this);}
};
struct A2 : A1 {
    void acceptVisit(Visitor& visitor) override {visitor.visit(*this);}
};


int main() {
    vector<shared_ptr<A1>> as = {make_shared<A1>(), make_shared<A2>()};
    
    // Добавляем новую функциональность семейству
    // классов, не залезая в их код:
    struct NewFunctionality : Visitor {
        void visit(A1& a1) override {cout << "Custom actions on A1" << endl;}
        void visit(A2& a2) override {cout << "Custom actions on A2" << endl;}
    };
    NewFunctionality my_functor;
    for (auto& a : as) {a->acceptVisit(my_functor);}
    
    return 0;
}
