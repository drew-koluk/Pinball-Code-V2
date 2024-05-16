#ifndef DROP_TARGET_H
#define DROP_TARGET_H

#include <vector>
#include "Coil.h"

class DropTarget {
private:
    std::vector<Coil> coils;

public:
    DropTarget(const std::vector<int>& pinNums);

    const std::vector<Coil>& getCoils() const;

    size_t size() const;
};

#endif // DROP_TARGET_H
