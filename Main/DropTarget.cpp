#include "DropTarget.h"

DropTarget::DropTarget(const std::vector<int>& pinNums) {
    for (int pinNum : pinNums) {
        coils.push_back(Coil(pinNum));
    }
}

const std::vector<Coil>& DropTarget::getCoils() const {
    return coils;
}

size_t DropTarget::size() const {
    return coils.size();
}
