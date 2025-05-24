@REM cmake 构建项目
@echo off
REM 设置构建目录
cmake  -S. -Bbuild  
cmake --build build --target ALL_BUILD