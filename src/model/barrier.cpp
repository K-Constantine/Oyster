
#include "../../include/model/barrier.hpp"

using namespace alef;

std::shared_ptr<Card> Barrier::getCard() 
{
    return this->card;
}

std::shared_ptr<Trip> Barrier::getTrip()
{
    return this->trip;
}
