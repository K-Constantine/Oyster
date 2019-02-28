
#include "../../include/model/trip.hpp"

using namespace alef;

long Trip::getId()
{
    return this->id;
}

TripType Trip::getType()
{
    return this->type;
}

std::string Trip::getName()
{
    return this->name;
}

void Trip::setOrigin(const std::shared_ptr<Location> & origin)
{
    this->origin = origin;
}

std::shared_ptr<Location> Trip::getOrigin() 
{
    return this->origin;
}

void Trip::setDestination(const std::shared_ptr<Location> & destination)
{
    this->destination = destination;
}

std::shared_ptr<Location> Trip::getDestination()
{
    return this->destination;
}

TripStatus Trip::getStatus()
{
    return this->status;
}

void Trip::finish()
{
    this->status = TripStatus::FINISHED;
}

std::shared_ptr<Trip> Trip::bus(
    const std::shared_ptr<Location> &origin,
    const std::shared_ptr<Location> &destination)
{
    auto trip = std::shared_ptr<Trip>(new Trip(TripType::BUS, "BUS_TRIP"));
    
    trip->setOrigin(origin);
    trip->setDestination(destination);

    return trip;
}

std::shared_ptr<Trip> Trip::tube(
    const std::shared_ptr<Location> &origin,
    const std::shared_ptr<Location> &destination)
{
    auto trip = std::shared_ptr<Trip>(new Trip(TripType::TUBE, "TUBE_TRIP"));

    trip->setOrigin(origin);
    trip->setDestination(destination);

    return trip;
}
