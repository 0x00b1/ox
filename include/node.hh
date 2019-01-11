#ifndef OX_NODE_HH
#define OX_NODE_HH

class Visitor;

namespace AST {
    class Node {
    public:
        Node() = default;

        virtual ~Node() = default;

        virtual void accept(Visitor &visitor) = 0;
    };
}

#endif
