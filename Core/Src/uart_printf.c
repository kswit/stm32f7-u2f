#include "stm32f7xx_hal.h"
#include "uart_printf.h"
#include <stdio.h>
#include <stdarg.h>

extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart1;
void uart_printf(const char *fmt, ...)
{
    char buffer[512];
    int ret;
    va_list args;
    va_start(args, fmt);
    ret = vsnprintf(buffer, sizeof(buffer)-1, fmt, args);
    va_end(args);
    if (ret > 0)
    {
        if(buffer[ret-1] == '\n')
            buffer[ret++] = '\r';
        HAL_UART_Transmit(&huart3, (uint8_t*)buffer, ret, 0xFFFF);
        //HAL_UART_Transmit(&huart1, (uint8_t*)buffer, ret, 0xFFFF);
        //HAL_UART_Transmit(&huart1, (uint8_t*)buffer, ret, 0xFFFF);
    }
}
