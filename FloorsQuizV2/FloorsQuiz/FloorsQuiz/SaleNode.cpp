#include "SaleNode.h"

SaleNode::SaleNode(int price) {
	this->price = price;
	this->saleNext = nullptr;
}
SaleNode::~SaleNode() {

}

double SaleNode::getPrice() {
	return this->price;
}
SaleNode* SaleNode::getSaleNext() {
	return this->saleNext;
}

void SaleNode::setPrice(double price) {
	this->price = price;
}
void SaleNode::setSaleNext(SaleNode* newSaleNext) {
	this->saleNext = newSaleNext;
}