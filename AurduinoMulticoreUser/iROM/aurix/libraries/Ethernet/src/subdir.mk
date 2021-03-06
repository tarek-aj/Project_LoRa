################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../aurix/libraries/Ethernet/src/Dhcp.cpp \
../aurix/libraries/Ethernet/src/Dns.cpp \
../aurix/libraries/Ethernet/src/Ethernet.cpp \
../aurix/libraries/Ethernet/src/EthernetClient.cpp \
../aurix/libraries/Ethernet/src/EthernetServer.cpp \
../aurix/libraries/Ethernet/src/EthernetUdp.cpp 

OBJS += \
./aurix/libraries/Ethernet/src/Dhcp.o \
./aurix/libraries/Ethernet/src/Dns.o \
./aurix/libraries/Ethernet/src/Ethernet.o \
./aurix/libraries/Ethernet/src/EthernetClient.o \
./aurix/libraries/Ethernet/src/EthernetServer.o \
./aurix/libraries/Ethernet/src/EthernetUdp.o 

CPP_DEPS += \
./aurix/libraries/Ethernet/src/Dhcp.d \
./aurix/libraries/Ethernet/src/Dns.d \
./aurix/libraries/Ethernet/src/Ethernet.d \
./aurix/libraries/Ethernet/src/EthernetClient.d \
./aurix/libraries/Ethernet/src/EthernetServer.d \
./aurix/libraries/Ethernet/src/EthernetUdp.d 


# Each subdirectory must supply rules for building sources it contributes
aurix/libraries/Ethernet/src/%.o: ../aurix/libraries/Ethernet/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C++ Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\cores\aurduino" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\EEPROM\src" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\Servo\src\aurix" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\Servo\src" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\MIDI\src" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Scu\Std" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Stm\Std" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Cpu\Irq" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\_Lib\DataHandling" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Cpu\Std" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\cores\aurduino\avr" -I"../h" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\Ethernet\src" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\Ethernet\src\utility" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\LiquidCrystal" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\SD\src" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\SD\src\utility" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\SPI" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\TFTV2" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\libraries\Wire" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\_Build" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\system\libaurix\include" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\_Impl" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\_Lib" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\_PinMap" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\_Reg" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Asclin" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Ccu6" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Cif" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Cpu" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Dma" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Dsadc" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Dts" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Emem" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Eray" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Eth" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Fce" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Flash" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Gtm" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Hssl" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\I2c" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Iom" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Msc" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Mtu" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Multican" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Port" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Psi5" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Psi5s" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Qspi" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Scu" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Sent" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Src" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\SrvSw" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Stm" -I"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275\iLLD\Include\Vadc" -fno-common -O2 -fgcse-after-reload -ffast-math -funswitch-loops -fpredictive-commoning -ftree-vectorize -fipa-cp-clone -fpeel-loops -fmove-loop-invariants -frename-registers -fira-algorithm=priority -g3 -W -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -DUSE_IRQ -DARDUINO_ARCH_AURIX -DTRIBOARD_TC275C -include Variant.h -fshort-double -mcpu=tc27xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


