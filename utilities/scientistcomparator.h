#ifndef SCIENTISTCOMPARATOR_H
#define SCIENTISTCOMPARATOR_H
#include "Programmer.h"

using namespace std;

/**
 * @brief The ScientistComparator can compare two scientists by rules set in the constructor when used with a sort function
 */
class ScientistComparator
{
public:
    ScientistComparator(string sortColumn, bool sortInAscendingOrder);

    bool operator() (const Programmer& first, const Programmer& second);
private:
    string sortColumn;
    bool sortInAscendingOrder;
};

#endif // SCIENTISTCOMPARATOR_H
