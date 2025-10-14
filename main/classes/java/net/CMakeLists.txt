#machine generated

add_subdirectory("http")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.net_SRCS)
file(GLOB classes.java.net_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.net_HEADERS}) 
list(LENGTH classes.java.net_SRCS classes.java.net_SRCS_LENGTH)
if(classes.java.net_SRCS_LENGTH)
	add_library(classes.java.net OBJECT "${classes.java.net_SRCS}" "${classes.java.net_HEADERS}")
	jcpp_enable_bigobj(classes.java.net)
endif()