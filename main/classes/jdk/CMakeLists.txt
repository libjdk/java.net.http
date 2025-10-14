#machine generated

add_subdirectory("internal")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.jdk_SRCS)
file(GLOB classes.jdk_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.jdk_HEADERS}) 
list(LENGTH classes.jdk_SRCS classes.jdk_SRCS_LENGTH)
if(classes.jdk_SRCS_LENGTH)
	add_library(classes.jdk OBJECT "${classes.jdk_SRCS}" "${classes.jdk_HEADERS}")
	jcpp_enable_bigobj(classes.jdk)
endif()