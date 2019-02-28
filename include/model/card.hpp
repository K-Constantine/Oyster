
#include "../stl.hpp"

namespace alef
{
class BarrierService;

class Card
{
    friend class BarrierService;

    long number;
    double amount;

    std::string name;

    Card(const long number, const double amount, const std::string &name)
        : number(number), amount(amount), name(name)
    {
    }

    void credit(const double amount);
    void debit(const double amount);

  public:
    long getNumber();
    double getAmount();

    std::string getName();

    static std::shared_ptr<Card> generateCard(const std::string &name, const double amount);
};
}; // namespace alef
