#include "ExternalPackageItem.hh"

Node::ExternalPackageItem::ExternalPackageItem() = default;

void Node::ExternalPackageItem::accept(Visitor &visitor) {
  std::shared_ptr<ExternalPackageItem> p{shared_from_this()};

  visitor.accept(p);
}
