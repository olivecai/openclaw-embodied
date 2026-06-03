#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "openclaw_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__openclaw_msgs__msg__TaskStatus() -> *const std::ffi::c_void;
}

#[link(name = "openclaw_msgs__rosidl_generator_c")]
extern "C" {
    fn openclaw_msgs__msg__TaskStatus__init(msg: *mut TaskStatus) -> bool;
    fn openclaw_msgs__msg__TaskStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TaskStatus>, size: usize) -> bool;
    fn openclaw_msgs__msg__TaskStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TaskStatus>);
    fn openclaw_msgs__msg__TaskStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TaskStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<TaskStatus>) -> bool;
}

// Corresponds to openclaw_msgs__msg__TaskStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TaskStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub prompt: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f64,

}



impl Default for TaskStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !openclaw_msgs__msg__TaskStatus__init(&mut msg as *mut _) {
        panic!("Call to openclaw_msgs__msg__TaskStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TaskStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { openclaw_msgs__msg__TaskStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { openclaw_msgs__msg__TaskStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { openclaw_msgs__msg__TaskStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TaskStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TaskStatus where Self: Sized {
  const TYPE_NAME: &'static str = "openclaw_msgs/msg/TaskStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__openclaw_msgs__msg__TaskStatus() }
  }
}


