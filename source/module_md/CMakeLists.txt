add_library(
    md
    OBJECT
    MD_func.cpp
    run_md_classic.cpp
    verlet.cpp
    NVE.cpp
    MSST.cpp
    NVT_ADS.cpp
    NVT_NHC.cpp
    FIRE.cpp
    Langevin.cpp
)

if(ENABLE_COVERAGE)
  add_coverage(md)
endif()

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
