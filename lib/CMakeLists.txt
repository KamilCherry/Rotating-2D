
# set (link_libs SDL-release-2.26.5)
# foreach (q IN LISTS ${link_libs})
#   add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${q})
# endforeach()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SDL-release-2.28.0)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SDL_image-release-2.6.3)

set(libs "SDL2")
target_link_libraries(${EXE_NAME} PUBLIC ${libs})

