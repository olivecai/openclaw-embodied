// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice
#ifndef OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "openclaw_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "openclaw_msgs/msg/detail/task_status__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
bool cdr_serialize_openclaw_msgs__msg__TaskStatus(
  const openclaw_msgs__msg__TaskStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
bool cdr_deserialize_openclaw_msgs__msg__TaskStatus(
  eprosima::fastcdr::Cdr &,
  openclaw_msgs__msg__TaskStatus * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
size_t get_serialized_size_openclaw_msgs__msg__TaskStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
size_t max_serialized_size_openclaw_msgs__msg__TaskStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
bool cdr_serialize_key_openclaw_msgs__msg__TaskStatus(
  const openclaw_msgs__msg__TaskStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
size_t get_serialized_size_key_openclaw_msgs__msg__TaskStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
size_t max_serialized_size_key_openclaw_msgs__msg__TaskStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, openclaw_msgs, msg, TaskStatus)();

#ifdef __cplusplus
}
#endif

#endif  // OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
