// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice
#include "openclaw_msgs/msg/detail/task_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `prompt`
#include "rosidl_runtime_c/string_functions.h"

bool
openclaw_msgs__msg__TaskStatus__init(openclaw_msgs__msg__TaskStatus * msg)
{
  if (!msg) {
    return false;
  }
  // prompt
  if (!rosidl_runtime_c__String__init(&msg->prompt)) {
    openclaw_msgs__msg__TaskStatus__fini(msg);
    return false;
  }
  // confidence
  return true;
}

void
openclaw_msgs__msg__TaskStatus__fini(openclaw_msgs__msg__TaskStatus * msg)
{
  if (!msg) {
    return;
  }
  // prompt
  rosidl_runtime_c__String__fini(&msg->prompt);
  // confidence
}

bool
openclaw_msgs__msg__TaskStatus__are_equal(const openclaw_msgs__msg__TaskStatus * lhs, const openclaw_msgs__msg__TaskStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // prompt
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->prompt), &(rhs->prompt)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
openclaw_msgs__msg__TaskStatus__copy(
  const openclaw_msgs__msg__TaskStatus * input,
  openclaw_msgs__msg__TaskStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // prompt
  if (!rosidl_runtime_c__String__copy(
      &(input->prompt), &(output->prompt)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  return true;
}

openclaw_msgs__msg__TaskStatus *
openclaw_msgs__msg__TaskStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  openclaw_msgs__msg__TaskStatus * msg = (openclaw_msgs__msg__TaskStatus *)allocator.allocate(sizeof(openclaw_msgs__msg__TaskStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(openclaw_msgs__msg__TaskStatus));
  bool success = openclaw_msgs__msg__TaskStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
openclaw_msgs__msg__TaskStatus__destroy(openclaw_msgs__msg__TaskStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    openclaw_msgs__msg__TaskStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
openclaw_msgs__msg__TaskStatus__Sequence__init(openclaw_msgs__msg__TaskStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  openclaw_msgs__msg__TaskStatus * data = NULL;

  if (size) {
    data = (openclaw_msgs__msg__TaskStatus *)allocator.zero_allocate(size, sizeof(openclaw_msgs__msg__TaskStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = openclaw_msgs__msg__TaskStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        openclaw_msgs__msg__TaskStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
openclaw_msgs__msg__TaskStatus__Sequence__fini(openclaw_msgs__msg__TaskStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      openclaw_msgs__msg__TaskStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

openclaw_msgs__msg__TaskStatus__Sequence *
openclaw_msgs__msg__TaskStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  openclaw_msgs__msg__TaskStatus__Sequence * array = (openclaw_msgs__msg__TaskStatus__Sequence *)allocator.allocate(sizeof(openclaw_msgs__msg__TaskStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = openclaw_msgs__msg__TaskStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
openclaw_msgs__msg__TaskStatus__Sequence__destroy(openclaw_msgs__msg__TaskStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    openclaw_msgs__msg__TaskStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
openclaw_msgs__msg__TaskStatus__Sequence__are_equal(const openclaw_msgs__msg__TaskStatus__Sequence * lhs, const openclaw_msgs__msg__TaskStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!openclaw_msgs__msg__TaskStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
openclaw_msgs__msg__TaskStatus__Sequence__copy(
  const openclaw_msgs__msg__TaskStatus__Sequence * input,
  openclaw_msgs__msg__TaskStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(openclaw_msgs__msg__TaskStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    openclaw_msgs__msg__TaskStatus * data =
      (openclaw_msgs__msg__TaskStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!openclaw_msgs__msg__TaskStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          openclaw_msgs__msg__TaskStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!openclaw_msgs__msg__TaskStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
