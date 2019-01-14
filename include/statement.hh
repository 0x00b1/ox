#ifndef OX_STATEMENT_HH
#define OX_STATEMENT_HH

#include <memory>

#include "visitor.hh"

namespace Statement {
    class Declaration: public AST::Statement, public std::enable_shared_from_this<Declaration> {
    public:
        Declaration(std::shared_ptr<AST::Declaration> declaration): declaration(declaration) {}

        std::shared_ptr<AST::Declaration> declaration;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Declaration> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Expression: public AST::Statement, public std::enable_shared_from_this<Expression> {
    public:
        Expression(std::shared_ptr<AST::Expression> expression): expression(expression) {}

        std::shared_ptr<AST::Expression> expression;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Expression> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
