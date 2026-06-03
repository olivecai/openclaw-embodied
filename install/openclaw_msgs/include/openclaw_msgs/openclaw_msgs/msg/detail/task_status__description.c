// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice

#include "openclaw_msgs/msg/detail/task_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_openclaw_msgs
const rosidl_type_hash_t *
openclaw_msgs__msg__TaskStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x01, 0x52, 0x80, 0x3c, 0x53, 0x7c, 0xf6, 0x8e,
      0xff, 0x33, 0x29, 0x05, 0xf7, 0x2c, 0x90, 0x11,
      0x50, 0x93, 0x2c, 0x01, 0xbe, 0x7b, 0x9e, 0x43,
      0x79, 0xfa, 0xa4, 0xaa, 0xd1, 0x5e, 0x8b, 0x08,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char openclaw_msgs__msg__TaskStatus__TYPE_NAME[] = "openclaw_msgs/msg/TaskStatus";

// Define type names, field names, and default values
static char openclaw_msgs__msg__TaskStatus__FIELD_NAME__prompt[] = "prompt";
static char openclaw_msgs__msg__TaskStatus__FIELD_NAME__confidence[] = "confidence";

static rosidl_runtime_c__type_description__Field openclaw_msgs__msg__TaskStatus__FIELDS[] = {
  {
    {openclaw_msgs__msg__TaskStatus__FIELD_NAME__prompt, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {openclaw_msgs__msg__TaskStatus__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
openclaw_msgs__msg__TaskStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {openclaw_msgs__msg__TaskStatus__TYPE_NAME, 28, 28},
      {openclaw_msgs__msg__TaskStatus__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string prompt\n"
  "float64 confidence";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
openclaw_msgs__msg__TaskStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {openclaw_msgs__msg__TaskStatus__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 33, 33},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
openclaw_msgs__msg__TaskStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *openclaw_msgs__msg__TaskStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
