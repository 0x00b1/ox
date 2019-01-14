#ifndef OX_TYPE_HH
#define OX_TYPE_HH

#include <memory>

#include "visitor.hh"

namespace Type {
    enum Primitive {
         fp16,  //           16-bit Floating-point
         fp32,  //           32-bit Floating-point
         fp64,  //           64-bit Floating-point
        fp128,  //          128-bit Floating-point
           i2,  //                  Boolean
           i8,  //            8-bit Integer
          i16,  //           16-bit Integer
          i32,  //           32-bit Integer
          i64,  //           64-bit Integer
         i128,  //          128-bit Integer
           u8,  // unsigned   8-bit Integer
          u16,  // unsigned  16-bit Integer
          u32,  // unsigned  32-bit Integer
          u64,  // unsigned  64-bit Integer
         u128   // unsigned 128-bit Integer
    };

    class Array: public AST::Type, public std::enable_shared_from_this<Array> {
    public:
        Array(const AST::AnonymousConstant &shape, std::shared_ptr<AST::Type> type): shape(shape), type(type) {}

        AST::AnonymousConstant shape;

        std::shared_ptr<AST::Type> type;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Array> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Boolean: public AST::Type, public std::enable_shared_from_this<Boolean> {
    public:
        Primitive primitive = Primitive::i2;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Boolean> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Bottom: public AST::Type, public std::enable_shared_from_this<Bottom> {
    public:
        void accept(Visitor &visitor) override {
            std::shared_ptr<Bottom> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class FloatingPoint: public AST::Type, public std::enable_shared_from_this<FloatingPoint> {
    public:
        Primitive primitive;

        void accept(Visitor &visitor) override {
            std::shared_ptr<FloatingPoint> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Function: public AST::Type, public std::enable_shared_from_this<Function> {
    public:
        Function(std::shared_ptr<AST::FunctionPrototype> function_prototype): function_prototype(function_prototype) {}

        std::shared_ptr<AST::FunctionPrototype> function_prototype;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Function> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Integer: public AST::Type, public std::enable_shared_from_this<Integer> {
    public:
        Primitive primitive;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Integer> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Path: public AST::Type, public std::enable_shared_from_this<Path> {
    public:
        AST::Path path;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Path> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Product: public AST::Type, public std::enable_shared_from_this<Product> {
    public:
        Product(const std::vector<std::shared_ptr<AST::Type>> &types): types(types) {}

        std::vector<std::shared_ptr<AST::Type>> types;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Product> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Reference: public AST::Type, public std::enable_shared_from_this<Reference> {
    public:
        Reference(std::shared_ptr<AST::Type> type): type(type) {}

        std::shared_ptr<AST::Type> type;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Reference> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Subroutine: public AST::Type, public std::enable_shared_from_this<Subroutine> {
    public:
        Subroutine(const std::vector<AST::GenericParameter> &generic_parameters, std::shared_ptr<AST::FunctionPrototype> function_prototype): generic_parameters(generic_parameters), function_prototype(function_prototype) {}

        std::vector<AST::GenericParameter> generic_parameters;

        std::shared_ptr<AST::FunctionPrototype> function_prototype;

        void accept(Visitor &visitor) override {
            std::shared_ptr<Subroutine> p{shared_from_this()};

            visitor.accept(p);
        }
    };

    class Top: public AST::Type, public std::enable_shared_from_this<Top> {
    public:
        void accept(Visitor &visitor) override {
            std::shared_ptr<Top> p{shared_from_this()};

            visitor.accept(p);
        }
    };
}

#endif
