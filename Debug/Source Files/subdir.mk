################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source\ Files/DataProcessing.cpp \
../Source\ Files/PatternCalls.cpp \
../Source\ Files/main.cpp 

OBJS += \
./Source\ Files/DataProcessing.o \
./Source\ Files/PatternCalls.o \
./Source\ Files/main.o 

CPP_DEPS += \
./Source\ Files/DataProcessing.d \
./Source\ Files/PatternCalls.d \
./Source\ Files/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source\ Files/DataProcessing.o: ../Source\ Files/DataProcessing.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/DataProcessing.d" -MT"Source\ Files/DataProcessing.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/PatternCalls.o: ../Source\ Files/PatternCalls.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/PatternCalls.d" -MT"Source\ Files/PatternCalls.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/main.o: ../Source\ Files/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/main.d" -MT"Source\ Files/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


