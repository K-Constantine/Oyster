
#include "../stl.hpp"

namespace alef
{
class BarrierService;

class Location
{
    friend class BarrierService;

    std::string name;
    std::vector<int> zones;

    Location(const std::string &name, const std::vector<int> &zones)
        : name(name), zones(zones)
    {
    }

  public:
    std::string getName();
    std::vector<int> getZones();
};
}; // namespace alef
