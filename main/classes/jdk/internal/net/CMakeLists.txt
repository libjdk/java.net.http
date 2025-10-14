#machine generated

add_subdirectory("http")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.jdk.internal.net_SRCS)
file(GLOB classes.jdk.internal.net_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.jdk.internal.net_HEADERS}) 
list(LENGTH classes.jdk.internal.net_SRCS classes.jdk.internal.net_SRCS_LENGTH)
if(classes.jdk.internal.net_SRCS_LENGTH)
	add_library(classes.jdk.internal.net OBJECT "${classes.jdk.internal.net_SRCS}" "${classes.jdk.internal.net_HEADERS}")
	jcpp_enable_bigobj(classes.jdk.internal.net)
endif()