#ifndef SYSCFG_HPP_
#define SYSCFG_HPP_

#include "syscfg_register_map.hpp"

namespace stm32::syscfg
{
    class SyscfgPeripheral
    {
    public:
    	SyscfgPeripheral(uint32_t addr) : 
			device(*reinterpret_cast<SyscfgRegisterMap*>(addr)) { }
		SyscfgPeripheral(ISyscfgRegisterMap & device) : device(device) { }

        void SetMemoryMapping(MemoryMapping memoryMapping);
        void ConfigureGpioInterrupt(uint8_t extiLine, ExtiConfiguration extiConfiguration);
    private:
        ISyscfgRegisterMap & device;
    };
}

#endif // SYSCFG_HPP_