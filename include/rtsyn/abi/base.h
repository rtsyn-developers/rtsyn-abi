/**
 * @file rtsyn/abi/base.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn ABI Base.
 *
 * This file contains the base defines needed by the ABI.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_ABI_BASE_H
#define RTSYN_ABI_BASE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RTSYN_ABI_VERSION 1u

#if defined(_WIN32)
#define RTSYN_ABI_EXPORT __declspec(dllexport)
#define RTSYN_ABI_CALL   __cdecl
#else
#define RTSYN_ABI_EXPORT __attribute__((visibility("default")))
#define RTSYN_ABI_CALL
#endif

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_ABI_BASE_H */
