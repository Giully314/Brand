add_library(brand_core)
target_sources(brand_core
    PUBLIC FILE_SET CXX_MODULES FILES
    core.cppm
    corefunction.cppm
    corempl.cppm
    coretypetraits.cppm
    coreconcepts.cppm
    )