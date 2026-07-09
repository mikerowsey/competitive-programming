option(CP_ENABLE_CLANG_TIDY "Enable clang-tidy during builds" OFF)

if(CP_ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)

    if(CLANG_TIDY_EXE)
        set(CP_CLANG_TIDY_ARGS "")

        if(APPLE)
            set(CP_CLANG_TIDY_SYSROOT "")

            if(DEFINED CMAKE_OSX_SYSROOT AND NOT CMAKE_OSX_SYSROOT STREQUAL "")
                set(CP_CLANG_TIDY_SYSROOT "${CMAKE_OSX_SYSROOT}")
            elseif(DEFINED ENV{SDKROOT} AND NOT "$ENV{SDKROOT}" STREQUAL "")
                set(CP_CLANG_TIDY_SYSROOT "$ENV{SDKROOT}")
            else()
                execute_process(
                    COMMAND xcrun --show-sdk-path
                    OUTPUT_VARIABLE CP_CLANG_TIDY_SYSROOT
                    OUTPUT_STRIP_TRAILING_WHITESPACE
                    ERROR_QUIET
                    RESULT_VARIABLE CP_XCRUN_RESULT
                )

                if(NOT CP_XCRUN_RESULT EQUAL 0)
                    set(CP_CLANG_TIDY_SYSROOT "")
                endif()
            endif()

            if(NOT CP_CLANG_TIDY_SYSROOT STREQUAL "")
                list(APPEND CP_CLANG_TIDY_ARGS "--extra-arg=-isysroot" "--extra-arg=${CP_CLANG_TIDY_SYSROOT}")
            else()
                message(WARNING "Could not determine macOS sysroot for clang-tidy; proceeding without explicit -isysroot")
            endif()
        endif()

        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
        if(CP_CLANG_TIDY_ARGS)
            list(APPEND CMAKE_CXX_CLANG_TIDY ${CP_CLANG_TIDY_ARGS})
        endif()
    else()
        message(WARNING "CP_ENABLE_CLANG_TIDY is ON, but clang-tidy was not found; continuing without it")
    endif()
endif()
