#include "rtsyn/abi/node.h"

bool
rtsyn_abi_node_type_is_valid(rtsyn_abi_node_type_t node_type)
{
    return node_type < RTSYN_ABI_NODE_COUNT;
}

bool
rtsyn_abi_node_descriptor_is_valid(const rtsyn_abi_node_descriptor_t *descriptor)
{
    if (!descriptor || !descriptor->name || descriptor->name[0] == '\0'
        || !rtsyn_abi_node_type_is_valid(descriptor->node_type)
        || (descriptor->port_count > 0 && !descriptor->ports)
        || (descriptor->param_count > 0 && !descriptor->params)
        || (descriptor->state_count > 0 && !descriptor->states) || !descriptor->callbacks.create
        || !descriptor->callbacks.start || !descriptor->callbacks.process
        || !descriptor->callbacks.stop || !descriptor->callbacks.destroy)
    {
        return false;
    }

    for (uint32_t index = 0; index < descriptor->port_count; index++)
    {
        if (!rtsyn_abi_port_descriptor_is_valid(&descriptor->ports[index]))
        {
            return false;
        }
    }

    for (uint32_t index = 0; index < descriptor->param_count; index++)
    {
        if (!rtsyn_abi_node_param_descriptor_is_valid(&descriptor->params[index]))
        {
            return false;
        }
    }

    for (uint32_t index = 0; index < descriptor->state_count; index++)
    {
        if (!rtsyn_abi_node_state_descriptor_is_valid(&descriptor->states[index]))
        {
            return false;
        }
    }

    return true;
}
