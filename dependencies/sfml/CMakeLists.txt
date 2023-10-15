message(STATUS "Fetching SFML...")

set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)

FetchContent_MakeAvailable(sfml)
