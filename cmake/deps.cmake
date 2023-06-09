include(FetchContent)

set(DOCTEST_NO_INSTALL ON)
FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/onqtam/doctest.git
  GIT_TAG v2.4.11)
FetchContent_MakeAvailable(doctest)


FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.1)
FetchContent_MakeAvailable(json)

include(FetchContent)
FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG v3.1.1)
FetchContent_MakeAvailable(cxxopts)

# 下载和构建 spdlog 库
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.9.2)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
  SQLiteCpp
  GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp.git
  GIT_TAG master
  )
set(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "")

FetchContent_MakeAvailable(SQLiteCpp)
