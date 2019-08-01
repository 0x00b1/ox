#include "SlicePattern.hh"

Node::SlicePattern::SlicePattern(std::vector<std::shared_ptr<Pattern>> patterns) {
  this->patterns = std::move(patterns);
};

void Node::SlicePattern::accept(Visitor &visitor) {
  std::shared_ptr<SlicePattern> p{shared_from_this()};

  visitor.accept(p);
}
