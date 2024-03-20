################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cripto.cpp \
../src/mensaje.cpp \
../src/prog_principal.cpp 

OBJS += \
./src/cripto.o \
./src/mensaje.o \
./src/prog_principal.o 

CPP_DEPS += \
./src/cripto.d \
./src/mensaje.d \
./src/prog_principal.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


