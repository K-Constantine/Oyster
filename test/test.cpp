
#include "include/test.hpp"

void Test::clear()
{
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
    }
}

void Test::space()
{
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }
}

void Test::before()
{
    this->clear();
    this->service = make_shared<BarrierService>();
}

void Test::run()
{
    this->showLocations();
    shared_ptr<Barrier> barrier = service->create(
        this->cardTest(), this->tubeTripTest());

    this->startJourney(barrier);
    this->endJourney(barrier);
}

shared_ptr<Card> Test::cardTest()
{
    shared_ptr<Card> card = Card::generateCard("Kevin Constantine", 50);
    cout << card->getNumber() << '(' << card->getName() << ')' << endl;

    return card;
}

shared_ptr<Trip> Test::busTripTest()
{
    shared_ptr<Trip> trip = Trip::bus(
        this->service->getLocations().at(0),
        this->service->getLocations().at(1));
    string status = (0 == trip->getStatus()) ? "ACTIVE" : "FINISHED";

    cout << trip->getName() << '(' << status << ')' << endl;
    return trip;
}

shared_ptr<Trip> Test::tubeTripTest()
{
    shared_ptr<Trip> trip = Trip::tube(
        this->service->getLocations().at(2),
        this->service->getLocations().at(3));
    string status = (0 == trip->getStatus()) ? "ACTIVE" : "FINISHED";

    cout << trip->getName() << '(' << status << ") "
         << trip->getOrigin()->getName()
         << " - " << trip->getDestination()->getName() << endl;
    return trip;
}

void Test::endJourney(const shared_ptr<Barrier> &barrier)
{
    this->service->endTrip(barrier->getTrip()->getId());
    cout << "Ledger balance: " << barrier->getCard()->getAmount() << endl;
}

void Test::startJourney(const shared_ptr<Barrier> &barrier)
{
    this->service->startTrip(barrier);
    cout << "Avaialable balance: " << barrier->getCard()->getAmount() << endl;
}

void Test::showLocations()
{
    auto locations = this->service->getLocations();
    for (auto itr = locations.begin(); itr != locations.end(); itr++)
    {
        cout << (*itr)->getName() << endl;
    }
    this->space();
}

void Test::after()
{
    this->clear();
}

shared_ptr<UnitTest> UnitTest::initialize()
{
    return make_shared<Test>();
}
