#include "rtsyn/abi/node/param.h"

bool
rtsyn_abi_node_param_descriptor_is_valid(const rtsyn_abi_param_descriptor_t *descriptor)
{
    return (descriptor && descriptor->name && descriptor->description
            && rtsyn_abi_value_is_valid(descriptor->value_type));
}
