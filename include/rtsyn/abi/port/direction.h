/**
 * @file rtsyn/abi/port/direction.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Public header file for the RTSyn Port Direction.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_ABI_PORT_DIRECTION_H
#define RTSYN_ABI_PORT_DIRECTION_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Identifiers for RTSyn Port Direction.
 */
typedef enum rtsyn_abi_port_direction_e : uint32_t {
    RTSYN_ABI_PORT_DIRECTION_IN = 0,                                   /**< Input port. */
    RTSYN_ABI_PORT_DIRECTION_OUT,                                      /**< Output port. */
    RTSYN_ABI_PORT_DIRECTION_COUNT,                                    /**< Number of types. */
    RTSYN_ABI_PORT_DIRECTION_INVALID = RTSYN_ABI_PORT_DIRECTION_COUNT, /**< Invalid port type. */
} rtsyn_abi_port_direction_t;

/**
 * @brief Validator for the direction type of the RTSyn Port direction.
 *
 * @param port_direction The port direction.
 * @return true if valid, false otherwhise.
 */
bool
rtsyn_abi_port_direction_is_valid(rtsyn_abi_port_direction_t direction);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_ABI_PORT_DIRECTION_H */
