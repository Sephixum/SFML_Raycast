include(FetchContent)

# SFML

find_package(SFML COMPONENTS graphics window system)
if(NOT SFML_FOUND)
  message(
    "SFML was not found on your system.\nIt will be downloaded from it's github repo."
  )
  fetchcontent(sfml GIT_REPOSITORY "https://github.com/SFML/SFML.git" GIT_TAG
               2.6.0)
  add_subdirectory(SFML)
endif()

# Dear ImGui
find_package(imgui)
if(NOT imgui_FOUND)
  FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG 35b1148efb839381b84de9290d9caf0b66ad7d03
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  FetchContent_MakeAvailable(imgui)
endif()

# ImGui-SFML
find_package(ImGui-SFML)
if(ImGui-SFML_FOUND)
  message(STATUS "Found ImGui-SFML")
else()
  FetchContent_Declare(
    ImGui-SFML
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml
    GIT_TAG 82dc2033e51b8323857c3ae1cf1f458b3a933c35
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  add_subdirectory(ImGui-SFML)
endif()
