#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to openclaw_msgs__msg__TaskStatus

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TaskStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub prompt: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f64,

}



impl Default for TaskStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TaskStatus::default())
  }
}

impl rosidl_runtime_rs::Message for TaskStatus {
  type RmwMsg = super::msg::rmw::TaskStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        prompt: msg.prompt.as_str().into(),
        confidence: msg.confidence,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        prompt: msg.prompt.as_str().into(),
      confidence: msg.confidence,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      prompt: msg.prompt.to_string(),
      confidence: msg.confidence,
    }
  }
}


