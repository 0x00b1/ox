#ifndef OX_VARIANT_HH
#define OX_VARIANT_HH

#include <memory>

#include "visitor.hh"

namespace Variant {
    class Record: public AST::Variant, public std::enable_shared_from_this<Record> {
    public:
        Record(const AST::Identifier &identifier, const std::vector<AST::RecordField> &fields): identifier(identifier), fields(fields) {}

        std::optional<AST::AnonymousConstant> discriminant;

        std::vector<AST::RecordField> fields;

        AST::Identifier identifier;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Record> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Tuple: public AST::Variant, public std::enable_shared_from_this<Tuple> {
    public:
        Tuple(const AST::Identifier &identifier, const std::vector<AST::RecordField> &fields): identifier(identifier), fields(fields) {}

        std::optional<AST::AnonymousConstant> discriminant;

        std::vector<AST::RecordField> fields;

        AST::Identifier identifier;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Tuple> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Unit: public AST::Variant, public std::enable_shared_from_this<Unit> {
    public:
        Unit(const AST::Identifier &identifier): identifier(identifier) {}

        Unit(const AST::Identifier &identifier, std::optional<AST::AnonymousConstant> discriminant): identifier(identifier), discriminant(discriminant) {}

        std::optional<AST::AnonymousConstant> discriminant;

        AST::Identifier identifier;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Unit> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
