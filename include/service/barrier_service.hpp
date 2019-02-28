
#include "../stl.hpp"
#include "../model/barrier.hpp"

namespace alef
{
class BarrierService
{
    std::map<long, std::shared_ptr<Barrier>> journies;
    std::vector<std::shared_ptr<Location>> locations;

    double getCost(const std::shared_ptr<Trip> &trip);
    double getInitialCost(const std::shared_ptr<Trip> &trip);

    bool contains(const int x, const std::vector<int> &v);

  public:
    BarrierService();

    std::shared_ptr<Barrier> create(const std::shared_ptr<Card> &card,
                                    const std::shared_ptr<Trip> &trip);

    void endTrip(const long id);
    void startTrip(const std::shared_ptr<Barrier> &barrier);

    std::shared_ptr<Barrier> getLastTrip();
    std::vector<std::shared_ptr<Location>> getLocations();

    static constexpr double MAX_FEE = 3.20;
    static constexpr double BUS_FEE = 1.80;
    static constexpr double ONLY_ZONE_ONE_FEE = 2.50;
    static constexpr double ONE_ZONE_NOT_INCLUDING_ZONE_ONE_FEE = 2.00;
    static constexpr double TWO_ZONES_INCLUDING_ZONE_ONE_FEE = 3.00;
    static constexpr double TWO_ZONES_EXCLUDING_ZONE_ONE_FEE = 2.25;
};
}; // namespace alef
