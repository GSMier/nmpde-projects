
cmake_minimum_required(VERSION 3.13.4)

find_package(deal.II REQUIRED
        HINTS ${DEAL_II_DIR} $ENV{DEAL_II_DIR}
        PATHS /u/sw/toolchains/gcc-glibc/11.2.0/pkgs/dealii/9.5.1
)

deal_ii_initialize_cached_variables()

project(nmpde_projects LANGUAGES CXX)

add_executable(proj-10 src/main.cpp)

deal_ii_setup_target(proj-10)
