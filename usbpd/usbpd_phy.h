#pragma once

#include <stdint.h>

typedef void (* pd_callbackRecv)(uint8_t * msg);
typedef void (* pd_callbackSent)();

void pd_initPhyLayer(pd_callbackRecv onMessageCallback, pd_callbackSent onSentCallback);
void pd_transmitMessage(uint8_t * msg, uint8_t sz);