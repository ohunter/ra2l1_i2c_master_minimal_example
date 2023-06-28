set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(CPU_FLAGS "-mcpu=${CMAKE_SYSTEM_PROCESSOR} -mthumb")

set(C_FLAGS "-Wall -Wpedantic -Wextra -Wsuggest-attribute=noreturn -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -nostdlib")
set(CXX_FLAGS "${C_FLAGS} -fno-exceptions -fno-rtti -fconcepts-diagnostics-depth=5")

# Toolchain settings
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_AS arm-none-eabi-as)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(CMAKE_SIZE arm-none-eabi-size)
set(RANLIB arm-none-eabi-ranlib)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_C_FLAGS "${CPU_FLAGS} ${SPEC_FLAGS} ${C_FLAGS}" CACHE INTERNAL "C Compiler Flags")
set(CMAKE_CXX_FLAGS "${CPU_FLAGS} ${SPEC_FLAGS} ${CXX_FLAGS}" CACHE INTERNAL "CXX Compiler Flags")
set(CMAKE_ASM_FLAGS "${CPU_FLAGS} ${ASM_FLAGS} -x assembler-with-cpp" CACHE INTERNAL "ASM Compiler Flags")

set(CMAKE_C_FLAGS_DEBUG "-g -ggdb3" CACHE INTERNAL "C Debug Compiler Flags")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb3" CACHE INTERNAL "CXX Debug Compiler Flags")
set(CMAKE_ASM_FLAGS_DEBUG "-g -ggdb3" CACHE INTERNAL "ASM Debug Compiler Flags")

set(CMAKE_C_FLAGS_RELEASE "-O3 -Werror" CACHE INTERNAL "C Release Compiler Flags")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Werror" CACHE INTERNAL "CXX Release Compiler Flags")
set(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "ASM Release Compiler Flags")

set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> qc <TARGET> <LINK_FLAGS> <OBJECTS>" CACHE INTERNAL "")
set(CMAKE_CXX_ARCHIVE_FINISH "${RANLIB} <TARGET>" CACHE INTERNAL "")

# Using this it allows for a simple declaration of linking groups by using `$<LINK_GROUP:CROSS_REFS,lib1,lib2>`
set(GCC_LINKER_GROUP_ARCHIVES
    "LINKER:--start-group"
    "LINKER:--end-group"
)

# Enable the use of this option for C, CXX, and ASM targets
set(CMAKE_C_LINK_GROUP_USING_CROSS_REFS_SUPPORTED TRUE)
set(CMAKE_CXX_LINK_GROUP_USING_CROSS_REFS_SUPPORTED TRUE)
set(CMAKE_ASM_LINK_GROUP_USING_CROSS_REFS_SUPPORTED TRUE)
set(CMAKE_C_LINK_GROUP_USING_CROSS_REFS ${GCC_LINKER_GROUP_ARCHIVES})
set(CMAKE_CXX_LINK_GROUP_USING_CROSS_REFS ${GCC_LINKER_GROUP_ARCHIVES})
set(CMAKE_ASM_LINK_GROUP_USING_CROSS_REFS ${GCC_LINKER_GROUP_ARCHIVES})

# Windows loves to set the extension of executables to ".exe"
# With these parameters I hope to circumvent this
set(CMAKE_EXECUTABLE_SUFFIX ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_ASM ".elf")
