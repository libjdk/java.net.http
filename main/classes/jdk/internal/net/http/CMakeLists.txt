#machine generated

add_subdirectory("common")
add_subdirectory("frame")
add_subdirectory("hpack")
add_subdirectory("websocket")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.jdk.internal.net.http_SRCS)
file(GLOB classes.jdk.internal.net.http_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.jdk.internal.net.http_HEADERS}) 
list(LENGTH classes.jdk.internal.net.http_SRCS classes.jdk.internal.net.http_SRCS_LENGTH)
if(classes.jdk.internal.net.http_SRCS_LENGTH)
	add_library(classes.jdk.internal.net.http OBJECT "${classes.jdk.internal.net.http_SRCS}" "${classes.jdk.internal.net.http_HEADERS}")
	jcpp_enable_bigobj(classes.jdk.internal.net.http)
endif()