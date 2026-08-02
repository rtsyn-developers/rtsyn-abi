#include "rtsyn/abi/port/direction.h"

bool
rtsyn_abi_port_direction_is_valid(rtsyn_abi_port_direction_t direction)
{
    return direction < RTSYN_ABI_PORT_DIRECTION_COUNT;
}
