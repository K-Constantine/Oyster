
#include "../../include/model/card.hpp"

using namespace alef;

long Card::getNumber() {
    return this->number;
}

double Card::getAmount() {
    return this->amount;
}

std::string Card::getName() {
    return this->name;
}

void Card::credit(const double amount) {
    this->amount += amount;
}

void Card::debit(const double amount) {
    this->amount -= amount;
}

std::shared_ptr<Card> Card::generateCard(const std::string & name, const double amount) {
    return std::shared_ptr<Card>(new Card(helper::generateId<long>(), amount, name));
}
