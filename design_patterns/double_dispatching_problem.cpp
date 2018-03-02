#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct A1 {};
struct A2 : A1 {};

struct B1 {
    virtual void interact(A1&) {cout << "A1-B1" << endl;}
    virtual void interact(A2&) {cout << "A2-B1" << endl;}
};
struct B2 : B1 {
    void interact(A1&) override {cout << "A1-B2" << endl;}
    void interact(A2&) override {cout << "A2-B2" << endl;}
};

int main() {
    vector<shared_ptr<A1>> as = {make_shared<A1>(), make_shared<A2>()};
    vector<shared_ptr<B1>> bs = {make_shared<B1>(), make_shared<B2>()};
    for (auto& a : as) {
        for (auto& b : bs) {
            b->interact(*a);
        }
    }
    return 0;
}
