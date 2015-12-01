#include "domain.h"

domain::domain()
{
    //ctor
}

//search in vektor for the name inputed
vector<programmers> domain::searchName(vector<programmers> programmers, string p.Name) {
    vector<programmers> searchResult;
    normalizeName(name);

    for(unsigned int i = 0; i < programmers.size(); i++){
        if(name == programmers[i].name){
           searchResult.push_back(programmers[i]);
        }
    }
    return searchResult;
}
