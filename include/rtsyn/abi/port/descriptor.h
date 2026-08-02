/**
 * @file rtsyn/abi/port.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn ABI Port.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_ABI_PORT_DESCRIPTOR_H
#define RTSYN_ABI_PORT_DESCRIPTOR_H

#include <stdint.h>

#include "rtsyn/abi/port/direction.h"
#include "rtsyn/abi/value.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rtsyn_abi_port_descriptor_s {
    const char *name;
    rtsyn_abi_value_type_t value_type;
    rtsyn_abi_port_direction_t direction;
} rtsyn_abi_port_descriptor_t;

bool
rtsyn_abi_port_descriptor_is_valid(const rtsyn_abi_port_descriptor_t *descriptor);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_ABI_PORT_DESCRIPTOR_H */
