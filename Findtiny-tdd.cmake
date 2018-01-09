find_path(tiny-tdd_INCLUDE_DIR ide_printer.h)
find_library(tiny-tdd_LIBRARY tiny-tdd)
mark_as_advanced(tiny-tdd_INCLUDE_DIR)

include(find_package(PackageHandleStandardArgs)
find_package_handle_standard_args(tiny-tdd REQUIRED_VARS tiny-tdd_INCLUDE_DIR)

if(tiny-tdd_FOUND AND NOT TARGET tiny-tdd::tiny-tdd)
    add_library(tiny-tdd UNKNOWN IMPORTED)
    set_target_properties(tiny-tdd:tiny-tdd PROPERTIES
    IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
    INTERFACE_INCLUDE_DIRECTORIES "${tiny-tdd_INCLUDE_DIR}")
endif()