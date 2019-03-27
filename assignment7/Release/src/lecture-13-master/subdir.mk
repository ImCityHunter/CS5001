################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lecture-13-master/issn.c \
../src/lecture-13-master/issn_test.c \
../src/lecture-13-master/journal.c \
../src/lecture-13-master/journal_test.c \
../src/lecture-13-master/main_v1.c \
../src/lecture-13-master/publisher.c \
../src/lecture-13-master/publisher_test.c \
../src/lecture-13-master/test_all.c 

OBJS += \
./src/lecture-13-master/issn.o \
./src/lecture-13-master/issn_test.o \
./src/lecture-13-master/journal.o \
./src/lecture-13-master/journal_test.o \
./src/lecture-13-master/main_v1.o \
./src/lecture-13-master/publisher.o \
./src/lecture-13-master/publisher_test.o \
./src/lecture-13-master/test_all.o 

C_DEPS += \
./src/lecture-13-master/issn.d \
./src/lecture-13-master/issn_test.d \
./src/lecture-13-master/journal.d \
./src/lecture-13-master/journal_test.d \
./src/lecture-13-master/main_v1.d \
./src/lecture-13-master/publisher.d \
./src/lecture-13-master/publisher_test.d \
./src/lecture-13-master/test_all.d 


# Each subdirectory must supply rules for building sources it contributes
src/lecture-13-master/%.o: ../src/lecture-13-master/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


