// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "openclaw_msgs/msg/task_status.hpp"


#ifndef OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__BUILDER_HPP_
#define OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "openclaw_msgs/msg/detail/task_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace openclaw_msgs
{

namespace msg
{

namespace builder
{

class Init_TaskStatus_confidence
{
public:
  explicit Init_TaskStatus_confidence(::openclaw_msgs::msg::TaskStatus & msg)
  : msg_(msg)
  {}
  ::openclaw_msgs::msg::TaskStatus confidence(::openclaw_msgs::msg::TaskStatus::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::openclaw_msgs::msg::TaskStatus msg_;
};

class Init_TaskStatus_prompt
{
public:
  Init_TaskStatus_prompt()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskStatus_confidence prompt(::openclaw_msgs::msg::TaskStatus::_prompt_type arg)
  {
    msg_.prompt = std::move(arg);
    return Init_TaskStatus_confidence(msg_);
  }

private:
  ::openclaw_msgs::msg::TaskStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::openclaw_msgs::msg::TaskStatus>()
{
  return openclaw_msgs::msg::builder::Init_TaskStatus_prompt();
}

}  // namespace openclaw_msgs

#endif  // OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__BUILDER_HPP_
