// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice
#include "openclaw_msgs/msg/detail/task_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "openclaw_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "openclaw_msgs/msg/detail/task_status__struct.h"
#include "openclaw_msgs/msg/detail/task_status__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // prompt
#include "rosidl_runtime_c/string_functions.h"  // prompt

// forward declare type support functions


using _TaskStatus__ros_msg_type = openclaw_msgs__msg__TaskStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
bool cdr_serialize_openclaw_msgs__msg__TaskStatus(
  const openclaw_msgs__msg__TaskStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: prompt
  {
    const rosidl_runtime_c__String * str = &ros_message->prompt;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
bool cdr_deserialize_openclaw_msgs__msg__TaskStatus(
  eprosima::fastcdr::Cdr & cdr,
  openclaw_msgs__msg__TaskStatus * ros_message)
{
  // Field name: prompt
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->prompt.data) {
      rosidl_runtime_c__String__init(&ros_message->prompt);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->prompt,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'prompt'\n");
      return false;
    }
  }

  // Field name: confidence
  {
    cdr >> ros_message->confidence;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
size_t get_serialized_size_openclaw_msgs__msg__TaskStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TaskStatus__ros_msg_type * ros_message = static_cast<const _TaskStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: prompt
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->prompt.size + 1);

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
size_t max_serialized_size_openclaw_msgs__msg__TaskStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: prompt
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = openclaw_msgs__msg__TaskStatus;
    is_plain =
      (
      offsetof(DataType, confidence) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
bool cdr_serialize_key_openclaw_msgs__msg__TaskStatus(
  const openclaw_msgs__msg__TaskStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: prompt
  {
    const rosidl_runtime_c__String * str = &ros_message->prompt;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
size_t get_serialized_size_key_openclaw_msgs__msg__TaskStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TaskStatus__ros_msg_type * ros_message = static_cast<const _TaskStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: prompt
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->prompt.size + 1);

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_openclaw_msgs
size_t max_serialized_size_key_openclaw_msgs__msg__TaskStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: prompt
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = openclaw_msgs__msg__TaskStatus;
    is_plain =
      (
      offsetof(DataType, confidence) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _TaskStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const openclaw_msgs__msg__TaskStatus * ros_message = static_cast<const openclaw_msgs__msg__TaskStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_openclaw_msgs__msg__TaskStatus(ros_message, cdr);
}

static bool _TaskStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  openclaw_msgs__msg__TaskStatus * ros_message = static_cast<openclaw_msgs__msg__TaskStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_openclaw_msgs__msg__TaskStatus(cdr, ros_message);
}

static uint32_t _TaskStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_openclaw_msgs__msg__TaskStatus(
      untyped_ros_message, 0));
}

static size_t _TaskStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_openclaw_msgs__msg__TaskStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TaskStatus = {
  "openclaw_msgs::msg",
  "TaskStatus",
  _TaskStatus__cdr_serialize,
  _TaskStatus__cdr_deserialize,
  _TaskStatus__get_serialized_size,
  _TaskStatus__max_serialized_size,
  nullptr,
  false,
  nullptr,
  nullptr
};

static rosidl_message_type_support_t _TaskStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TaskStatus,
  get_message_typesupport_handle_function,
  &openclaw_msgs__msg__TaskStatus__get_type_hash,
  &openclaw_msgs__msg__TaskStatus__get_type_description,
  &openclaw_msgs__msg__TaskStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, openclaw_msgs, msg, TaskStatus)() {
  return &_TaskStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
