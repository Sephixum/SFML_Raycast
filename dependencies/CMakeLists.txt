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

# Dear ImGui
FetchContent_Declare(
  imgui
  # GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  # GIT_TAG 35b1148efb839381b84de9290d9caf0b66ad7d03 # 1.82
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(imgui)

# ImGui-SFML
FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml
  # GIT_TAG 82dc2033e51b8323857c3ae1cf1f458b3a933c35 # 2.3
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
add_subdirectory(imgui-sfml)
