#ifndef OX_EXPRESSION_HH
#define OX_EXPRESSION_HH

#include <optional>
#include <memory>
#include <string>
#include <vector>

#include "visitor.hh"

namespace Expression {
    class Array: public AST::Expression, public std::enable_shared_from_this<Array> {
    public:
        Array(std::vector<std::shared_ptr<AST::Expression>> elements): elements(elements) {}

        std::vector<std::shared_ptr<AST::Expression>> elements;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Array> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Assignment: public AST::Expression, public std::enable_shared_from_this<Assignment> {
    public:
        Assignment(std::shared_ptr<AST::Expression> variable, std::shared_ptr<AST::Expression> expression): variable(variable), expression(expression) {}

        std::shared_ptr<AST::Expression> variable;

        std::shared_ptr<AST::Expression> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Assignment> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class BinaryOperation: public AST::Expression, public std::enable_shared_from_this<BinaryOperation> {
    public:
        BinaryOperation(const std::string &operation, std::shared_ptr<AST::Expression> a, std::shared_ptr<AST::Expression> b): operation(operation), a(a), b(b) {}

        std::string operation;

        std::shared_ptr<AST::Expression> a;
        std::shared_ptr<AST::Expression> b;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<BinaryOperation> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Block: public AST::Expression, public std::enable_shared_from_this<Block> {
    public:
        Block(std::shared_ptr<AST::Block> block): block(block) {}

        Block(std::shared_ptr<AST::Block> block, AST::Label label): block(block), label(label) {}

        std::shared_ptr<AST::Block> block;

        std::optional<AST::Label> label;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Block> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class BooleanLiteral: public AST::Expression, public std::enable_shared_from_this<BooleanLiteral> {
    public:
        BooleanLiteral(const std::string &value): value(value) {}

        std::shared_ptr<Type::Boolean> type;

        std::string value;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<BooleanLiteral> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Break: public AST::Expression, public std::enable_shared_from_this<Break> {
    public:
        Break(AST::Label label, std::shared_ptr<AST::Expression> expression): label(label), expression(expression) {}

        Break(AST::Label label): label(label) {}

        Break(std::shared_ptr<AST::Expression> expression): expression(expression) {}

        Break() = default;

        std::optional<AST::Label> label;

        std::optional<std::shared_ptr<AST::Expression>> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Break> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Call: public AST::Expression, public std::enable_shared_from_this<Call> {
    public:
        Call(std::shared_ptr<AST::Expression> subroutine, std::vector<std::shared_ptr<AST::Expression>> arguments): subroutine(subroutine), arguments(arguments) {}

        std::shared_ptr<AST::Expression> subroutine;

        std::vector<std::shared_ptr<AST::Expression>> arguments;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Call> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Closure: public AST::Expression, public std::enable_shared_from_this<Closure> {
    public:
        Closure(std::shared_ptr<AST::FunctionPrototype> prototype, std::shared_ptr<AST::Expression> expression): prototype(prototype), expression(expression) {}

        std::shared_ptr<AST::FunctionPrototype> prototype;

        std::shared_ptr<AST::Expression> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Closure> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Conditional: public AST::Expression, public std::enable_shared_from_this<Conditional> {
    public:
        Conditional(std::shared_ptr<AST::Expression> antecedent, std::shared_ptr<AST::Block> consequent): antecedent(antecedent), consequent(consequent) {}

        Conditional(std::shared_ptr<AST::Expression> antecedent, std::shared_ptr<AST::Block> consequent, std::optional<std::shared_ptr<AST::Expression>> alternate): antecedent(antecedent), consequent(consequent), alternate(alternate) {}

        std::shared_ptr<AST::Expression> antecedent;

        std::shared_ptr<AST::Block> consequent;

        std::optional<std::shared_ptr<AST::Expression>> alternate;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Conditional> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Continue: public AST::Expression, public std::enable_shared_from_this<Continue> {
    public:
        Continue(AST::Label label): label(label) {}

        Continue() = default;

        std::optional<AST::Label> label;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Continue> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class FloatingPointLiteral: public AST::Expression, public std::enable_shared_from_this<FloatingPointLiteral> {
    public:
        FloatingPointLiteral(const std::string &value): value(value) {}

        std::shared_ptr<Type::FloatingPoint> type;

        std::string value;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<FloatingPointLiteral> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class ForLoop: public AST::Expression, public std::enable_shared_from_this<ForLoop> {
    public:
        ForLoop(std::shared_ptr<AST::Pattern> item, std::shared_ptr<AST::Expression> collection, std::shared_ptr<AST::Expression> expression): item(item), collection(collection), expression(expression) {}

        ForLoop(std::shared_ptr<AST::Pattern> item, std::shared_ptr<AST::Expression> collection, std::shared_ptr<AST::Expression> expression, AST::Label label): item(item), collection(collection), expression(expression), label(label) {}

        std::shared_ptr<AST::Pattern> item;

        std::shared_ptr<AST::Expression> collection;

        std::shared_ptr<AST::Expression> expression;

        std::optional<AST::Label> label;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<ForLoop> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Index: public AST::Expression, public std::enable_shared_from_this<Index> {
    public:
        Index(std::shared_ptr<AST::Node> expression, std::shared_ptr<AST::Node> subscript): expression(expression), subscript(subscript) {}

        std::shared_ptr<AST::Node> expression;

        std::shared_ptr<AST::Node> subscript;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Index> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class IntegerLiteral: public AST::Expression, public std::enable_shared_from_this<IntegerLiteral> {
    public:
        IntegerLiteral(const std::string &value): value(value) {}

        std::shared_ptr<Type::Integer> type;

        std::string value;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<IntegerLiteral> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Member: public AST::Expression, public std::enable_shared_from_this<Member> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Member> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Range: public AST::Expression, public std::enable_shared_from_this<Range> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Range> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Record: public AST::Expression, public std::enable_shared_from_this<Record> {
    public:
        Record(AST::Path path, std::vector<AST::Field> fields): path(path), fields(fields) {}

        AST::Path path;

        std::vector<AST::Field> fields;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Record> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Reference: public AST::Expression, public std::enable_shared_from_this<Reference> {
    public:
        Reference(std::shared_ptr<AST::Expression> expression): expression(expression) {}

        std::shared_ptr<AST::Expression> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Reference> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Return: public AST::Expression, public std::enable_shared_from_this<Return> {
    public:
        Return(std::shared_ptr<AST::Expression> expression): expression(expression) {}

        Return() = default;

        std::optional<std::shared_ptr<AST::Expression>> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Return> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Switch: public AST::Expression, public std::enable_shared_from_this<Switch> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Switch> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Tuple: public AST::Expression, public std::enable_shared_from_this<Tuple> {
    public:
        Tuple(const std::vector<std::shared_ptr<AST::Expression>> &elements): elements(elements) {}

        std::vector<std::shared_ptr<AST::Expression>> elements;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Tuple> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class UnaryOperation: public AST::Expression, public std::enable_shared_from_this<UnaryOperation> {
    public:
        UnaryOperation(const std::string &operation, std::shared_ptr<AST::Expression> expression): operation(operation), expression(expression) {}

        std::string operation;

        std::shared_ptr<AST::Expression> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<UnaryOperation> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class WhileLoop: public AST::Expression, public std::enable_shared_from_this<WhileLoop> {
    public:
        WhileLoop(std::shared_ptr<AST::Expression> condition, std::shared_ptr<AST::Block> expression): condition(condition), expression(expression) {}

        WhileLoop(std::shared_ptr<AST::Expression> condition, std::shared_ptr<AST::Block> expression, AST::Label label): condition(condition), expression(expression), label(label) {}

        std::shared_ptr<AST::Expression> condition;

        std::shared_ptr<AST::Block> expression;

        std::optional<AST::Label> label;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<WhileLoop> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
