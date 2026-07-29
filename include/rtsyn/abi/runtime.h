/**
 * @file rtsyn/abi/runtime.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn ABI Runtime.
 *
 * Defines the basic types.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_ABI_RUNTIME_H
#define RTSYN_ABI_RUNTIME_H

#include <stdbool.h>
#include <stdint.h>

#include "rtsyn/abi/base.h"
#include "rtsyn/abi/status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rtsyn_abi_runtime_context_s rtsyn_abi_runtime_context_t;

/**
 * @brief Stages for the runtime cycle.
 */
typedef enum rtsyn_abi_runtime_cycle_stage_e : uint32_t {
    RTSYN_RUNTIME_CYCLE_STAGE_IMMEDIATE = 0, /**< Exeuted immediately after input acquisition.*/
    RTSYN_RUNTIME_CYCLE_STAGE_INTERMEDIATE,  /**< Executed between device executions. */
    RTSYN_RUNTIME_CYCLE_STAGE_TERMINAL,      /**< Executed after processing and before output. */
    RTSYN_RUNTIME_CYCLE_STAGE_OBSERVATION,   /**< Exectued after the cycle for observation only. */
    RTSYN_RUNTIME_CYCLE_STAGE_COUNT,         /**< Number of cycle stages. */
    RTSYN_RUNTIME_CYCLE_STAGE_INVALID = RTSYN_RUNTIME_CYCLE_STAGE_COUNT, /**< Invalid stage. */
} rtsyn_abi_runtime_cycle_stage_t;

typedef struct rtsyn_abi_runtime_api_s {
    rtsyn_abi_status_t(RTSYN_ABI_CALL *read)(const rtsyn_abi_runtime_context_t *context,
                                             uint32_t port_index, void *out_value);

    rtsyn_abi_status_t(RTSYN_ABI_CALL *write)(const rtsyn_abi_runtime_context_t *context,
                                              uint32_t port_index, const void *value);

    bool(RTSYN_ABI_CALL *is_port_connected)(const rtsyn_abi_runtime_context_t *context,
                                            uint32_t port_index);

} rtsyn_abi_runtime_api_t;

struct rtsyn_abi_runtime_context_s {
    uint64_t cycle_index;
    uint64_t monotonic_time_ns;
    uint64_t period_ns;
    rtsyn_abi_runtime_cycle_stage_t
        cycle_stage; /*< Contains the stage of the phase, this is usefull or the devices,
                             which are called 2 times and must process different depending on the
                             stage */

    const rtsyn_abi_runtime_api_t *api;

    /*
     * Private RTSyn pointer.
     * The module must never dereference this.
     */
    const void *host_context;
};

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_ABI_RUNTIME_H */
