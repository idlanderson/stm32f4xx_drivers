#include <cstdint>

static volatile unsigned &RCC_AHB1 = *reinterpret_cast<unsigned *>(0x40021014);

class Test
{
public:
    std::uint32_t Add(std::uint32_t a, std::uint32_t b) 
    { 
        return a + b; 
    }
};

int main()
{
    Test test;
    test.Add(1, 2);

    return 0U;
}