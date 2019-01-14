#ifndef OX_AST_HH
#define OX_AST_HH

#include <optional>
#include <memory>
#include <vector>

#include "visitor.hh"

namespace AST {
    class AnonymousConstant: public Node, public std::enable_shared_from_this<AnonymousConstant> {
    public:
        AnonymousConstant(std::shared_ptr<Expression> expression): expression(expression) {}

        std::shared_ptr<Expression> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<AnonymousConstant> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Argument: public Node, public std::enable_shared_from_this<Argument> {
    public:
        Argument(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type): pattern(pattern), type(type) {}

        std::shared_ptr<Pattern> pattern;

        std::shared_ptr<Type> type;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Argument> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Block: public Node, public std::enable_shared_from_this<Block> {
    public:
        std::vector<Statement> statements;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Block> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Declaration: public Node {
    public:
    };

    class Expression: public Node {
    public:
    };

    class Field: public Node, public std::enable_shared_from_this<Field> {
    public:
        Field(std::shared_ptr<Node> expression): expression(expression) {}

        std::shared_ptr<Node> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Field> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class FunctionPrototype: public Node, public std::enable_shared_from_this<FunctionPrototype> {
    public:
        FunctionPrototype(std::vector<Argument> arguments, std::shared_ptr<Type> type, bool variadic): arguments(arguments), type(type), variadic(variadic) {}

        std::vector<Argument> arguments;

        std::shared_ptr<Type> type;

        bool variadic;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<FunctionPrototype> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class GenericParameter: public Node, public std::enable_shared_from_this<GenericParameter> {
    public:
        std::optional<std::shared_ptr<Type>> type;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<GenericParameter> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Identifier: public Node, public std::enable_shared_from_this<Identifier> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Identifier> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Label: public Node, public std::enable_shared_from_this<Label> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Label> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Path: public Node, public std::enable_shared_from_this<Path> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Path> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Pattern: public Node, public std::enable_shared_from_this<Pattern> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Pattern> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class RecordField: public Node, public std::enable_shared_from_this<RecordField> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<RecordField> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Statement: public Node {
    public:
    };

    class Type: public Node {
    public:
    };

    class Variant: public Node {
    public:
        Identifier identifier;

        std::optional<AnonymousConstant> discriminant;
    };
}

#endif
