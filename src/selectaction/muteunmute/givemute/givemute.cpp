#pragma once
#include <dpp/dpp.h>
#include "voice/givemutevoicemodal.cpp"

dpp::component givemute (dpp::cluster& bot, const dpp::select_click_t& event) {
    dpp::component component = dpp::component().add_component(
            dpp::component()
           .set_type(dpp::cot_selectmenu)
           .set_placeholder("Выберите какое либо действие")
           .add_select_option(dpp::select_option("Голосовой мут","givemutevoice","Заткни кого-то").set_emoji("icons896",1183228117335158845))
           .add_select_option(dpp::select_option("Текстовый мут","givemutetext","Заткни кого-то").set_emoji("icons896",1183469211390062672))
           .set_id("givemutevoicetext")
        );

    return component;
}