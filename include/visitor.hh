#ifndef OX_VISITOR_HH
#define OX_VISITOR_HH

#include <memory>

class Visitor;

namespace AST {
    class Node {
    public:
        virtual void accept(Visitor &visitor) = 0;
    };
}

namespace AST {
    class Expression;
}

namespace Expression {
    class Integer;
}

class Visitor {
public:
    virtual void accept(std::shared_ptr<Expression::Integer>) = 0;
};

#endif
