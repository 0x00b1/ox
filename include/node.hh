#ifndef OX_NODE_HH
#define OX_NODE_HH

class Visitor;

namespace AST {
    class Node {
    public:
        Node() {}

        virtual ~Node() {}

        virtual void accept(Visitor &visitor) = 0;
    };
}

#endif
