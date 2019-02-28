
#include "../stl.hpp"
#include "card.hpp"
#include "trip.hpp"

namespace alef
{
class Barrier
{
    friend class BarrierService;

    std::shared_ptr<Card> card;
    std::shared_ptr<Trip> trip;

    Barrier(
        const std::shared_ptr<Card> &card,
        const std::shared_ptr<Trip> &trip)
        : card(move(card)), trip(move(trip)) {}

  public:
    std::shared_ptr<Card> getCard();
    std::shared_ptr<Trip> getTrip();
};
}; // namespace alef
