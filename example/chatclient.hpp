/*
Copyright © 2013 Christian Glöckner <cgloeckner@freenet.de>

This file is part of the networking module:
    https://github.com/cgloeckner/networking

It offers an event-based networking framework for games and other software.

The source code is released under CC BY-NC 3.0
http://creativecommons.org/licenses/by-nc/3.0/
*/

#ifndef CHATCLIENT_HPP
#define CHATCLIENT_HPP

#include <iostream>
#include <map>

#include "events.hpp"

#include "../src/connection.hpp"
#include "../src/serverclient.hpp"

class ChatClient;

void client_handler(ChatClient* client);

class ChatClient: public networking::Client {
    friend void client_handler(ChatClient* client);
    protected:
        networking::Thread handler;

        std::map<ClientID, std::string> users;

        void handle();
        void login(LoginResponse* data);
        void message(MessageResponse* data);
        void logout(LogoutResponse* data);
        void update(UserlistUpdate* data);
    public:
        ChatClient(const std::string& ip, unsigned short port);
        virtual ~ChatClient();

        bool authed;
        std::string username;
};

#endif

