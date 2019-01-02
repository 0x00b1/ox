#ifndef OX_OX_HH
#define OX_OX_HH

#include <iostream>
#include <vector>

class Visitor;

class Node {
public:
    virtual void accept(Visitor &visitor) = 0;
};

class Boolean;
class FloatingPoint;
class Integer;
class Expression;

class Visitor {
public:
    virtual void visit(Boolean &file) = 0;
    virtual void visit(FloatingPoint &file) = 0;
    virtual void visit(Integer &file) = 0;
    virtual void visit(Expression &file) = 0;
};

class Boolean: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class FloatingPoint: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Integer: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Expression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Generator: public Visitor {
public:
    void visit(Boolean &) override {
        std::cout << "generating Boolean" << std::endl;
    }

    void visit(FloatingPoint &) override {
        std::cout << "generating Integer" << std::endl;
    }

    void visit(Integer &) override {
        std::cout << "generating Integer" << std::endl;
    }

    void visit(Expression &) override {
        std::cout << "generating Expression" << std::endl;
    }
};

#endif
