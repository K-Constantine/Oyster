
#include "../../include/model/location.hpp"

using namespace alef;

std::string Location::getName()
{
    return this->name;
}

std::vector<int> Location::getZones()
{
    return this->zones;
}
