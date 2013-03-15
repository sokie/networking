/*
Copyright © 2013 Christian Glöckner <cgloeckner@freenet.de>

This file is part of the networking module:
    https://github.com/cgloeckner/networking

It offers an event-based networking framework for games and other software.

The source code is released under CC BY-NC 3.0
http://creativecommons.org/licenses/by-nc/3.0/
*/

#include "eventsystem.hpp"

Event::Event()
    : event_id(E_GENERIC) {
}

Event::Event(EventID event_id)
    : event_id(event_id) {
}

Event::Event(Event* other)
    : event_id(other->event_id) {
}

