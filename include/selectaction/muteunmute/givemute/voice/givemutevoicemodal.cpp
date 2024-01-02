#pragma once
#include <dpp/dpp.h>

long long time_seconds(std::string time) {
    char value_type = 0;
    unsigned long long int time_value = 0;
    for (int i = 0; i < time.size(); i++) {
        if (!(time[i] >= '0' && time[i] <= '9') && (time[i] != 's' && time[i] != 'm' && time[i] != 'h' && time[i] != 'd' && time[i] != 'w')) {
            return false;
        }
        if (time[i] == 's' || time[i] == 'm' || time[i] == 'h' || time[i] == 'd' || time[i] == 'w') {
            value_type = time[i];
            break;
        }
        if (time[i] >= '0' && time[i] <= '9') {
            time_value += (time[i] + '0');
            time_value *= 10;
        }
    }
    time_value /= 10;
    if (!time_value) {
        return false;
    }
    else {
        if (value_type == 's') {}
        else if (value_type == 'm') {
            time_value *= 60;
        }
        else if (value_type == 'h') {
            time_value *= 3600;
        }
        else if (value_type == 'd') {
            time_value *= 3600 * 24;
        }
        else if (value_type == 'w') {
            time_value *= 3600 * 24 * 7;
        }
    }
    return time_value;
}

dpp::interaction_modal_response givemutevoice(dpp::cluster& bot, const dpp::select_click_t& event) {
    /* Check for our /dialog command */
    {
        /* Instantiate an interaction_modal_response object */
        dpp::interaction_modal_response modal("my_modal", u8"Мут - голосового чата");
        /* Add a text component */
        modal.add_component(
            dpp::component().
            set_label(u8"Выберите причину мута").
            set_id("voicemutere  ason").
            set_type(dpp::cot_text).
            set_placeholder(u8"Причина мута").
            set_min_length(5).
            set_max_length(50).
            set_text_style(dpp::text_short)
        );
        /* Add another text component in the next row, as required by Discord */
        modal.add_row();
        modal.add_component(
            dpp::component().
            set_label(u8"Выберите время мута").
            set_id("voicemutetime").
            set_type(dpp::cot_text).
            set_placeholder(u8"Время мута").
            set_min_length(1).
            set_max_length(500).
            set_text_style(dpp::text_paragraph)
        );

        /* Trigger the dialog box. All dialog boxes are ephemeral */
        return modal;
    }
    bot.on_form_submit([&bot](const dpp::form_submit_t& event) {
        dpp::message message = event.command.msg; // это все нормально, так и должно быть
        if (message.embeds.empty()) {
            std::cout << "10 ballsacks" << std::endl;
            event.reply(u8"Я тебя найду и... Ну... хз");
            std::cout << u8"найду" << std::endl;
            return;
        }
        std::string userid = message.embeds[0].footer.value().text;

        std::cout << event.components.size() << ' ' << event.components[0].components.size() << std::endl;
        std::cout << event.components.size() << ' ' << event.components[1].components.size() << std::endl;

        std::string reason = std::get <std::string>(event.components[0].components[0].value);
        std::string duration = std::get <std::string>(event.components[1].components[0].value);

        std::cout << reason << ' ' << duration << std::endl;

        long long actual_duration = time_seconds(duration);

        if (actual_duration) {
            const dpp::snowflake rolemutevoice = 1066588600046735430;
            bot.guild_member_add_role(event.command.guild_id, userid, rolemutevoice);
            bot.start_timer([&bot, event, userid, rolemutevoice](dpp::timer h) {
                bot.guild_member_remove_role(event.command.guild_id, userid, rolemutevoice);

                bot.stop_timer(h);
            }, actual_duration);
            event.reply(dpp::message("I like being raped 24/7"));
            bot.direct_message_create((dpp::snowflake)userid, dpp::message(u8"Привет долбоебик!\nТебя замутили на " + std::to_string(actual_duration) + u8" секунд, ес хош то сам переводи, мне впабло. Все пока, мне пора идти хуи сосать. А, вот, причина:```" + reason + "```"));
        }
        else {
            event.reply(dpp::message("I aint got balls and im not castrated, im just a female"));
        }
    });

}