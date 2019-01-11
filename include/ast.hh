#ifndef OX_AST_HH
#define OX_AST_HH

#include <string>
#include <optional>
#include <vector>
#include <iostream>

#include "visitor.hh"
#include "type.hh"

namespace AST {
    class Root: public Node {
    public:
        Root() = default;

        explicit Root(const std::vector<std::shared_ptr<Node>> &nodes): nodes(nodes) {};

        std::vector<std::shared_ptr<Node>> nodes;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Argument: public Node {
    public:
        explicit Argument(std::shared_ptr<Node> expression): expression(expression) {};

        Argument(const std::string &name, std::shared_ptr<Node> expression): name(name), expression(expression) {};

        std::string name;

        std::shared_ptr<Node> expression;

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
        explicit EnumerationDeclaration(const std::string &name): name(name) {};

        std::string name;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class ModuleDeclaration: public Node {
    public:
        explicit ModuleDeclaration(const std::string &name): name(name) {};

        ModuleDeclaration(const std::string &name, const std::vector<std::shared_ptr<Node>> &members): name(name), members(members) {};

        std::string name;

        std::vector<std::shared_ptr<Node>> members;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordDeclaration: public Node {
    public:
        RecordDeclaration(const std::string &name, std::vector<RecordFieldDeclaration*> *fields): name(name), fields(*fields) {};

        std::string name;

        std::vector<RecordFieldDeclaration*> fields;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordFieldDeclaration: public Node {
    public:
        RecordFieldDeclaration(const std::string &name, Type::Type *type): name(name), type(type) {};

        std::string name;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class SubroutineDeclaration: public Node {
    public:
        SubroutineDeclaration(const std::string &name, TypeSignature *signature): name(name), signature(signature) {};

        std::string name;

        TypeSignature *signature;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TypeAliasDeclaration: public Node {
    public:
        TypeAliasDeclaration(const std::string &name, Type::Type *type): name(name), type(type) {};

        std::string name;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class UnionDeclaration: public Node {
    public:
        UnionDeclaration(const std::string &name, std::vector<RecordFieldDeclaration*> *fields): name(name), fields(*fields) {};

        std::string name;

        std::vector<RecordFieldDeclaration*> fields;

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
        explicit ArrayExpression(std::vector<std::shared_ptr<Node>> *items): items(*items) {};

        std::vector<std::shared_ptr<Node>> items;

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
        BinaryOperationExpression(const std::string &name, Node *a): name(name), a(a) {};

        BinaryOperationExpression(const std::string &name, Node *a, Node *b): name(name), a(a), b(b) {};

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

        explicit BlockExpression(std::vector<std::shared_ptr<Node>> statements): statements(statements) {};

        std::vector<std::shared_ptr<Node>> statements;

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
        explicit BooleanLiteralExpression(bool value): value(value) {};

        bool value;

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

        explicit BreakExpression(const std::string &name): name(name) {};

        explicit BreakExpression(LabelDeclaration *label): label(label) {};

        std::optional<LabelDeclaration*> label;

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
        CallExpression(std::shared_ptr<Node> expression, std::vector<Argument*> *arguments): expression(expression), arguments(arguments) {};

        std::shared_ptr<Node> expression;

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
        explicit ClosureExpression(BlockExpression *expression): expression(expression) {};

        ClosureExpression(TypeSignature *signature, BlockExpression *expression): signature(signature), expression(expression) {};

        TypeSignature *signature;

        BlockExpression *expression;

        Type::Function *type{};

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

        explicit ContinueExpression(LabelDeclaration *label): label(label) {};

        explicit ContinueExpression(const std::string &name): name(name) {};

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
        explicit FloatingPointLiteralExpression(std::string value): value(std::move(value)) {};

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
        ForLoopExpression(const std::string &name) {};

        ForLoopExpression(const std::string &name, std::shared_ptr<Node> container, std::shared_ptr<BlockExpression> expression): name(name), container(container), expression(expression) {};

        std::string name;

        std::shared_ptr<Node> container;

        std::shared_ptr<BlockExpression> expression;

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
        explicit IntegerLiteralExpression(std::string value): value(std::move(value)) {};

        std::string value;

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

        std::optional<std::shared_ptr<Node>> c;

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
        explicit RecordExpression(std::vector<std::shared_ptr<Node>> *expressions): expressions(expressions) {};

        RecordExpression(std::vector<std::shared_ptr<Node>> *expressions, Node* expression): expressions(expressions), expression(expression) {};

        std::vector<std::shared_ptr<Node>> *expressions;

        std::optional<std::shared_ptr<Node>> expression;

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

        explicit ReturnExpression(std::shared_ptr<Node> expression): expression(expression) {};

        explicit ReturnExpression(LabelDeclaration *label): label(label) {};

        std::optional<LabelDeclaration*> label;

        std::shared_ptr<Node> expression;

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
        SubscriptExpression(std::shared_ptr<Node> a, std::vector<Argument*> *b): a(a), b(b) {};

        std::shared_ptr<Node> a;

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
        explicit TupleExpression(std::vector<std::shared_ptr<Node>> *items): items(items) {};

        std::vector<std::shared_ptr<Node>> *items;

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
        explicit UnaryOperationExpression(std::shared_ptr<Node> a): a(a) {};

        UnaryOperationExpression(std::string operation, std::shared_ptr<Node> a): operation(std::move(operation)), a(a) {};

        std::shared_ptr<Node> a;

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
        WhileLoopExpression() = default;

        WhileLoopExpression(std::shared_ptr<Node> a, std::shared_ptr<BlockExpression> b): a(a), b(b) {};

        std::shared_ptr<Node> a;

        std::shared_ptr<BlockExpression> b;

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
        explicit LabelDeclaration(const std::string &name): name(name) {};

        LabelDeclaration(const std::string &name, Node *statement): name(name), statement(statement) {};

        std::string name;

        Node *statement;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Parameter: public Node {
    public:
        explicit Parameter(const std::string &name): name(name) {};

        Parameter(const std::string &name, std::shared_ptr<Node> expression): name(name), expression(expression) {};

        Parameter(const std::string &name, Type::Type *type): name(name), type(type) {};

        Parameter(const std::string &name, Type::Type *type, std::shared_ptr<Node> expression): name(name), type(type), expression(expression) {};

        std::string name;

        Type::Type *type;

        std::shared_ptr<Node> expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TypeSignature: public Node {
    public:
        TypeSignature() = default;

        explicit TypeSignature(std::vector<Parameter*> *parameters): parameters(parameters) {};

        TypeSignature(std::vector<Parameter*> *parameters, Type::Type *type): parameters(parameters), type(type) {};

        std::vector<Parameter*> *parameters;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };
}

#endif
