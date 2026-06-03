// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice

#ifndef OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "openclaw_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "openclaw_msgs/msg/detail/task_status__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace openclaw_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_openclaw_msgs
cdr_serialize(
  const openclaw_msgs::msg::TaskStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_openclaw_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  openclaw_msgs::msg::TaskStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_openclaw_msgs
get_serialized_size(
  const openclaw_msgs::msg::TaskStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_openclaw_msgs
max_serialized_size_TaskStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_openclaw_msgs
cdr_serialize_key(
  const openclaw_msgs::msg::TaskStatus & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_openclaw_msgs
get_serialized_size_key(
  const openclaw_msgs::msg::TaskStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_openclaw_msgs
max_serialized_size_key_TaskStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace openclaw_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_openclaw_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, openclaw_msgs, msg, TaskStatus)();

#ifdef __cplusplus
}
#endif

#endif  // OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
