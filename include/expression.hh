#ifndef OX_EXPRESSION_HH
#define OX_EXPRESSION_HH

#include <memory>
#include <string>
#include <utility>

#include "visitor.hh"

namespace Expression {
    class IntegerLiteral: public AST::Expression, public std::enable_shared_from_this<IntegerLiteral> {
    public:
        explicit IntegerLiteral(std::string value): value(std::move(value)) {}

        std::string value;

        void accept(Visitor &visitor) override {
            std::shared_ptr<IntegerLiteral> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
