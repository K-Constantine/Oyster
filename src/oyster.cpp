
#include "../include/oyster.hpp"

using namespace std;
using namespace alef;

void showCardDetails(const shared_ptr<Card> &card)
{
    cout << "\nHere are your card details: "
         << "\n\nNumber: " << card->getNumber()
         << "\nName: " << card->getName()
         << "\nAmount: $" << card->getAmount() << endl;
}

void showLocations(const shared_ptr<BarrierService> &service)
{
    int32_t location = 0;
    for (auto itr = service->getLocations().begin();
         itr != service->getLocations().end(); itr++)
    {
        location += 1;
        cout << location << ") " << (*itr)->getName() << endl;
    }
}

void startTrip()
{
    char name[250];
    double amount;
    int32_t temp = -1;
    int32_t tripType = -1;
    int32_t location = -1;
    int32_t destination = -1;

    shared_ptr<Card> card = nullptr;
    shared_ptr<Trip> trip = nullptr;
    shared_ptr<BarrierService> service = make_shared<BarrierService>();

    cout << "\n\n\n\n\n\n\n\nHello, Please provide the neccessary information needed to asin an oyster card to you :). Thank you" << endl;
    cout << "\n\nFull Name: ";

    cin.getline(name, sizeof(name));

    cout << "Amount Deposited: ";
    cin >> amount;

    card = Card::generateCard(name, amount);

    cout << "\n\nSelect current location: " << endl;
    showLocations(service);

    cin >> location;
    if (location > service->getLocations().size() || location < 1)
    {
        cout << "Invalide location provided!" << endl;
        return;
    }
    showCardDetails(card);

    cout << "\n\nWhat trip would you like to get on?\n1) Bus trip \n2) Tube trip" << endl;
    cin >> tripType;

    cout << "\n\nSelect Destination: " << endl;
    showLocations(service);

    cin >> destination;
    if (destination > service->getLocations().size() || destination < 1)
    {
        cout << "Invalide location provided!" << endl;
        return;
    }

    if (tripType == 1)
    {
        trip = Trip::bus(service->getLocations().at(location - 1), service->getLocations().at(destination - 1));
    }
    else if (tripType == 2)
    {
        trip = Trip::tube(service->getLocations().at(location - 1), service->getLocations().at(destination - 1));
    }
    else
    {
        cout << "Specified trip type not available!" << endl;
        return;
    }

    shared_ptr<Barrier> barrier = service->create(card, trip);
    service->startTrip(barrier);
    cout << "Avaialable balance: " << barrier->getCard()->getAmount() << endl;

    if (tripType == 1) {
        cout << endl << endl;
        return;
    }

    cout << "\n\nWelcome to " << trip->getDestination()->getName() << endl;
    cout << "Do you want to use the barrier exit?\n1) Yes\n2) No" << endl;

    cin >> temp;
    if (temp == 1)
    {
        service->endTrip(barrier->getTrip()->getId());
        cout << "\nFinal balance: " << barrier->getCard()->getAmount() << endl;
    }
    cout << endl << endl;
}

void Oyster::run()
{
    try {
        startTrip();
    } catch(logic_error ex) {
        cout << "\n\n" << ex.what() << endl;
    }
}
