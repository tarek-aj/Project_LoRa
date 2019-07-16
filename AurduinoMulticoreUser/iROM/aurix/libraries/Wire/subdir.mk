################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../aurix/libraries/Wire/Wire.cpp 

OBJS += \
./aurix/libraries/Wire/Wire.o 

CPP_DEPS += \
./aurix/libraries/Wire/Wire.d 


# Each subdirectory must supply rules for building sources it contributes
aurix/libraries/Wire/%.o: ../aurix/libraries/Wire/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C++ Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\cores\aurduino" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Scu\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Stm\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Cpu\Irq" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\_Lib\DataHandling" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Cpu\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\cores\aurduino\avr" -I"../h" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\libraries\Ethernet\src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\libraries\Ethernet\src\utility" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\libraries\LiquidCrystal" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\libraries\SD\src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\libraries\SD\src\utility" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\libraries\SPI" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\libraries\TFTV2" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\libraries\Wire" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\_Build" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\system\libaurix\include" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\_Impl" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\_Lib" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\_PinMap" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\_Reg" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Asclin" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Ccu6" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Cif" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Cpu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Dma" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Dsadc" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Dts" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Emem" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Eray" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Eth" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Fce" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Flash" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Gtm" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Hssl" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\I2c" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Iom" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Msc" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Mtu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Multican" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Port" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Psi5" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Psi5s" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Qspi" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Scu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Sent" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\SrvSw" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Stm" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\AurduinoUser\aurix\variants\tc275\iLLD\Include\Vadc" -fno-common -O0 -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -DUSE_IRQ -DTRIBOARD_TC275C -include Variant.h -fshort-double -mcpu=tc27xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


