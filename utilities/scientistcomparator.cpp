#include "utilities/scientistcomparator.h"
#include "utilities/utils.h"
#include "programmer.h"
#include "utilities/constants.h"
using namespace std;
using namespace constants;


ScientistComparator::ScientistComparator(string column, bool sortInAscendingOrder)
{
    this->sortColumn = column;
    this->sortInAscendingOrder = sortInAscendingOrder;
}

bool ScientistComparator::operator() (const Programmer& first, const Programmer& second)
{
    if (sortColumn == COLUMN_NAME)
    {
        if (sortInAscendingOrder)
        {
            return first.Name < second.Name;
        }
        else
        {
            return second.Name < first.Name;
        }
    }
    else if (sortColumn == COLUMN_GENDER)
    {
        if (sortInAscendingOrder)
        {
            return first.Gender < second.Gender;
        }
        else
        {
            return second.Gender < first.Gender;
        }
    }

    return false;
}



