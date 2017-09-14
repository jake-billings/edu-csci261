################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Player.cpp \
../src/Tile.cpp \
../src/TileMap.cpp \
../src/main.cpp 

OBJS += \
./src/Player.o \
./src/Tile.o \
./src/TileMap.o \
./src/main.o 

CPP_DEPS += \
./src/Player.d \
./src/Tile.d \
./src/TileMap.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


