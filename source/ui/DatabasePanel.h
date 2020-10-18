#pragma once

#include <memory>
#include <optional>
#include <vector>

class wxListEvent;

namespace WhatsApp {
class Chat;
class Database;
} // namespace WhatsApp

namespace UI {

class DatabasePanel : public wxPanel {
public:
  DatabasePanel(wxWindow *parent, std::unique_ptr<WhatsApp::Database> database);

private:
  std::unique_ptr<WhatsApp::Database> database;
  std::vector<WhatsApp::Chat> chats;
  std::optional<WhatsApp::Chat *> selectedChat;

  void updateChats();
  void openChat(WhatsApp::Chat &chat);

  void OnDisplayChat(wxListEvent &event);

  wxDECLARE_EVENT_TABLE();
};

} // namespace UI