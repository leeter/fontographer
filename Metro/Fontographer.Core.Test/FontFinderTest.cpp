#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Fontographer::Core;
namespace Fontographer_Core_Test
{
    TEST_CLASS(FontFinderTest)
    {
    public:
        TEST_METHOD(ConstructorTest)
        {
            auto finder = ref new FontFinder();
        }
    };
}