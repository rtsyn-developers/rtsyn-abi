
#include "rtsyn/abi/port/descriptor.h"

bool
rtsyn_abi_port_descriptor_is_valid(const rtsyn_abi_port_descriptor_t *descriptor)
{
    return (descriptor && descriptor->name && rtsyn_abi_value_is_valid(descriptor->value_type)
            && rtsyn_abi_port_direction_is_valid(descriptor->direction));
}
