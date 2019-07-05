#ifndef OX_GENERATOR_HH
#define OX_GENERATOR_HH

#include <memory>

#include "visitor.hh"

class Generator: public Visitor {
public:
    void accept(std::shared_ptr<Expression::Integer> node) override {
        std::cout << node->value << std::endl;
    }
};

#endif
