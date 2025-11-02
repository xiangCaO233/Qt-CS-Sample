cmake_minimum_required(VERSION 3.28)

project(
  qtip
  VERSION 0.1
  LANGUAGES CXX)

# 启用自动处理 Qt 特性
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# 查找 Qt 包
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Svg Sql Network)

# 创建可执行文件
qt_add_executable(
  qtiptest MANUAL_FINALIZATION src/main.cpp src/server/servermainwindow.h
  src/server/servermainwindow.cpp src/server/servermainwindow.ui
  src/client/clientmainwindow.h src/client/clientmainwindow.cpp src/client/clientmainwindow.ui)

# 链接库
target_link_libraries(qtiptest PRIVATE Qt6::Core Qt6::Widgets Qt6::Svg Qt6::Sql
                                       Qt6::Network)

# 安装配置
include(GNUInstallDirs)
install(
  TARGETS qtiptest
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Qt6 最终化处理
qt_finalize_executable(qtiptest)
