add_library(brand)
target_sources(brand
    PUBLIC FILE_SET CXX_MODULES FILES
    brand.cppm
    )

add_subdirectory(core)
target_link_libraries(brand PUBLIC brand_core)