#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.net.http_SRCS)
file(GLOB classes.java.net.http_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.net.http_HEADERS}) 
list(LENGTH classes.java.net.http_SRCS classes.java.net.http_SRCS_LENGTH)
if(classes.java.net.http_SRCS_LENGTH)
	add_library(classes.java.net.http OBJECT "${classes.java.net.http_SRCS}" "${classes.java.net.http_HEADERS}")
	jcpp_enable_bigobj(classes.java.net.http)
endif()