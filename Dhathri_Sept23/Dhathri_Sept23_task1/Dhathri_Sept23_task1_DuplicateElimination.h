#ifndef DUPLICATEELIMINATION_H
#define DUPLICATEELIMINATION_H

#include <vector>

class DuplicateElimination {
private:
    std::vector<int> uniqueNumbers;

    bool isDuplicate(int number) const;

public:
    void addNumber(int number);
    const std::vector<int>& getUniqueNumbers() const;
};

#endif
