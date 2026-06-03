// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from openclaw_msgs:msg/TaskStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "openclaw_msgs/msg/task_status.hpp"


#ifndef OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__TRAITS_HPP_
#define OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "openclaw_msgs/msg/detail/task_status__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace openclaw_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TaskStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: prompt
  {
    out << "prompt: ";
    rosidl_generator_traits::value_to_yaml(msg.prompt, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: prompt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prompt: ";
    rosidl_generator_traits::value_to_yaml(msg.prompt, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, openclaw_msgs::msg::TaskStatus>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).prompt,
    std::forward<T>(msg).confidence);
}

}  // namespace msg

}  // namespace openclaw_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<openclaw_msgs::msg::TaskStatus>()
{
  return "openclaw_msgs::msg::TaskStatus";
}

template<>
constexpr const char * name<openclaw_msgs::msg::TaskStatus>()
{
  return "openclaw_msgs/msg/TaskStatus";
}

template<>
struct has_fixed_size<openclaw_msgs::msg::TaskStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<openclaw_msgs::msg::TaskStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<openclaw_msgs::msg::TaskStatus>
  : std::true_type {};

template<>
struct MessageTraits<openclaw_msgs::msg::TaskStatus>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "prompt",
    "confidence",
  };
};

}  // namespace rosidl_generator_traits

#endif  // OPENCLAW_MSGS__MSG__DETAIL__TASK_STATUS__TRAITS_HPP_
