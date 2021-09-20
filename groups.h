#include <iostream>
#include <string.h>
#include <vector>
#include "people.h"
#include "seniorEmployees.h"
#include "enumerations.h"

#ifndef GROUPS_H_
#define GROUPS_H_
class Groups {
public:
    Groups();
    Groups(string group_name);
    ~Groups(){ }

    string getGroupName() const;

protected:
    std::vector<People> people_holder;
    int groupCount;
    string groupName;
};


Groups::Groups() {
    groupName = "";
    groupCount = 0;
}

Groups::Groups(string group_name) {
    groupName = (group_name);
    groupCount = 0;
}

string Groups::getGroupName() const {
    return this->groupName;
}
#endif //GROUPS_H_