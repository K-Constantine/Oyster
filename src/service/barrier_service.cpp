
#include "../../include/service/barrier_service.hpp"

using namespace alef;

constexpr double BarrierService::MAX_FEE;
constexpr double BarrierService::BUS_FEE;
constexpr double BarrierService::ONLY_ZONE_ONE_FEE;
constexpr double BarrierService::ONE_ZONE_NOT_INCLUDING_ZONE_ONE_FEE;
constexpr double BarrierService::TWO_ZONES_INCLUDING_ZONE_ONE_FEE;
constexpr double BarrierService::TWO_ZONES_EXCLUDING_ZONE_ONE_FEE;

BarrierService::BarrierService()
{
    locations.push_back(std::shared_ptr<Location>(new Location("Holborn", {1})));
    locations.push_back(std::shared_ptr<Location>(new Location("Earl's Court", {1, 2})));
    locations.push_back(std::shared_ptr<Location>(new Location("Wimbledon", {3})));
    locations.push_back(std::shared_ptr<Location>(new Location("Hammersmith", {2})));
}

std::shared_ptr<Barrier> BarrierService::create(const std::shared_ptr<Card> &card,
                                                const std::shared_ptr<Trip> &trip)
{
    if (card == nullptr || trip == nullptr || trip->getStatus() == TripStatus::FINISHED)
    {
        throw std::logic_error("Invalid details provided!");
    }
    if (!(card->getAmount() >= getInitialCost(trip)))
    {
        throw std::logic_error("Insufficent found to carry out this transaction!");
    }
    return std::shared_ptr<Barrier>(new Barrier(card, trip));
}

void BarrierService::endTrip(const long id)
{
    std::shared_ptr<Barrier> barrier = this->journies.at(id);
    if (barrier == nullptr)
    {
        throw std::logic_error("Invalid trip id provided!");
    }
    barrier->trip->finish();
    if (barrier->trip->getType() == TripType::BUS)
    {
        return;
    }
    barrier->card->credit(MAX_FEE - this->getCost(barrier->trip));
}

void BarrierService::startTrip(const std::shared_ptr<Barrier> &barrier)
{
    barrier->card->debit(getInitialCost(barrier->trip));
    this->journies.insert({barrier->trip->getId(), barrier});
}

double BarrierService::getCost(const std::shared_ptr<Trip> &trip)
{
    auto origin = trip->getOrigin();
    auto destination = trip->getDestination();

    std::vector<double> prices;

    prices.push_back(MAX_FEE);
    if (contains(1, origin->getZones()) && contains(1, destination->getZones()))
    {
        prices.push_back(ONLY_ZONE_ONE_FEE);
    }
    if (!contains(1, origin->getZones()) || !contains(1, destination->getZones()))
    {
        prices.push_back(ONE_ZONE_NOT_INCLUDING_ZONE_ONE_FEE);
    }
    if (contains(1, origin->getZones()) || contains(1, destination->getZones()))
    {
        prices.push_back(TWO_ZONES_INCLUDING_ZONE_ONE_FEE);
    }
    if (!contains(1, origin->getZones()) && !contains(1, destination->getZones()))
    {
        prices.push_back(TWO_ZONES_EXCLUDING_ZONE_ONE_FEE);
    }
    return *std::min_element(std::begin(prices), std::end(prices));
}

double BarrierService::getInitialCost(const std::shared_ptr<Trip> &trip)
{
    return (trip->getType() == TripType::BUS) ? BUS_FEE : MAX_FEE;
}

std::shared_ptr<Barrier> BarrierService::getLastTrip()
{
    return (--this->journies.end())->second;
}

std::vector<std::shared_ptr<Location>> BarrierService::getLocations()
{
    return this->locations;
}

bool BarrierService::contains(const int x, const std::vector<int> &v)
{
    return std::find(v.begin(), v.end(), x) != v.end();
}
