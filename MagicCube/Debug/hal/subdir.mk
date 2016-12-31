################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/initialization.c 

CPP_SRCS += \
../hal/PinBase.cpp \
../hal/ShiftRegister.cpp \
../hal/ShiftRegisterArray.cpp \
../hal/Timer.cpp 

C_DEPS += \
./hal/initialization.d 

OBJS += \
./hal/PinBase.o \
./hal/ShiftRegister.o \
./hal/ShiftRegisterArray.o \
./hal/Timer.o \
./hal/initialization.o 

CPP_DEPS += \
./hal/PinBase.d \
./hal/ShiftRegister.d \
./hal/ShiftRegisterArray.d \
./hal/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
hal/%.o: ../hal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C++ Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-g++" -MMD -MT "$@" -DXMC1100_Q024x0064 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC1100_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -fno-exceptions -fno-rtti -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -g -gstabs+ -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
hal/%.o: ../hal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC1100_Q024x0064 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC1100_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -O0 -ffunction-sections -fdata-sections -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m0 -mthumb -g -gstabs+ -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

