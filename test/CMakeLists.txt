#machine generated

jcpp_add_dependencies(
	"java.base:17.35"
)

include_directories("classes")
include_directories("../main/include")

add_subdirectory("classes")

aux_source_directory("." source_SRCS)

set(local_object ${local_object}
	"$<TARGET_OBJECTS:test-classes>"
)

add_executable(${JCPP_PROJECT_FULL_NAME}-test "${local_object}" "${source_SRCS}")

SET_TARGET_PROPERTIES(${JCPP_PROJECT_FULL_NAME}-test PROPERTIES OUTPUT_NAME "${JCPP_PROJECT_FULL_NAME}-test")
if(JCPP_OS MATCHES "linux")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_FULL_NAME}-test PROPERTIES INSTALL_RPATH "\\\$ORIGIN;\\\$ORIGIN/../lib")
elseif(JCPP_OS MATCHES "macosx")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_FULL_NAME}-test PROPERTIES INSTALL_RPATH ".;../lib")
endif()

jcpp_enable_debug_info(${JCPP_PROJECT_FULL_NAME}-test)

if(BUILD_SHARED_LIB)
	target_link_libraries(${JCPP_PROJECT_FULL_NAME}-test
		PRIVATE ${JCPP_DEPENDENCY_LIBS}
		PRIVATE ${JCPP_PROJECT_NAME}_shared
	)
	add_dependencies(${JCPP_PROJECT_FULL_NAME}-test ${JCPP_PROJECT_NAME}_shared)
	if(WIN32)
		foreach(runtimeFile IN LISTS JCPP_DEPENDENCY_RUNTIME_FILE_PATHS)
			add_custom_command(TARGET ${JCPP_PROJECT_FULL_NAME}-test POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy_if_different 
					${runtimeFile}
					"${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>"
			)
		endforeach()
		add_custom_command(TARGET ${JCPP_PROJECT_FULL_NAME}-test POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_if_different 
				$<TARGET_FILE:${JCPP_PROJECT_NAME}_shared>
				"${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/"
		)
	else()
		foreach(runtimeFile IN LISTS JCPP_DEPENDENCY_RUNTIME_FILE_PATHS)
			add_custom_command(TARGET ${JCPP_PROJECT_FULL_NAME}-test POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy_if_different 
					${runtimeFile}
					"${CMAKE_CURRENT_BINARY_DIR}/"
			)
		endforeach()
	endif()
else()

	target_link_libraries(${JCPP_PROJECT_FULL_NAME}-test
		PRIVATE ${JCPP_PROJECT_NAME}_static
		${JCPP_EXT_LIBS}
	)
	add_dependencies(${JCPP_PROJECT_FULL_NAME}-test ${JCPP_PROJECT_NAME}_static)
endif()

jcpp_enable_bigobj(${JCPP_PROJECT_FULL_NAME}-test)

install(TARGETS ${JCPP_PROJECT_FULL_NAME}-test DESTINATION "${JCPP_BIN_INSTALL_PATH}")
