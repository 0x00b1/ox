#ifndef OX_AST_HH
#define OX_AST_HH

#include <string>
#include <optional>
#include <vector>

#include "include/visitor.hh"
#include "type.hh"

namespace AST {
    class Root: public Node {
    public:
        Root() = default;

        Root(std::vector<Node*> *nodes): nodes(*nodes) {};

        std::vector<Node*> nodes;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Argument: public Node {
    public:
        Argument(Node *expression): expression(expression) {};

        Argument(std::string name, Node *expression): name(name), expression(expression) {};

        std::string name;

        Node *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  DECLARATIONS
     */

    class ConstantDeclaration: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class EnumerationDeclaration: public Node {
    public:
        EnumerationDeclaration(std::string name): name(name) {};

        std::string name;

        Type::Enumerated *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class ModuleDeclaration: public Node {
    public:
        ModuleDeclaration(std::string name): name(name) {};

        ModuleDeclaration(std::string name, std::vector<Node*> members): name(name), members(members) {};

        std::string name;

        std::vector<Node*> members;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordDeclaration: public Node {
    public:
        RecordDeclaration(std::string name, std::vector<RecordFieldDeclaration*> *fields): name(name), fields(*fields) {};

        std::string name;

        std::vector<RecordFieldDeclaration*> fields;

        Type::Record *record;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordFieldDeclaration: public Node {
    public:
        RecordFieldDeclaration(std::string name, Type::Type *type): name(name), type(type) {};

        std::string name;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class SubroutineDeclaration: public Node {
    public:
        SubroutineDeclaration(std::string name, TypeSignature *signature): name(name), signature(signature) {};

        std::string name;

        TypeSignature *signature;

        Type::Function *type;

        bool variadic;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TypeAliasDeclaration: public Node {
    public:
        TypeAliasDeclaration(std::string name, Type::Type *type): name(name), type(type) {};

        std::string name;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class UnionDeclaration: public Node {
    public:
        UnionDeclaration(std::string name, std::vector<RecordFieldDeclaration*> *fields): name(name), fields(*fields) {};

        std::string name;

        std::vector<RecordFieldDeclaration*> fields;

        Type::Union *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  EXPRESSIONS
     */

    /*
     *  An array expression, e.g.
     *
     *      [1, 2, 3]
     */
    class ArrayExpression: public Node {
    public:
        ArrayExpression(std::vector<Node*> *items): items(*items) {};

        std::vector<Node*> items;

        Type::Array *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A binary operation expression, e.g.
     *
     *      a + b
     */
    class BinaryOperationExpression: public Node {
    public:
        BinaryOperationExpression(std::string name, Node *a): name(name), a(a) {};

        std::string name;

        Node *a;
        Node *b;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A block expression, e.g.
     *
     *      { true }
     */
    class BlockExpression: public Node {
    public:
        BlockExpression() = default;

        BlockExpression(std::vector<Node*> *statements): statements(*statements) {};

        std::vector<Node*> statements;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A Boolean literal expression, e.g.
     *
     *      true
     */
    class BooleanLiteralExpression: public Node {
    public:
        BooleanLiteralExpression(bool value): value(value) {};

        bool value;

        Type::Boolean *type = new Type::Boolean();

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A break expression, e.g.
     *
     *      break
     */
    class BreakExpression: public Node {
    public:
        BreakExpression() = default;

        BreakExpression(std::string name): name(name) {};

        BreakExpression(LabelDeclaration *label): label(label) {};

        std::optional<LabelDeclaration*> label;

        std::optional<Node*> expression;

        std::string name;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A subroutine call expression, e.g.
     *
     *      f(x)
     */
    class CallExpression: public Node {
    public:
        CallExpression(Node *expression, std::vector<Argument*> *arguments): expression(expression), arguments(arguments) {};

        Node *expression;

        std::vector<Argument*> *arguments;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A closure expression, e.g.
     *
     *      λ (x: 8-bit Integer) → 8-bit Integer { a + 1 }
     */
    class ClosureExpression: public Node {
    public:
        ClosureExpression(BlockExpression *expression): expression(expression) {};

        ClosureExpression(TypeSignature *signature, BlockExpression *expression): signature(signature), expression(expression) {};

        TypeSignature *signature;

        BlockExpression *expression;

        Type::Function *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A conditional expression, e.g.
     *
     *      if true {
     *
     *      } else {
     *
     *      }
     */
    class ConditionalExpression: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A continue expression, e.g.
     *
     *      continue
     */
    class ContinueExpression: public Node {
    public:
        ContinueExpression() = default;

        ContinueExpression(LabelDeclaration *label): label(label) {};

        ContinueExpression(std::string name): name(name) {};

        std::optional<LabelDeclaration*> label;

        std::string name;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A floating-point literal expression, e.g.
     *
     *      1.0
     */
    class FloatingPointLiteralExpression: public Node {
    public:
        FloatingPointLiteralExpression(std::string value): value(value) {};

        std::string value;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A for loop expression, e.g.
     *
     *      for index in 1, 2, … 3 {
     *
     *      }
     */
    class ForLoopExpression: public Node {
    public:
        ForLoopExpression(std::string name, Node *container, BlockExpression *expression): name(name), container(container), expression(expression) {};

        std::string name;

        Node *container;

        BlockExpression *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  An integer literal expression, e.g.
     *
     *      1
     */
    class IntegerLiteralExpression: public Node {
    public:
        IntegerLiteralExpression(std::string value): value(value) {};

        std::string value;

        Type::Integer *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A range expression, e.g.
     *
     *      1, 2, … 3
     */
    class RangeExpression: public Node {
    public:
        RangeExpression(Node* a, Node* b): a(a), b(b) {};

        RangeExpression(Node* a, Node* b, Node* c): a(a), b(b), c(c) {};

        Node* a;
        Node* b;

        std::optional<Node*> c;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A record expression, e.g.
     *
     *      A { a: 1, b: 2 }
     */
    class RecordExpression: public Node {
    public:
        RecordExpression(std::vector<Node*> *expressions): expressions(expressions) {};

        RecordExpression(std::vector<Node*> *expressions, Node* expression): expressions(expressions), expression(expression) {};

        std::vector<Node*> *expressions;

        std::optional<Node*> expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A return expression, e.g.
     *
     *      return
     */
    class ReturnExpression: public Node {
    public:
        ReturnExpression() = default;

        ReturnExpression(Node *expression): expression(expression) {};

        ReturnExpression(LabelDeclaration *label): label(label) {};

        std::optional<LabelDeclaration*> label;

        Node *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A subscript expression, e.g.
     *
     *      a[b]
     */
    class SubscriptExpression: public Node {
    public:
        SubscriptExpression(Node *a, std::vector<Argument*> *b): a(a), b(b) {};

        Node *a;

        std::vector<Argument*> *b;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A switch expression, e.g.
     *
     *      switch a {
     *          case a:
     *          case b:
     *
     *          default:
     *      }
     */
    class SwitchExpression: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A tuple expression, e.g.
     *
     *      ⟨1, 2, 3⟩
     */
    class TupleExpression: public Node {
    public:
        TupleExpression(std::vector<Node*> *items): items(items) {};

        std::vector<Node*> *items;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A unary operation expression, e.g.
     *
     *      −a
     */
    class UnaryOperationExpression: public Node {
    public:
        UnaryOperationExpression(Node *a): a(a) {};

        UnaryOperationExpression(std::string operation, Node *a): operation(operation), a(a) {};

        Node *a;

        std::string operation;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A while loop expression, e.g.
     *
     *      while true {
     *
     *      }
     */
    class WhileLoopExpression: public Node {
    public:
        WhileLoopExpression(Node *a, BlockExpression *b): a(a), b(b) {};

        Node *a;

        BlockExpression *b;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class GenericParameter: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class LabelDeclaration: public Node {
    public:
        LabelDeclaration(std::string name): name(name) {};

        LabelDeclaration(std::string name, Node *statement): name(name), statement(statement) {};

        std::string name;

        Node *statement;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Parameter: public Node {
    public:
        Parameter(std::string name): name(name) {};

        Parameter(std::string name, Node *expression): name(name), expression(expression) {};

        Parameter(std::string name, Type::Type *type): name(name), type(type) {};

        Parameter(std::string name, Type::Type *type, Node *expression): name(name), type(type), expression(expression) {};

        std::string name;

        Type::Type *type;

        Node *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TypeSignature: public Node {
    public:
        TypeSignature() = default;

        TypeSignature(std::vector<Parameter*> *parameters): parameters(parameters) {};

        TypeSignature(std::vector<Parameter*> *parameters, Type::Type *type): parameters(parameters), type(type) {};

        std::vector<Parameter*> *parameters;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };
}

#endif
