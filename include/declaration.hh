#ifndef OX_DECLARATION_HH
#define OX_DECLARATION_HH

#include <optional>
#include <memory>
#include <string>
#include <vector>

#include "visitor.hh"

namespace Declaration {
    class Constant: public AST::Declaration, public std::enable_shared_from_this<Constant> {
    public:
        Constant(const AST::Identifier &identifier, std::shared_ptr<AST::Type> type, std::shared_ptr<AST::Expression> expression): identifier(identifier), type(type), expression(expression) {}

        std::shared_ptr<AST::Expression> expression;

        AST::Identifier identifier;

        std::shared_ptr<AST::Type> type;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Constant> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Enumeration: public AST::Declaration, public std::enable_shared_from_this<Enumeration> {
    public:
        Enumeration(const AST::Identifier &identifier): identifier(identifier) {}

        AST::Identifier identifier;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Enumeration> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Module: public AST::Declaration, public std::enable_shared_from_this<Module> {
    public:
        Module(const AST::Identifier &identifier, const std::vector<std::shared_ptr<AST::Declaration>> &declarations): identifier(identifier), declarations(declarations) {}

        std::vector<std::shared_ptr<AST::Declaration>> declarations;

        AST::Identifier identifier;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Module> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Record: public AST::Declaration, public std::enable_shared_from_this<Record> {
    public:
        Record(const AST::Identifier &identifier, std::shared_ptr<AST::Variant> variant): identifier(identifier), variant(variant) {}

        AST::Identifier identifier;

        std::shared_ptr<AST::Variant> variant;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Record> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Subroutine: public AST::Declaration, public std::enable_shared_from_this<Subroutine> {
    public:
        Subroutine(const AST::Identifier &identifier, std::shared_ptr<AST::FunctionPrototype> function_prototype, std::shared_ptr<AST::Block> block): identifier(identifier), function_prototype(function_prototype), block(block) {}

        std::shared_ptr<AST::Block> block;

        std::shared_ptr<AST::FunctionPrototype> function_prototype;

        AST::Identifier identifier;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Subroutine> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class TaggedUnion: public AST::Declaration, public std::enable_shared_from_this<TaggedUnion> {
    public:
        TaggedUnion(const AST::Identifier &identifier, const std::vector<std::shared_ptr<AST::Variant>> &variants): identifier(identifier), variants(variants) {}

        AST::Identifier identifier;

        std::vector<std::shared_ptr<AST::Variant>> variants;

        void accept(Visitor &visitor) override {
            std::shared_ptr<TaggedUnion> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class TypeAlias: public AST::Declaration, public std::enable_shared_from_this<TypeAlias> {
    public:
        TypeAlias(const AST::Identifier &identifier, std::shared_ptr<AST::Type> type): identifier(identifier), type(type) {}

        AST::Identifier identifier;

        std::shared_ptr<AST::Type> type;

        void accept(Visitor &visitor) override {
            std::shared_ptr<TypeAlias> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
