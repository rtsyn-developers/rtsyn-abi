/**
 * @file rtsyn/abi/node.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn ABI Node.
 *
 * This file contains the node defines needed by the ABI.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_ABI_NODE_H
#define RTSYN_ABI_NODE_H

#include <stdint.h>

#include "rtsyn/abi/base.h"
#include "rtsyn/abi/node/param.h"
#include "rtsyn/abi/node/state.h"
#include "rtsyn/abi/port.h"
#include "rtsyn/abi/runtime.h"
#include "rtsyn/abi/status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum rtsyn_abi_node_type_e : uint32_t {
    RTSYN_ABI_NODE_PLUGIN = 0, /**< Plugin execution. */
    RTSYN_ABI_NODE_DEVICE,     /**< Device execution. */
    RTSYN_ABI_NODE_TRANSMISOR, /**< Propagates the runtime data through the
                                                transmisor. */
    RTSYN_ABI_NODE_COUNT,      /**< Number of node type. */
    RTSYN_ABI_NODE_INVALID,    /**< Invalid or uninitialized node. */
} rtsyn_abi_node_type_t;

typedef struct rtsyn_abi_node_callbacks_s {
    rtsyn_abi_status_t(RTSYN_ABI_CALL *create)(void **out_instance);

    rtsyn_abi_status_t(RTSYN_ABI_CALL *set_param)(void *instance, uint32_t param_index,
                                                  const void *value);

    rtsyn_abi_status_t(RTSYN_ABI_CALL *read_state)(const void *instance, uint32_t state_index,
                                                   void *out_value);

    rtsyn_abi_status_t(RTSYN_ABI_CALL *start)(void *instance);

    rtsyn_abi_status_t(RTSYN_ABI_CALL *process)(void *instance,
                                                const rtsyn_abi_runtime_context_t *context);

    rtsyn_abi_status_t(RTSYN_ABI_CALL *stop)(void *instance);

    void(RTSYN_ABI_CALL *destroy)(void *instance);
} rtsyn_abi_node_callbacks_t;

typedef struct rtsyn_abi_node_descriptor_s {
    const char *name;

    rtsyn_abi_node_type_t node_type;
    uint32_t port_count;
    const rtsyn_abi_port_descriptor_t *ports;

    uint32_t param_count;
    const rtsyn_abi_param_descriptor_t *params;

    uint32_t state_count;
    const rtsyn_abi_state_descriptor_t *states;

    rtsyn_abi_node_callbacks_t callbacks;
} rtsyn_abi_node_descriptor_t;

bool
rtsyn_abi_node_type_is_valid(rtsyn_abi_node_type_t node_type);

bool
rtsyn_abi_node_descriptor_is_valid(const rtsyn_abi_node_descriptor_t *descriptor);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_ABI_NODE_H */
