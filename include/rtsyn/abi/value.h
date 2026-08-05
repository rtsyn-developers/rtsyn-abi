/**
 * @file rtsyn/abi/value.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Public header file for the RTSyn ABI Value.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_ABI_VALUE_H
#define RTSYN_ABI_VALUE_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Identifiers for RTSyn Port Value.
 */
typedef enum rtsyn_abi_value_type_e : uint32_t {
    RTSYN_ABI_VALUE_F32 = 0,
    RTSYN_ABI_VALUE_F64,
    // RTSYN_ABI_VALUE_I32,
    RTSYN_ABI_VALUE_I64,
    // RTSYN_ABI_VALUE_U32,
    RTSYN_ABI_VALUE_U64,
    RTSYN_ABI_VALUE_STRING,
    RTSYN_ABI_VALUE_COUNT,
    RTSYN_ABI_VALUE_INVALID = RTSYN_ABI_VALUE_COUNT,
} rtsyn_abi_value_type_t;

bool
rtsyn_abi_value_is_valid(rtsyn_abi_value_type_t value_type);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_ABI_VALUE_H */
