/**
 * @file rtsyn/abi/status.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn ABI Status.
 *
 * Defines the basic types.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_ABI_STATUS_H
#define RTSYN_ABI_STATUS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum rtsyn_abi_status_e : int32_t {
    RTSYN_ABI_STATUS_OK = 0,
    RTSYN_ABI_STATUS_ERROR = -1,
    RTSYN_ABI_STATUS_INVALID_ARGUMENT = -2,
    RTSYN_ABI_STATUS_UNSUPPORTED_VERSION = -3,
    RTSYN_ABI_STATUS_NOT_FOUND = -4,
    RTSYN_ABI_STATUS_TYPE_MISMATCH = -5,
    RTSYN_ABI_STATUS_INVALID_STATE = -6
} rtsyn_abi_status_t;

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_ABI_STATUS_H */
