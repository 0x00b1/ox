#ifndef OX_OX_HH
#define OX_OX_HH

#include <iostream>
#include <vector>

class Visitor;

class Node {
public:
    virtual void accept(Visitor &visitor) = 0;
};

class ArrayExpression;
class Block;
class BooleanLiteral;
class BreakExpression;
class Call;
class ClosureExpression;
class Conditional;
class ConstantDeclaration;
class ContinueExpression;
class EnumeratedDeclaration;
class Expression;
class FloatingPointLiteral;
class For;
class Goto;
class IndexExpression;
class IntegerLiteral;
class ModuleItem;
class OperatorDeclaration;
class RecordExpression;
class RecordDeclaration;
class ReturnExpression;
class SubroutineDeclaration;
class Switch;
class TupleExpression;
class TypeDeclaration;
class UnionDeclaration;
class While;

class Visitor {
public:
    virtual void visit(ArrayExpression &file) = 0;
    virtual void visit(Block &file) = 0;
    virtual void visit(BooleanLiteral &file) = 0;
    virtual void visit(BreakExpression &file) = 0;
    virtual void visit(Call &file) = 0;
    virtual void visit(ClosureExpression &file) = 0;
    virtual void visit(Conditional &file) = 0;
    virtual void visit(ConstantDeclaration &file) = 0;
    virtual void visit(ContinueExpression &file) = 0;
    virtual void visit(EnumeratedDeclaration &file) = 0;
    virtual void visit(FloatingPointLiteral &file) = 0;
    virtual void visit(For &file) = 0;
    virtual void visit(Goto &file) = 0;
    virtual void visit(IndexExpression &file) = 0;
    virtual void visit(IntegerLiteral &file) = 0;
    virtual void visit(Expression &file) = 0;
    virtual void visit(ModuleItem &file) = 0;
    virtual void visit(OperatorDeclaration &file) = 0;
    virtual void visit(RecordExpression &file) = 0;
    virtual void visit(RecordDeclaration &file) = 0;
    virtual void visit(ReturnExpression &file) = 0;
    virtual void visit(SubroutineDeclaration &file) = 0;
    virtual void visit(Switch &file) = 0;
    virtual void visit(TupleExpression &file) = 0;
    virtual void visit(TypeDeclaration &file) = 0;
    virtual void visit(UnionDeclaration &file) = 0;
    virtual void visit(While &file) = 0;
};

class ArrayExpression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Block: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class BooleanLiteral: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class BreakExpression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Call: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class ClosureExpression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Conditional: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class ConstantDeclaration: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class ContinueExpression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class EnumeratedDeclaration: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class FloatingPointLiteral: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class For: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Goto: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class IndexExpression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class IntegerLiteral: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Expression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class ModuleItem: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class OperatorDeclaration: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class RecordExpression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class RecordDeclaration: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class ReturnExpression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class SubroutineDeclaration: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Switch: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class TupleExpression: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class TypeDeclaration: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class UnionDeclaration: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class While: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Generator: public Visitor {
public:
    void visit(ArrayExpression &) override {
        std::cout << "generating BooleanLiteral" << std::endl;
    }

    void visit(Block &) override {
        std::cout << "generating BooleanLiteral" << std::endl;
    }

    void visit(BooleanLiteral &) override {
        std::cout << "generating BooleanLiteral" << std::endl;
    }

    void visit(BreakExpression &) override {
        std::cout << "generating BreakExpression" << std::endl;
    }

    void visit(Call &) override {
        std::cout << "generating BreakExpression" << std::endl;
    }

    void visit(ClosureExpression &) override {
        std::cout << "generating ClosureExpression" << std::endl;
    }

    void visit(Conditional &) override {
        std::cout << "generating Conditional" << std::endl;
    }

    void visit(ConstantDeclaration &) override {
        std::cout << "generating ConstantDeclaration" << std::endl;
    }

    void visit(ContinueExpression &) override {
        std::cout << "generating ContinueExpression" << std::endl;
    }

    void visit(FloatingPointLiteral &) override {
        std::cout << "generating FloatingPointLiteral" << std::endl;
    }

    void visit(For &) override {
        std::cout << "generating FloatingPointLiteral" << std::endl;
    }

    void visit(Goto &) override {
        std::cout << "generating Goto" << std::endl;
    }

    void visit(IndexExpression &) override {
        std::cout << "generating IndexExpression" << std::endl;
    }

    void visit(IntegerLiteral &) override {
        std::cout << "generating IntegerLiteral" << std::endl;
    }

    void visit(EnumeratedDeclaration &) override {
        std::cout << "generating EnumeratedDeclaration" << std::endl;
    }

    void visit(Expression &) override {
        std::cout << "generating Expression" << std::endl;
    }

    void visit(ModuleItem &) override {
        std::cout << "generating ModuleItem" << std::endl;
    }

    void visit(OperatorDeclaration &) override {
        std::cout << "generating OperatorDeclaration" << std::endl;
    }

    void visit(RecordExpression &) override {
        std::cout << "generating RecordExpression" << std::endl;
    }

    void visit(RecordDeclaration &) override {
        std::cout << "generating RecordDeclaration" << std::endl;
    }

    void visit(ReturnExpression &) override {
        std::cout << "generating ReturnExpression" << std::endl;
    }

    void visit(SubroutineDeclaration &) override {
        std::cout << "generating SubroutineDeclaration" << std::endl;
    }

    void visit(Switch &) override {
        std::cout << "generating Switch" << std::endl;
    }

    void visit(TupleExpression &) override {
        std::cout << "generating TypeDeclaration" << std::endl;
    }

    void visit(TypeDeclaration &) override {
        std::cout << "generating TypeDeclaration" << std::endl;
    }

    void visit(UnionDeclaration &) override {
        std::cout << "generating UnionDeclaration" << std::endl;
    }

    void visit(While &) override {
        std::cout << "generating While" << std::endl;
    }
};

#endif
