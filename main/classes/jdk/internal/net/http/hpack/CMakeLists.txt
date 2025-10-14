#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.jdk.internal.net.htt_2_SRCS)
file(GLOB classes.jdk.internal.net.htt_2_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.jdk.internal.net.htt_2_HEADERS}) 
list(LENGTH classes.jdk.internal.net.htt_2_SRCS classes.jdk.internal.net.htt_2_SRCS_LENGTH)
if(classes.jdk.internal.net.htt_2_SRCS_LENGTH)
	add_library(classes.jdk.internal.net.htt_2 OBJECT "${classes.jdk.internal.net.htt_2_SRCS}" "${classes.jdk.internal.net.htt_2_HEADERS}")
	jcpp_enable_bigobj(classes.jdk.internal.net.htt_2)
endif()