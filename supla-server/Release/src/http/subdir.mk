################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/http/cJSON.c \
../src/http/cJSON_Utils.c 

CPP_SRCS += \
../src/http/trivialhttp.cpp \
../src/http/trivialhttps.cpp 

OBJS += \
./src/http/cJSON.o \
./src/http/cJSON_Utils.o \
./src/http/trivialhttp.o \
./src/http/trivialhttps.o 

C_DEPS += \
./src/http/cJSON.d \
./src/http/cJSON_Utils.d 

CPP_DEPS += \
./src/http/trivialhttp.d \
./src/http/trivialhttps.d 


# Each subdirectory must supply rules for building sources it contributes
src/http/%.o: ../src/http/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -D__BCRYPT=1 -D__OPENSSL_TOOLS=1 -I$(SSLDIR)/include -I../src -I../src/user -I../src/device -I../src/client -O3 -Wall -c -fmessage-length=0 -fstack-protector-all -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/http/%.o: ../src/http/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__BCRYPT=1 -D__OPENSSL_TOOLS=1 -I/usr/include/mysql -I../src/client -I../src/user -I../src/device -I../src -I$(SSLDIR)/include -O3 -Wall -c -fmessage-length=0 -fstack-protector-all -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

