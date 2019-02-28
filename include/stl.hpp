#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>
#include <random>
#include <vector>
#include <string>
#include <memory>
#include <map>

namespace helper
{
template <class T>
long generateId()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(100000000000.0, 900000000000.0);

    return dist(mt);
}
} // namespace helper 