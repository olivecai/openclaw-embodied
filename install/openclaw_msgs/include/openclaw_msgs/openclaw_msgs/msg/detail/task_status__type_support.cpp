// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "openclaw_msgs/msg/detail/task_status__functions.h"
#include "openclaw_msgs/msg/detail/task_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace openclaw_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TaskStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) openclaw_msgs::msg::TaskStatus(_init);
}

void TaskStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<openclaw_msgs::msg::TaskStatus *>(message_memory);
  typed_message->~TaskStatus();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TaskStatus_message_member_array[2] = {
  {
    "prompt",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(openclaw_msgs::msg::TaskStatus, prompt),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "confidence",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(openclaw_msgs::msg::TaskStatus, confidence),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TaskStatus_message_members = {
  "openclaw_msgs::msg",  // message namespace
  "TaskStatus",  // message name
  2,  // number of fields
  sizeof(openclaw_msgs::msg::TaskStatus),
  false,  // has_any_key_member_
  TaskStatus_message_member_array,  // message members
  TaskStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  TaskStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TaskStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TaskStatus_message_members,
  get_message_typesupport_handle_function,
  &openclaw_msgs__msg__TaskStatus__get_type_hash,
  &openclaw_msgs__msg__TaskStatus__get_type_description,
  &openclaw_msgs__msg__TaskStatus__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace openclaw_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<openclaw_msgs::msg::TaskStatus>()
{
  return &::openclaw_msgs::msg::rosidl_typesupport_introspection_cpp::TaskStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, openclaw_msgs, msg, TaskStatus)() {
  return &::openclaw_msgs::msg::rosidl_typesupport_introspection_cpp::TaskStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
