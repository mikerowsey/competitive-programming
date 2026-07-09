set(CMAKE_SYSTEM_NAME Darwin)

if(NOT DEFINED CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
endif()

if(NOT DEFINED CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")
endif()

if(NOT DEFINED CMAKE_OSX_SYSROOT OR CMAKE_OSX_SYSROOT STREQUAL "")
    execute_process(
        COMMAND xcrun --show-sdk-path
        OUTPUT_VARIABLE _sdkroot
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )

    if(_sdkroot)
        set(CMAKE_OSX_SYSROOT "${_sdkroot}" CACHE STRING "" FORCE)
    endif()
endif()
