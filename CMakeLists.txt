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

set(ServerSources
    src/server/ServerMain.cpp src/server/MainServer.h src/server/MainServer.cpp
    src/server/servermainwindow.h src/server/servermainwindow.cpp
    src/server/servermainwindow.ui)
set(ClientSources
    src/client/ClientMain.cpp src/client/StandardClient.h
    src/client/StandardClient.cpp src/client/clientmainwindow.h
    src/client/clientmainwindow.cpp src/client/clientmainwindow.ui)

# 创建可执行文件
qt_add_executable(qtip-ServerTest MANUAL_FINALIZATION ${ServerSources})
qt_add_executable(qtip-ClientTest MANUAL_FINALIZATION ${ClientSources})

# 链接库
target_link_libraries(qtip-ServerTest PRIVATE Qt6::Core Qt6::Widgets Qt6::Svg
                                              Qt6::Sql Qt6::Network)
target_link_libraries(qtip-ClientTest PRIVATE Qt6::Core Qt6::Widgets Qt6::Svg
                                              Qt6::Sql Qt6::Network)

# 安装配置
include(GNUInstallDirs)
install(
  TARGETS qtip-ServerTest
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(
  TARGETS qtip-ClientTest
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Qt6 最终化处理
qt_finalize_executable(qtip-ServerTest)
qt_finalize_executable(qtip-ClientTest)
