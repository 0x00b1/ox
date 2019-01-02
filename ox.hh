#ifndef OX_OX_HH
#define OX_OX_HH

#include <iostream>
#include <vector>

class Visitor;

class Node {
public:
    virtual void accept(Visitor &visitor) = 0;
};

class Array;
class Block;
class Boolean;
class Break;
class Call;
class Closure;
class Conditional;
class Constant;
class Continue;
class Enumerated;
class Expression;
class FloatingPoint;
class For;
class Goto;
class Integer;
class Module;
class Record;
class Return;
class Subroutine;
class Switch;
class Tuple;
class Type;
class Union;
class While;

class Visitor {
public:
    virtual void visit(Array &file) = 0;
    virtual void visit(Block &file) = 0;
    virtual void visit(Boolean &file) = 0;
    virtual void visit(Break &file) = 0;
    virtual void visit(Call &file) = 0;
    virtual void visit(Closure &file) = 0;
    virtual void visit(Conditional &file) = 0;
    virtual void visit(Constant &file) = 0;
    virtual void visit(Continue &file) = 0;
    virtual void visit(Enumerated &file) = 0;
    virtual void visit(FloatingPoint &file) = 0;
    virtual void visit(For &file) = 0;
    virtual void visit(Goto &file) = 0;
    virtual void visit(Integer &file) = 0;
    virtual void visit(Expression &file) = 0;
    virtual void visit(Module &file) = 0;
    virtual void visit(Record &file) = 0;
    virtual void visit(Return &file) = 0;
    virtual void visit(Subroutine &file) = 0;
    virtual void visit(Switch &file) = 0;
    virtual void visit(Tuple &file) = 0;
    virtual void visit(Type &file) = 0;
    virtual void visit(Union &file) = 0;
    virtual void visit(While &file) = 0;
};

class Array: public Node {
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

class Boolean: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Break: public Node {
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

class Closure: public Node {
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

class Constant: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Continue: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Enumerated: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class FloatingPoint: public Node {
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

class Integer: public Node {
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

class Module: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Record: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Return: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Subroutine: public Node {
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

class Tuple: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Type: public Node {
public:
    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

class Union: public Node {
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
    void visit(Array &) override {
        std::cout << "generating Boolean" << std::endl;
    }

    void visit(Block &) override {
        std::cout << "generating Boolean" << std::endl;
    }

    void visit(Boolean &) override {
        std::cout << "generating Boolean" << std::endl;
    }

    void visit(Break &) override {
        std::cout << "generating Break" << std::endl;
    }

    void visit(Call &) override {
        std::cout << "generating Break" << std::endl;
    }

    void visit(Closure &) override {
        std::cout << "generating Closure" << std::endl;
    }

    void visit(Conditional &) override {
        std::cout << "generating Conditional" << std::endl;
    }

    void visit(Constant &) override {
        std::cout << "generating Constant" << std::endl;
    }

    void visit(Continue &) override {
        std::cout << "generating Continue" << std::endl;
    }

    void visit(FloatingPoint &) override {
        std::cout << "generating FloatingPoint" << std::endl;
    }

    void visit(For &) override {
        std::cout << "generating FloatingPoint" << std::endl;
    }

    void visit(Goto &) override {
        std::cout << "generating Goto" << std::endl;
    }

    void visit(Integer &) override {
        std::cout << "generating Integer" << std::endl;
    }

    void visit(Enumerated &) override {
        std::cout << "generating Enumerated" << std::endl;
    }

    void visit(Expression &) override {
        std::cout << "generating Expression" << std::endl;
    }

    void visit(Module &) override {
        std::cout << "generating Module" << std::endl;
    }

    void visit(Record &) override {
        std::cout << "generating Record" << std::endl;
    }

    void visit(Return &) override {
        std::cout << "generating Return" << std::endl;
    }

    void visit(Subroutine &) override {
        std::cout << "generating Subroutine" << std::endl;
    }

    void visit(Switch &) override {
        std::cout << "generating Switch" << std::endl;
    }

    void visit(Tuple &) override {
        std::cout << "generating Type" << std::endl;
    }

    void visit(Type &) override {
        std::cout << "generating Type" << std::endl;
    }

    void visit(Union &) override {
        std::cout << "generating Union" << std::endl;
    }

    void visit(While &) override {
        std::cout << "generating While" << std::endl;
    }
};

#endif
