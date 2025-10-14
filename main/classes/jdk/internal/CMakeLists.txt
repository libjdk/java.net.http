#machine generated

add_subdirectory("net")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.jdk.internal_SRCS)
file(GLOB classes.jdk.internal_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.jdk.internal_HEADERS}) 
list(LENGTH classes.jdk.internal_SRCS classes.jdk.internal_SRCS_LENGTH)
if(classes.jdk.internal_SRCS_LENGTH)
	add_library(classes.jdk.internal OBJECT "${classes.jdk.internal_SRCS}" "${classes.jdk.internal_HEADERS}")
	jcpp_enable_bigobj(classes.jdk.internal)
endif()