#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>



// This file contains constants that this application uses


namespace constants {

    const string DATABASE_FILE_NAME = "database.db";

    const string PROGRAMMERS_ORDER_NAME           = "Name";
    const string PROGRAMMERS_ORDER_NAME_DESC      = "Name desc";
    const string PROGRAMMERS_ORDER_GENDER         = "Gender, Name";
    const string PROGRAMMERS_ORDER_GENDER_DESC    = "Gender desc, Name";
    const string PROGRAMMERS_ORDER_BIRTHYEAR      = "Birthyear, Name";
    const string PROGRAMMERS_ORDER_BIRTHYEAR_DESC = "Birthyear desc, Name";
    const string PROGRAMMERS_ORDER_DEADYEAR       = "Deadyear, Name";
    const string PROGRAMMERS_ORDER_DEADYEAR_DESC  = "Deadyear desc, Name";

    const string COMPUTERS_ORDER_NAME            = "Name";
    const string COMPUTERS_ORDER_NAME_DESC       = "Name desc";
    const string COMPUTERS_ORDER_TYPE            = "Type";
    const string COMPUTERS_ORDER_TYPE_DESC       = "Type desc, Name";
    const string COMPUTERS_ORDER_WASITBUILT      = "Wasitbuilt";
    const string COMPUTERS_ORDER_WASITBUILT_DESC = "Wasitbuilt desc, Name";
    const string COMPUTERS_ORDER_YEARBUILT       = "Yearbuilt, Name";
    const string COMPUTERS_ORDER_YEARBUILT_DESC  = "Yearbuilt desc, Name";


}

#endif // CONSTANTS_H

