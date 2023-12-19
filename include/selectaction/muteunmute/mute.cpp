#pragma once
#include <dpp/dpp.h>
#include "givemute/givemute.cpp"



dpp::component mute (dpp::cluster& bot, const dpp::select_click_t& event) {
    dpp::component component = dpp::component().add_component(
            dpp::component()
           .set_type(dpp::cot_selectmenu)
           .set_placeholder("Выберите какое либо действие")
           .add_select_option(dpp::select_option("Выдать мут","givemute","Заткни кого-то").set_emoji("icons896",1183228117335158845))
           .add_select_option(dpp::select_option("Снять мут","ungivemute","Заткни кого-то").set_emoji("icons896",1183227274179399710))
           .add_select_option(dpp::select_option("Меню","menu","Заткни кого-то").set_emoji("icons896",1183228671494983690))
           .add_select_option(dpp::select_option("Выход","exit","Заткни кого-то").set_emoji("icons896",1179425719932162079))
           .set_id("givemute")
        );
return component;
}
