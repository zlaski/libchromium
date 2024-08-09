#pragma once 
#define __LIBCHROMIUM_MODS__

////////////////////////

#define NOMINMAX
#define _WINSOCKAPI_

#define __builtin_unreachable() __assume(0)
#define _CRT_RAND_S

#pragma warning (disable: 4244 4715) 

#define __LIBCHROMIUM_LOG__  std::cerr

#define NOTREACHED_IN_MIGRATION() __LIBCHROMIUM_LOG__

#define LOG_IS_ON() 0
#define LOG(fd) __LIBCHROMIUM_LOG__
#define DLOG(fd) __LIBCHROMIUM_LOG__
#define DPLOG(fd) __LIBCHROMIUM_LOG__
#define DPLOG_IF(s, c) __LIBCHROMIUM_LOG__
#define PLOG(fd) __LIBCHROMIUM_LOG__
#define VPLOG(fd) __LIBCHROMIUM_LOG__

#define DCHECK_IS_ON() 0
#define DCHECK(expr) __LIBCHROMIUM_LOG__
#define DCHECK_EQ(expr1, expr2)
#define DCHECK_GE(expr1, expr2)
#define DCHECK_GT(expr1, expr2)
#define DCHECK_LE(expr1, expr2)
#define DCHECK_LT(expr1, expr2)
#define DCHECK_NE(expr1, expr2) __LIBCHROMIUM_LOG__

#define DPCHECK(expr) __LIBCHROMIUM_LOG__

#define CHECK(expr, ...)
#define CHECK_EQ(expr1, expr2)
#define CHECK_GT(expr1, expr2)
#define CHECK_LE(expr1, expr2)
#define CHECK_LT(expr1, expr2)
#define CHECK_NE(expr1, expr2)

#define BUILDFLAG_INTERNAL_CLANG_PROFILING() 0
#define BUILDFLAG_INTERNAL_DCHECK_IS_CONFIGURABLE() 0
#define BUILDFLAG_INTERNAL_ENABLE_BANNED_BASE_FEATURE_PREFIX() 0
#define BUILDFLAG_INTERNAL_ENABLE_BASE_TRACING() 0
#define BUILDFLAG_INTERNAL_ENABLE_COMMANDLINE_SEQUENCE_CHECKS() 0
#define BUILDFLAG_INTERNAL_ENABLE_LOG_ERROR_NOT_REACHED() 0
#define BUILDFLAG_INTERNAL_EXPENSIVE_DCHECKS_ARE_ON() 0
#define BUILDFLAG_INTERNAL_IS_CHROMEOS_ASH() 0
#define BUILDFLAG_INTERNAL_IS_CHROMEOS_LACROS() 0
#define BUILDFLAG_INTERNAL_PROTECTED_MEMORY_ENABLED() 0
#define BUILDFLAG_INTERNAL_USE_FUZZING_ENGINE() 0

#define PA_BUILDFLAG_INTERNAL_ASSERT_CPP_20() 0
#define PA_BUILDFLAG_INTERNAL_DCHECKS_ARE_ON() 0
#define PA_BUILDFLAG_INTERNAL_ENABLE_BACKUP_REF_PTR_INSTANCE_TRACER() 0
#define PA_BUILDFLAG_INTERNAL_ENABLE_BACKUP_REF_PTR_SLOW_CHECKS() 0
#define PA_BUILDFLAG_INTERNAL_ENABLE_BACKUP_REF_PTR_SUPPORT() 0
#define PA_BUILDFLAG_INTERNAL_ENABLE_DANGLING_RAW_PTR_CHECKS() 0
#define PA_BUILDFLAG_INTERNAL_ENABLE_POINTER_ARITHMETIC_TRAIT_CHECK() 0
#define PA_BUILDFLAG_INTERNAL_ENABLE_POINTER_COMPRESSION() 0
#define PA_BUILDFLAG_INTERNAL_ENABLE_SHADOW_METADATA_FOR_64_BITS_POINTERS() 0
#define PA_BUILDFLAG_INTERNAL_HAS_MEMORY_TAGGING() 0
#define PA_BUILDFLAG_INTERNAL_IS_CHROMEOS() 0
#define PA_BUILDFLAG_INTERNAL_RAW_PTR_ZERO_ON_CONSTRUCT() 0
#define PA_BUILDFLAG_INTERNAL_RAW_PTR_ZERO_ON_DESTRUCT() 0
#define PA_BUILDFLAG_INTERNAL_RAW_PTR_ZERO_ON_MOVE() 0
#define PA_BUILDFLAG_INTERNAL_USE_ALLOCATOR_SHIM() 0
#define PA_BUILDFLAG_INTERNAL_USE_ASAN_BACKUP_REF_PTR() 0
#define PA_BUILDFLAG_INTERNAL_USE_PARTITION_ALLOC() 0
#define PA_BUILDFLAG_INTERNAL_USE_PARTITION_ALLOC_AS_MALLOC() 0
#define PA_BUILDFLAG_INTERNAL_USE_RAW_PTR_ASAN_UNOWNED_IMPL() 0
#define PA_BUILDFLAG_INTERNAL_USE_RAW_PTR_BACKUP_REF_IMPL() 0
#define PA_BUILDFLAG_INTERNAL_USE_RAW_PTR_HOOKABLE_IMPL() 0

#ifdef _WIN64
#define PA_BUILDFLAG_INTERNAL_HAS_64_BIT_POINTERS() 1
#else
#define PA_BUILDFLAG_INTERNAL_HAS_64_BIT_POINTERS() 0
#endif

#define RAW_PTR_EXCLUSION

#define FORWARD_DECLARE_TEST(t1, t2)
#define FRIEND_TEST(test_case_name, test_name) \
  friend class test_case_name##_##test_name##_Test
#define FRIEND_TEST_ALL_PREFIXES(t1, t2)

#define SCOPED_FILE_TRACE_WITH_SIZE(file, size)
#define SCOPED_FILE_TRACE(file)

//#define QueryUnbiasedInterruptTimePrecise(t) QueryUnbiasedInterruptTime(t)

#include <iostream>

#include "base/allocator/partition_allocator/src/partition_alloc/build_config.h"
#include "build/build_config.h"  // BUILDFLAG(...)

namespace base {
    class Location { };
    extern Location FROM_HERE;

    enum class BlockingType { MAY_BLOCK, WILL_BLOCK };

    class ScopedBlockingCall {
    public:
      ScopedBlockingCall(const Location& from_here, BlockingType blocking_type);
      ~ScopedBlockingCall();
    };

    int RandInt(int min, int max);
}

