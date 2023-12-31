cmake_minimum_required(VERSION 2.0)

project(test)

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT_PARENT_DIR ${PARENT_DIR} DIRECTORY)

message(status "source directory is: " ${PROJECT_SOURCE_DIR})
message(status "parent directory is: " ${PARENT_DIR})
message(status "parent parent directory is: " ${PARENT_PARENT_DIR})

add_compile_options(-g)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PARENT_PARENT_DIR} ${PARENT_DIR} ${PARENT_PARENT_DIR}/include)

add_executable(skip_list_test
skip_list_test.cpp
${PARENT_DIR}/skip_list.cpp
)

add_executable(tree_test
tree_test.cpp
${PARENT_DIR}/tree.cpp
)

add_executable(disjoint_set_test
disjoint_set_test.cpp
${PARENT_DIR}/disjoint_set.cpp
)

add_executable(list_test
list_test.cpp
)

add_executable(min_heap_test
min_heap_test.cpp
)

add_executable(graph_test
graph_test.cpp
${PARENT_DIR}/graph.cpp
${PARENT_DIR}/disjoint_set.cpp
)

add_executable(sparse_matrix_test
sparse_matrix_test.cpp
)

add_executable(ring_buffer_test
ring_buffer_test.cpp
)

add_executable(trie_test
trie_test.cpp
)

add_executable(monotonic_queue_test
monotonic_queue_test.cpp
)

add_executable(kmp_tset
kmp_test.cpp
)

add_executable(lru_tset
lru_test.cpp
)

add_executable(segment_tree_tset
segment_tree_test.cpp
)

add_executable(sort_test
sort_test.cpp
)

target_link_libraries(ring_buffer_test
pthread
)

target_link_libraries(sort_test
pthread
)
