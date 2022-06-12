cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_MODULE_PATH 
	${CMAKE_MODULE_PATH} ${CMAKE_MODULE_PATH}/cmake_helpers/find_modules)

project(Elprom LANGUAGES CXX)	#first instance the project and the language


set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})	#set the current path to be equal to the Base Dir

add_executable(
	${PROJECT_NAME} 	
	#${_BASE_DIR}/FileReader.h
	#${_BASE_DIR}/FileReader.cpp
	
	${_BASE_DIR}/main.cpp
	)


target_include_directories(
${PROJECT_NAME} 
	PRIVATE 
		${_BASE_DIR}
)
#this is a bash script for copying the resource folder
#add_custom_command(
#	TARGET ${PROJECT_NAME} POST_BUILD
#		COMMAND ${CMAKE_COMMAND} -E copy_directory
#		${CMAKE_CURRENT_SOURCE_DIR}/resources/
#		$<TARGET_FILE_DIR:${PROJECT_NAME}>resources/
#	)
