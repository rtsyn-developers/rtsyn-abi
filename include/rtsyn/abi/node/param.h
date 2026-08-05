/**
 * @file rtsyn/abi/node/param.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Public header file for the RTSyn ABI Node Param.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_ABI_NODE_PARAM_H
#define RTSYN_PORT_ABI_NODE_PARAM_H

#include <stdbool.h>

#include "rtsyn/abi/value.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rtsyn_abi_param_descriptor_s {
    const char *name;
    const char *description;
    rtsyn_abi_value_type_t value_type;
} rtsyn_abi_param_descriptor_t;

bool
rtsyn_abi_node_param_descriptor_is_valid(const rtsyn_abi_param_descriptor_t *descriptor);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_PORT_ABI_NODE_PARAM_H */
