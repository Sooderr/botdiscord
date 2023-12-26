#include "listeners/ message_listener.h"
#include "../include/selectaction/muteunmute/mute.cpp"

void message_listener::select_click(const dpp::select_click_t& event) {
dpp::cluster& bot = *event.from->creator;
    dpp::message message = event.command.msg;
        message.components = std::vector <dpp::component>(0);
        if (event.values[0] == "value1") {
            message.add_component(mute(bot, event));                    
        }
        else if(event.values[0] == "givemute")
        {
            event.dialog(givemutevoice(bot,event));
        }
         else if (event.values[0] == "exit") {
         bot.message_delete(event.command.msg.id, event.command.channel.id);
        }
        event.reply(dpp::ir_update_message,message);
return;
}
