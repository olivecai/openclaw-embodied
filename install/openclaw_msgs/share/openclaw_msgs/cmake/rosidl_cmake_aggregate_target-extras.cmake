# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target openclaw_msgs::openclaw_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${openclaw_msgs_TARGETS}.
if(openclaw_msgs_TARGETS AND NOT TARGET openclaw_msgs::openclaw_msgs)
  add_library(openclaw_msgs::openclaw_msgs INTERFACE IMPORTED)
  set_target_properties(openclaw_msgs::openclaw_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${openclaw_msgs_TARGETS}")
endif()
