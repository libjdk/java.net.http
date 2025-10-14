#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" test-classes_SRCS)
file(GLOB test-classes_HEADERS *.h *.hpp)
source_group("Include" FILES ${test-classes_HEADERS}) 
list(LENGTH test-classes_SRCS test-classes_SRCS_LENGTH)
if(test-classes_SRCS_LENGTH)
	add_library(test-classes OBJECT "${test-classes_SRCS}" "${test-classes_HEADERS}")
	jcpp_enable_bigobj(test-classes)
endif()