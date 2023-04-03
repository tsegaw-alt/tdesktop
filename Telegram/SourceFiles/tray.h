/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "platform/platform_tray.h"
#include <rpl/producer.h>

namespace Core {

class Tray {
public:
    Tray();

    void create();
    void update_menu_text();
    void update_icon_counters();

    [[nodiscard]] rpl::producer<> about_to_show_requests() const;
    [[nodiscard]] rpl::producer<> show_from_tray_requests() const;
    [[nodiscard]] rpl::producer<> hide_to_tray_requests() const;

    [[nodiscard]] bool has() const;

private:
    void rebuild_menu();
    void toggle_sound_notifications();

    Platform::Tray _tray;

    bool _active_for_tray_icon_action = false;
    crl::time _last_tray_click_time = 0;

    rpl::event_stream<> _text_updates;
    rpl::event_stream<> _minimize_menu_item_clicks;
};

} // namespace Core
