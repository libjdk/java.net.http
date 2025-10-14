#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.jdk.internal.net.htt_0_SRCS)
file(GLOB classes.jdk.internal.net.htt_0_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.jdk.internal.net.htt_0_HEADERS}) 
list(LENGTH classes.jdk.internal.net.htt_0_SRCS classes.jdk.internal.net.htt_0_SRCS_LENGTH)
if(classes.jdk.internal.net.htt_0_SRCS_LENGTH)
	add_library(classes.jdk.internal.net.htt_0 OBJECT "${classes.jdk.internal.net.htt_0_SRCS}" "${classes.jdk.internal.net.htt_0_HEADERS}")
	jcpp_enable_bigobj(classes.jdk.internal.net.htt_0)
endif()