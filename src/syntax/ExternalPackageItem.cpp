#include "ExternalPackageItem.h"

Node::ExternalPackageItem::ExternalPackageItem(std::string identifier) {
  this->identifier = std::move(identifier);
}

Node::ExternalPackageItem::ExternalPackageItem(std::string identifier, std::string alias) {
  this->identifier = std::move(identifier);

  this->alias = std::move(alias);
}

void Node::ExternalPackageItem::accept(Visitor &visitor) {
  std::shared_ptr<ExternalPackageItem> p{shared_from_this()};

  visitor.accept(p);
}
