#ifndef OX_AST_HH
#define OX_AST_HH

#include <optional>
#include <string>
#include <vector>

#include "visitor.hh"
#include "type.hh"

namespace AST {
    class Root: public Node {
    public:
        Root() = default;

        explicit Root(
            const std::vector<std::shared_ptr<Statement>> &nodes
        ): nodes(nodes) {};

        std::vector<std::shared_ptr<Statement>> nodes;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Statement: public Node {
    public:
        Statement() = default;

        ~Statement() = default;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Argument: public Statement {
    public:
        explicit Argument(
            const std::shared_ptr<Expression> &expression
        ): expression(expression) {};

        Argument(
            const std::string &name, 
            const std::shared_ptr<Expression> &expression
        ): name(name), expression(expression) {};

        std::string name;

        std::shared_ptr<Expression> expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  Declarations
     */

    class Declaration: public Statement {};

    class ConstantDeclaration: public Declaration {};

    class EnumerationDeclaration: public Declaration {
    public:
        explicit EnumerationDeclaration(
            const std::string &name
        ): name(name) {};

        std::string name;
    };

    class ModuleDeclaration: public Declaration {
    public:
        explicit ModuleDeclaration(const std::string &name): name(name) {};

        ModuleDeclaration(
            const std::string &name, 
            const std::vector<std::shared_ptr<Declaration>> &items
        ): name(name), items(items) {};

        std::string name;

        std::vector<std::shared_ptr<Declaration>> items;
    };

    class RecordDeclaration: public Declaration {
    public:
        RecordDeclaration(
            const std::string &name, 
            const std::vector<std::shared_ptr<RecordFieldDeclaration>> &items
        ): name(name), items(items) {};

        std::string name;

        std::vector<std::shared_ptr<RecordFieldDeclaration>> items;
    };

    class RecordFieldDeclaration: public Declaration {
    public:
        RecordFieldDeclaration(
            const std::string &name, 
            std::shared_ptr<Type::Type> type
        ): name(name), type(type) {};

        std::string name;

        std::shared_ptr<Type::Type> type;
    };

    class SubroutineDeclaration: public Declaration {
    public:
        SubroutineDeclaration(
            const std::string &name, 
            std::shared_ptr<TypeSignature> signature
        ): name(name), signature(signature) {};

        std::string name;

        std::shared_ptr<TypeSignature> signature;
    };

    class TypeAliasDeclaration: public Declaration {
    public:
        TypeAliasDeclaration(
            const std::string &name, 
            std::shared_ptr<Type::Type> type
        ): name(name), type(type) {};

        std::string name;

        std::shared_ptr<Type::Type> type;
    };

    class UnionDeclaration: public Declaration {
    public:
        UnionDeclaration(
            const std::string &name, 
            const std::vector<std::shared_ptr<RecordFieldDeclaration>> &items
        ): name(name), items(items) {};

        std::string name;

        std::vector<std::shared_ptr<RecordFieldDeclaration>> items;
    };

    /*
     *  Expressions
     */

    class Expression: public Statement {};

    /*
     *  An array expression, e.g.
     *
     *      [1, 2, 3]
     */
    class ArrayExpression: public Expression {
    public:
        explicit ArrayExpression(
            const std::vector<std::shared_ptr<Expression>> &items
        ): items(items) {};

        std::vector<std::shared_ptr<Expression>> items;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A binary operation expression, e.g.
     *
     *      a + b
     */
    class BinaryOperationExpression: public Expression {
    public:
        BinaryOperationExpression(
            const std::string &name, 
            std::shared_ptr<Expression> a
        ): name(name), a(a) {};

        BinaryOperationExpression(
            const std::string &name, 
            std::shared_ptr<Expression> a, 
            std::shared_ptr<Expression> b
        ): name(name), a(a), b(b) {};

        std::string name;

        std::shared_ptr<Expression> a;
        std::shared_ptr<Expression> b;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A block expression, e.g.
     *
     *      { true }
     */
    class BlockExpression: public Expression {
    public:
        BlockExpression() = default;

        explicit BlockExpression(
            const std::vector<std::shared_ptr<Statement>> &statements
        ): statements(statements) {};

        std::vector<std::shared_ptr<Statement>> statements;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A Boolean literal expression, e.g.
     *
     *      true
     */
    class BooleanLiteralExpression: public Expression {
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
    class BreakExpression: public Expression {
    public:
        BreakExpression() = default;

        explicit BreakExpression(const std::string &name): name(name) {};

        explicit BreakExpression(
            std::shared_ptr<LabelDeclaration> label
        ): label(label) {};

        std::optional<std::shared_ptr<LabelDeclaration>> label;

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
    class CallExpression: public Expression {
    public:
        CallExpression(
            std::shared_ptr<Expression> expression,
            const std::vector<std::shared_ptr<Argument>> &arguments
        ): expression(expression), arguments(arguments) {};

        std::shared_ptr<Expression> expression;

        std::vector<std::shared_ptr<Argument>> arguments;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A closure expression, e.g.
     *
     *      λ (x: 8-bit Integer) → 8-bit Integer { a + 1 }
     */
    class ClosureExpression: public Expression {
    public:
        explicit ClosureExpression(
            std::shared_ptr<BlockExpression> expression
        ): expression(expression) {};

        ClosureExpression(
            std::shared_ptr<TypeSignature> signature, 
            std::shared_ptr<BlockExpression> expression
        ): signature(signature), expression(expression) {};

        std::shared_ptr<TypeSignature> signature;

        std::shared_ptr<BlockExpression> expression;

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
    class ConditionalExpression: public Expression {
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
    class ContinueExpression: public Expression {
    public:
        ContinueExpression() = default;

        explicit ContinueExpression(
            std::shared_ptr<LabelDeclaration> label
        ): label(label) {};

        explicit ContinueExpression(const std::string &name): name(name) {};

        std::optional<std::shared_ptr<LabelDeclaration>> label;

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
    class FloatingPointLiteralExpression: public Expression {
    public:
        explicit FloatingPointLiteralExpression(
            const std::string &value
        ): value(value) {};

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
    class ForLoopExpression: public Expression {
    public:
        ForLoopExpression(const std::string &name) {};

        ForLoopExpression(
            const std::string &name, 
            std::shared_ptr<Expression> container, 
            std::shared_ptr<BlockExpression> expression
        ): name(name), container(container), expression(expression) {};

        std::string name;

        std::shared_ptr<Expression> container;

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
    class IntegerLiteralExpression: public Expression {
    public:
        explicit IntegerLiteralExpression(
            const std::string &value
        ): value(value) {};

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
    class RangeExpression: public Expression {
    public:
        RangeExpression(
            std::shared_ptr<Expression> a, 
            std::shared_ptr<Expression> b
        ): a(a), b(b) {};

        RangeExpression(
            std::shared_ptr<Expression> a, 
            std::shared_ptr<Expression> b, 
            std::shared_ptr<Expression> c
        ): a(a), b(b), c(c) {};

        std::shared_ptr<Expression> a;
        std::shared_ptr<Expression> b;

        std::optional<std::shared_ptr<Expression>> c;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A record expression, e.g.
     *
     *      A { a: 1, b: 2 }
     */
    class RecordExpression: public Expression {
    public:
        explicit RecordExpression(
            const std::vector<std::shared_ptr<Expression>> &expressions
        ): expressions(expressions) {};

        RecordExpression(
            const std::vector<std::shared_ptr<Expression>> &expressions, 
            std::shared_ptr<Expression> expression
        ): expressions(expressions), expression(expression) {};

        std::vector<std::shared_ptr<Expression>> expressions;

        std::optional<std::shared_ptr<Expression>> expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A return expression, e.g.
     *
     *      return
     */
    class ReturnExpression: public Expression {
    public:
        ReturnExpression() = default;

        explicit ReturnExpression(
            std::shared_ptr<Expression> expression
        ): expression(expression) {};

        explicit ReturnExpression(
            std::shared_ptr<LabelDeclaration> label
        ): label(label) {};

        std::optional<std::shared_ptr<LabelDeclaration>> label;

        std::shared_ptr<Expression> expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A subscript expression, e.g.
     *
     *      a[b]
     */
    class SubscriptExpression: public Expression {
    public:
        SubscriptExpression(
            std::shared_ptr<Expression> a, 
            const std::vector<std::shared_ptr<Argument>> &b
        ): a(a), b(b) {};

        std::shared_ptr<Expression> a;

        std::vector<std::shared_ptr<Argument>> b;

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
    class SwitchExpression: public Expression {
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
    class TupleExpression: public Expression {
    public:
        explicit TupleExpression(
            const std::vector<std::shared_ptr<Expression>> &items
        ): items(items) {};

        std::vector<std::shared_ptr<Expression>> items;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A unary operation expression, e.g.
     *
     *      −a
     */
    class UnaryOperationExpression: public Expression {
    public:
        explicit UnaryOperationExpression(
            std::shared_ptr<Expression> a
        ): a(a) {};

        UnaryOperationExpression(
            const std::string &operation, 
            std::shared_ptr<Expression> a
        ): operation(operation), a(a) {};

        std::shared_ptr<Expression> a;

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
    class WhileLoopExpression: public Expression {
    public:
        WhileLoopExpression() = default;

        WhileLoopExpression(
            std::shared_ptr<Expression> a, 
            std::shared_ptr<BlockExpression> b
        ): a(a), b(b) {};

        std::shared_ptr<Expression> a;

        std::shared_ptr<BlockExpression> b;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class GenericParameter: public Statement {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class LabelDeclaration: public Statement {
    public:
        explicit LabelDeclaration(const std::string &name): name(name) {};

        LabelDeclaration(
            const std::string &name, 
            std::shared_ptr<Statement> statement
        ): name(name), statement(statement) {};

        std::string name;

        std::shared_ptr<Statement> statement;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Parameter: public Statement {
    public:
        explicit Parameter(const std::string &name): name(name) {};

        Parameter(
            const std::string &name, 
            std::shared_ptr<Expression> expression
        ): name(name), expression(expression) {};

        Parameter(
            const std::string &name, 
            std::shared_ptr<Type::Type> type
        ): name(name), type(type) {};

        Parameter(
            const std::string &name, 
            std::shared_ptr<Type::Type> type, 
            std::shared_ptr<Expression> expression
        ): name(name), type(type), expression(expression) {};

        std::string name;

        std::shared_ptr<Type::Type> type;

        std::shared_ptr<Expression> expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TypeSignature: public Statement {
    public:
        TypeSignature() = default;

        explicit TypeSignature(
            const std::vector<std::shared_ptr<Parameter>> &parameters
        ): parameters(parameters) {};

        TypeSignature(
            const std::vector<std::shared_ptr<Parameter>> &parameters, 
            std::shared_ptr<Type::Type> type
        ): parameters(parameters), type(type) {};

        std::vector<std::shared_ptr<Parameter>> parameters;

        std::shared_ptr<Type::Type> type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };
}

#endif
