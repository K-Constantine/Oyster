
#include <assert.h>
#include "stl.hpp"

namespace alef {
    class UnitTest {
        public:
            virtual void before() = 0;
            virtual void run() = 0;
            virtual void after() = 0;

            static std::shared_ptr<UnitTest> initialize();
    };
};
