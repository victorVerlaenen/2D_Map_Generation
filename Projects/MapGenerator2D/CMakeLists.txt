add_executable(
MapGenerator2D
main.cpp
MapGenerator2D.h
MapGenerator2D.cpp
 "Map.h" "Map.cpp")

set_target_properties(MapGenerator2D PROPERTIES FOLDER Games)

target_include_directories(MapGenerator2D PUBLIC ${GAME_INCLUDE_PATH})
target_link_libraries(MapGenerator2D PUBLIC Core)
target_link_libraries(MapGenerator2D PUBLIC OpenGL::GL)

source_group(
	"Game code"
	FILES MapGenerator2D.h MapGenerator2D.cpp main.cpp
)

# create a list of files to copy
IF( WIN32 )
get_filename_component(SDL2_LIBRARY_PATH ${SDL2_LIBRARY} DIRECTORY)
get_filename_component(SDL2_TTF_LIBRARY_PATH ${SDL2_TTF_LIBRARY} DIRECTORY) 
get_filename_component(SDL2_IMAGE_LIBRARY_PATH ${SDL2_IMAGE_LIBRARY} DIRECTORY) 
get_filename_component(SDL2_MIXER_LIBRARY_PATH ${SDL2_MIXER_LIBRARY} DIRECTORY) 

set( THIRD_PARTY_DLLS
   "${SDL2_LIBRARY_PATH}/SDL2.dll"
   "${SDL2_TTF_LIBRARY_PATH}/SDL2_ttf.dll"
   "${SDL2_TTF_LIBRARY_PATH}/libfreetype-6.dll"
   "${SDL2_IMAGE_LIBRARY_PATH}/SDL2_Image.dll"
   "${SDL2_IMAGE_LIBRARY_PATH}/zlib1.dll"
   "${SDL2_IMAGE_LIBRARY_PATH}/libjpeg-9.dll"
   "${SDL2_IMAGE_LIBRARY_PATH}/libpng16-16.dll"
	"${SDL2_IMAGE_LIBRARY_PATH}/libtiff-5.dll"
	"${SDL2_IMAGE_LIBRARY_PATH}/libwebp-7.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/SDL2_mixer.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/libFLAC-8.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/libmodplug-1.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/libmpg123-0.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/libogg-0.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/libopus-0.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/libopusfile-0.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/libvorbis-0.dll"
	"${SDL2_MIXER_LIBRARY_PATH}/libvorbisfile-3.dll"
)

# do the copying
foreach( file_i ${THIRD_PARTY_DLLS})
    add_custom_command(
    TARGET MapGenerator2D
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
     -E copy_if_different ${file_i} $<TARGET_FILE_DIR:MapGenerator2D>)
endforeach( file_i )
ENDIF()

foreach( file_i ${THIRD_PARTY_DLLS})
    install(FILES ${file_i} DESTINATION bin)
endforeach( file_i )

add_custom_command(TARGET MapGenerator2D POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_CURRENT_SOURCE_DIR}/Resources/ $<TARGET_FILE_DIR:MapGenerator2D>)

install(TARGETS MapGenerator2D DESTINATION bin)