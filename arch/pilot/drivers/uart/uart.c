/*
 * Copyright (c) 2003, Lucas Mendes <lmendes@netbsd.com.br>
 * Copyright (c) 2003, Marcelo Samsoniuk <marcelos@bsi.com.br>
 *      All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the liquidfire distribution.
 */

#include <port/uart.h>

	struct EZ328UART *uart0=(struct EZ328UART *)EZ328UARTADDR;

void UARTputc(char c) {

	uart0->UTX.data=c;

	if(c=='\n') uart0->UTX.data='\r';
}
