#machine generated

add_subdirectory("net")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java_SRCS)
file(GLOB classes.java_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java_HEADERS}) 
list(LENGTH classes.java_SRCS classes.java_SRCS_LENGTH)
if(classes.java_SRCS_LENGTH)
	add_library(classes.java OBJECT "${classes.java_SRCS}" "${classes.java_HEADERS}")
	jcpp_enable_bigobj(classes.java)
endif()