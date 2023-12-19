    #include <dpp/dpp.h>
    #include "Listeners/ message_listener.h"

void message_listener::select_click(const dpp::select_click_t& event) {
dpp::cluster& bot = *event.from->creator;
bot.on_select_click([&bot](const dpp::select_click_t& event)
 {
    dpp::message message = event.command.msg;
        message.components = std::vector <dpp::component>(0);

        if (event.values[0] == "value1") {
            message.add_component(mute(bot, event));                    
        }
         else if (event.values[0] == "exit") {
         bot.message_delete(event.command.msg.id, event.command.channel.id);
        }
        event.edit_original_response(message);
 });    

}