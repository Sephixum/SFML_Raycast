include(FetchContent)

# SFML
find_package(
  SFML
  COMPONENTS graphics window system
  REQUIRED)

if(NOT SFML_FOUND)
  FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    URL_MD5 2c4438b3e5b2d81a6e626ecf72bf75be
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  add_subdirectory(sfml)
endif()
