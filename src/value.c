#include "rtsyn/abi/value.h"

bool
rtsyn_abi_value_is_valid(rtsyn_abi_value_type_t value_type)
{
    return value_type < RTSYN_ABI_VALUE_COUNT;
}
