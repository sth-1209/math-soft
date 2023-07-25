cmake_minimum_required(VERSION 3.5)
project(Chicken)

# 设置安装目录变量
set(INSTALL_DIR "~/math-soft/ass06" CACHE PATH "Installation directory")

# 设置源文件路径
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# 添加可执行文件的生成规则
add_executable(chicken ${SOURCES})

# 设置输出可执行文件的路径
set_target_properties(chicken PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${INSTALL_DIR}/bin")

# 设置头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 安装头文件
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Chicken.h DESTINATION ${INSTALL_DIR}/include)

# 安装可执行文件
install(TARGETS chicken DESTINATION ${INSTALL_DIR}/bin)

# Check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
endif()
# Configure the Doxyfile
file(WRITE ${DOXYGEN_IN} "PROJECT_NAME = \"Chicken\"\n")    
file(APPEND ${DOXYGEN_IN} "PROJECT_NUMBER = \"1.0\"\n")
file(APPEND ${DOXYGEN_IN} "INPUT = ${INSTALL_DIR}\n")
file(APPEND ${DOXYGEN_IN} "OUTPUT_DIRECTORY = ${INSTALL_DIR}/doc\n")
file(APPEND ${DOXYGEN_IN} "GENERATE_LATEX = YES\n")
file(APPEND ${DOXYGEN_IN} "LATEX_OUTPUT = chicken\n")

configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

add_custom_command(
    OUTPUT ${INSTALL_DIR}/doc        
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${INSTALL_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)

add_custom_target(doc ALL DEPENDS ${INSTALL_DIR}/doc)

