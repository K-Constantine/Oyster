
#include "../../include/unit_test.hpp"
#include "../../include/service/barrier_service.hpp"

using namespace std;
using namespace alef;

class Test : public UnitTest
{
    shared_ptr<BarrierService> service;

    void clear();
    void space();

    shared_ptr<Card> cardTest();
    shared_ptr<Trip> busTripTest();
    shared_ptr<Trip> tubeTripTest();

    void showLocations();
    
    void endJourney(const shared_ptr<Barrier> &barrier);
    void startJourney(const shared_ptr<Barrier> &barrier);

  public:
    void before();
    void run();
    void after();
};
