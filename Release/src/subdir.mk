################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GameBoard.cpp \
../src/GameController.cpp \
../src/Mastermind.cpp \
../src/Peg.cpp \
../src/Slot.cpp 

OBJS += \
./src/GameBoard.o \
./src/GameController.o \
./src/Mastermind.o \
./src/Peg.o \
./src/Slot.o 

CPP_DEPS += \
./src/GameBoard.d \
./src/GameController.d \
./src/Mastermind.d \
./src/Peg.d \
./src/Slot.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


