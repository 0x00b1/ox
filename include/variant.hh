#ifndef OX_VARIANT_HH
#define OX_VARIANT_HH

#include <memory>

#include "visitor.hh"

namespace Variant {
    class Record: public AST::Variant, public std::enable_shared_from_this<Record> {
    public:
        Record(const std::vector<AST::RecordField> &fields): fields(fields) {}

        std::vector<AST::RecordField> fields;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Record> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Tuple: public AST::Variant, public std::enable_shared_from_this<Tuple> {
    public:
        Tuple(const std::vector<AST::RecordField> &fields): fields(fields) {}

        std::vector<AST::RecordField> fields;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Tuple> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Unit: public AST::Variant, public std::enable_shared_from_this<Unit> {
    public:
        Unit() = default;

        virtual void accept(Visitor &visitor) override {
            std::shared_ptr<Unit> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
