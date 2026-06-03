// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "openclaw_msgs/msg/task_status.h"


#ifndef OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__STRUCT_H_
#define OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'prompt'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TaskStatus in the package openclaw_msgs.
typedef struct openclaw_msgs__msg__TaskStatus
{
  rosidl_runtime_c__String prompt;
  double confidence;
} openclaw_msgs__msg__TaskStatus;

// Struct for a sequence of openclaw_msgs__msg__TaskStatus.
typedef struct openclaw_msgs__msg__TaskStatus__Sequence
{
  openclaw_msgs__msg__TaskStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} openclaw_msgs__msg__TaskStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__STRUCT_H_
