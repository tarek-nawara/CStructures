set(LIST_SOURCE_FILES
  linked_list.hpp
  single_linked_list.hpp
  main.cpp
)

# Declare the library
add_library(list STATIC
    ${LIST_SOURCE_FILES}
)

# Specify here the include directories exported
# by this library
target_include_directories(list PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
