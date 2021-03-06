#pragma once
#include "Event.h"
#include "aurpch.h"
namespace Aurora {
class KeyEvent : public Event {
 public:
  inline int GetKeyCode() const { return m_keycode; }
  EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
 protected:
  KeyEvent(int keycode) : m_keycode(keycode) {}
  int m_keycode;
};

class keyPressedEvent : public KeyEvent {
 public:
  keyPressedEvent(int keycode, int repeatcount)
      : KeyEvent(keycode), m_RepeatCount(repeatcount) {}
  inline int GetRepeatCount() const { return m_RepeatCount; }
  std::string ToString() const override {
    std::stringstream ss;
    ss << "KeyPressedEvent: " << m_keycode << ":" << m_RepeatCount;
    return ss.str();
  }
  EVENT_CLASS_TYPE(KeyPressed)
 private:
  int m_RepeatCount;
};


class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(int keycode)
		: KeyEvent(keycode) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_keycode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyReleased)
};


class KeyTypedEvent : public KeyEvent {
public:
	KeyTypedEvent(int keycode)
		: KeyEvent(keycode) {}
	
	std::string ToString() const override {
		std::stringstream ss;
		ss << "KeyTypedEvent: " << m_keycode ;
		return ss.str();
	}
	EVENT_CLASS_TYPE(KeyTyped)
};



}  // namespace Aurora
