################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../frames/FloorRegister.cpp \
../frames/Frame.cpp 

OBJS += \
./frames/FloorRegister.o \
./frames/Frame.o 

CPP_DEPS += \
./frames/FloorRegister.d \
./frames/Frame.d 


# Each subdirectory must supply rules for building sources it contributes
frames/%.o: ../frames/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C++ Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-g++" -MMD -MT "$@" -DXMC1100_Q024x0064 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC1100_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -fno-exceptions -fno-rtti -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -g -gstabs+ -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

