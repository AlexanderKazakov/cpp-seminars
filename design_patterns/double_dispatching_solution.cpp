#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct B1;

struct A1 {
    virtual void interact(B1& b);
};
struct A2 : A1 {
    virtual void interact(B1& b);
};

struct B1 {
    virtual void interact(A1&) {cout << "A1-B1" << endl;}
    virtual void interact(A2&) {cout << "A2-B1" << endl;}
};
struct B2 : B1 {
    void interact(A1&) override {cout << "A1-B2" << endl;}
    void interact(A2&) override {cout << "A2-B2" << endl;}
};

void A1::interact(B1& b) {b.interact(*this);}
void A2::interact(B1& b) {b.interact(*this);}

int main() {
    vector<shared_ptr<A1>> as = {make_shared<A1>(), make_shared<A2>()};
    vector<shared_ptr<B1>> bs = {make_shared<B1>(), make_shared<B2>()};
    for (auto& a : as) {
        for (auto& b : bs) {
            a->interact(*b);
        }
    }
    return 0;
}
