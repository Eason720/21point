#include "Card.h"
using namespace std;

Card::Card(int value) : value(value) {}

int Card::getValue() const {
    return value;
}
