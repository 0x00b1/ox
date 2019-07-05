#ifndef OX_EXPRESSION_HH
#define OX_EXPRESSION_HH

#include <memory>
#include <string>
#include <utility>

#include "visitor.hh"

namespace Expression {
    class Integer: public AST::Expression, public std::enable_shared_from_this<Integer> {
    public:
        explicit Integer(std::string value) {
            this->value = std::move(value);
        }

        std::string value;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Integer> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
