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
        std::shared_ptr<AST::Type> type;

        std::shared_ptr<AST::Expression> expression;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Constant> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Enumeration: public AST::Declaration, public std::enable_shared_from_this<Enumeration> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Enumeration> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Module: public AST::Declaration, public std::enable_shared_from_this<Module> {
    public:
        std::vector<std::shared_ptr<AST::Declaration>> declarations;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Module> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Record: public AST::Declaration, public std::enable_shared_from_this<Record> {
    public:
        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Record> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Subroutine: public AST::Declaration, public std::enable_shared_from_this<Subroutine> {
    public:
        std::shared_ptr<AST::Block> block;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Subroutine> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class TaggedUnion: public AST::Declaration, public std::enable_shared_from_this<TaggedUnion> {
    public:
        std::vector<std::shared_ptr<AST::Variant>> variants;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<TaggedUnion> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class TypeAlias: public AST::Declaration, public std::enable_shared_from_this<TypeAlias> {
    public:
        std::shared_ptr<AST::Type> type;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<TypeAlias> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
