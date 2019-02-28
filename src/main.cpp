
#include "../include/oyster.hpp"
#include "../include/unit_test.hpp"

void runTest()
{
    std::shared_ptr<alef::UnitTest> test = alef::UnitTest::initialize();
    test->before();
    test->run();
    test->after();
}

int main(int argc, char **args)
{
    if (!(argc > 1 && std::string("test").compare(args[1]) == 0))
    {
        alef::Oyster::run();
    } else {
        runTest();
    }
}
