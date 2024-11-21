cmake_minimum_required(VERSION 3.22)
project(data_structure)
set(CMAKE_C_STANDARD 99)

# include 디렉토리 추가
include_directories(${PROJECT_SOURCE_DIR}/include/01_single_linked_list)
include_directories(${PROJECT_SOURCE_DIR}/include/02_doubly_linked_list)

# 실행 파일 생성
add_executable(data_structure
        src/main.c
        src/01_single_linked_list/single_linked_list.c
        src/02_doubly_linked_list/doubly_linked_list.c
)
