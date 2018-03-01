#include <stdio.h>
#include <iostream>
#include "SmartPtr.h"

class TestClassBase {
public:
    TestClassBase() {}
    virtual ~TestClassBase() {}
    virtual void printName() {printf("TestClassBase\n");}
};

class TestClass: public TestClassBase {
public:
    TestClass() {}
    ~TestClass() {}
    virtual void printName() {printf("TestClass\n");}
};

int main()
{
    SmartPtr<TestClass> p1(new TestClass());
    SmartPtr<TestClassBase> p2 = p1;
    p1->printName();
    p2->printName();
}
