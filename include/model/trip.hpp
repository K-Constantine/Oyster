
#include "../stl.hpp"
#include "location.hpp"

namespace alef
{
enum TripType
{
    BUS,
    TUBE
};

enum TripStatus
{
    ACTIVE,
    FINISHED
};

class Trip
{
    friend class BarrierService;

    long id;

    TripType type;
    TripStatus status;

    std::string name;
    std::shared_ptr<Location> origin;
    std::shared_ptr<Location> destination;

    Trip(const TripType type, const std::string &name)
        : type(type), status(TripStatus::ACTIVE), name(name)
    {
        this->id = helper::generateId<long>();
    }

    void setOrigin(const std::shared_ptr<Location> &origin);
    void setDestination(const std::shared_ptr<Location> &destination);

    void finish();

  public:
    long getId();

    TripType getType();
    TripStatus getStatus();

    std::string getName();
    std::shared_ptr<Location> getOrigin();
    std::shared_ptr<Location> getDestination();

    static std::shared_ptr<Trip> bus(const std::shared_ptr<Location> &origin,
                                     const std::shared_ptr<Location> &destination);
    static std::shared_ptr<Trip> tube(const std::shared_ptr<Location> &origin,
                                      const std::shared_ptr<Location> &destination);
};
}; // namespace alef
