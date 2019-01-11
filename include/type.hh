#ifndef OX_TYPE_HH
#define OX_TYPE_HH

#include <optional>
#include <vector>

namespace Type {
    /*
     *  5.0.    TYPES
     */

    class Type {};

    /*
     *  5.1.    PRIMITIVE TYPES
     */

    /*
     *  5.1.1.  BOOLEAN
     */    

    class Boolean: public Type {};  // Boolean

    /*
     *  5.1.2.  NUMBER
     */

    class Number: public Type {
    public:
        std::uint8_t bits;

        std::int64_t minimum;
        std::int64_t maximum;
    };

    class Integer: public Number {
    public:
        bool sign;
    };

    class   U8: public Integer {};     // unsigned   8-bit Integer
    class  U16: public Integer {};     // unsigned  16-bit Integer
    class  U32: public Integer {};     // unsigned  32-bit Integer
    class  U64: public Integer {};     // unsigned  64-bit Integer
    class U128: public Integer {};     // unsigned 128-bit Integer

    class   I8: public Integer {};     //   8-bit Integer
    class  I16: public Integer {};     //  16-bit Integer
    class  I32: public Integer {};     //  32-bit Integer
    class  I64: public Integer {};     //  64-bit Integer
    class I128: public Integer {};     // 128-bit Integer

    class  F32: public Type {};     // 32-bit Floating-point
    class  F64: public Type {};     // 64-bit Floating-point

    /*
     *  5.1.3.  UNIT TYPE
     */

    class Unit: public Type {};     // ()

    /*
     *  5.1.2.  ARRAY TYPE
     */

    class Array: public Type {
    public:
        Array(std::vector<std::string> *shape, Type *type): shape(shape), type(type) {};

        Type *type;

        std::vector<std::string> *shape;
    };

    /*
     *  5.2.    PRODUCT TYPE
     */

    class Product: public Type {};

    /*
     *  5.2.1.  TUPLE TYPE
     */

    class Tuple: public Product {
    public:
        Tuple(std::vector<Type*> *types): types(types) {}

        std::vector<Type*> *types;
    };

    /*
     *  5.2.2.  RECORD TYPE
     */

    class Record: public Product {
    public:
        Record(std::string name): name(name) {};

        Record(std::string name, std::vector<std::pair<std::string, Type*>> *types): name(name), types(types) {};

        std::string name;

        std::vector<std::pair<std::string, Type*>> *types;
    };

    /*
     *  5.3.    SUM TYPE
     */

    class Sum: public Type {};

    /*
     *  5.3.1.  TAGGED UNION
     */

    class Union: public Sum {
    public:
        Union(std::string name): name(name) {};

        Union(std::string name, std::vector<std::pair<std::string, Type*>> *types): name(name), types(types) {};

        std::string name;

        std::vector<std::pair<std::string, Type*>> *types;
    };

    /*
     *  5.3.2.  ENUMERATED TYPE
     */

    class Enumerated: public Sum {
    public:
        Enumerated(std::string name, std::vector<std::pair<std::string, Type*>> *types): name(name), types(types) {};

        std::string name;

        std::vector<std::pair<std::string, Type*>> *types;
    };

    /*
     *  5.4.    FUNCTION TYPE
     */

    class Function: public Type {
    public:
        Function(std::vector<Type*> *a, Type *b): a(a), b(b) {};

        Function(std::string name, std::vector<Type*> *a, Type *b): name(name), a(a), b(b) {};

        std::optional<std::string> name;

        std::vector<Type*> *a;

        Type *b;
    };

    /*
     *  5.5.    REFERENCE TYPE
     */

    class Reference: public Type {
    public:
        Reference(Type *referenced): referenced(referenced) {};

        Type *referenced;
    };
}

#endif
