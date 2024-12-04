file(GLOB_RECURSE ALLFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_executable(aoc_2024_day_02 ${ALLFILES})

target_link_libraries(aoc_2024_day_02 PRIVATE
        Catch2::Catch2WithMain)

target_include_directories(aoc_2024_day_02 PUBLIC ${CMAKE_SOURCE_DIR})
