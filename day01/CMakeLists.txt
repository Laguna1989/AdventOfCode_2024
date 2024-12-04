file(GLOB_RECURSE ALLFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_executable(aoc_2024_day_01 ${ALLFILES})

target_link_libraries(aoc_2024_day_01 PRIVATE
        Catch2::Catch2WithMain)

target_include_directories(aoc_2024_day_01 PUBLIC ${CMAKE_SOURCE_DIR})
