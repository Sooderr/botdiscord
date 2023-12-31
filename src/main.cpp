#include <dpp/dpp.h>
#include "listeners/ message_listener.h"


const std::string BOT_TOKEN = "";


int main()
{

    dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);
    bot.on_log(dpp::utility::cout_logger());
    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            dpp::slashcommand menu("action", u8"Выберите пользователя", bot.me.id);
            menu.add_option(
                dpp::command_option(dpp::co_user, "sobaka", "ti sobaka", true)
            );
            bot.global_command_create(menu);
        }



        });

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "action") {
            dpp::guild_member rolegay = event.command.member;
            auto dimka = rolegay.get_roles();
            for (const dpp::snowflake x : dimka)
            {
            const dpp::role* role = dpp::find_role(x); 
                if(role != nullptr){
                if (role->has_administrator()){
                  dpp::snowflake userid = std::get <dpp::snowflake>(event.get_parameter("sobaka"));

                  dpp::embed content = dpp::embed()
                  .set_color(dpp::colors::yellow_orange)
                  .set_title(u8"Делаем дела с пользователем")
                    .set_footer(std::to_string(userid), "");
                   event.reply(dpp::message (event.command.channel_id,content).set_flags(dpp::m_ephemeral).add_component(
                dpp::component().add_component(
                    dpp::component()
                        .set_type(dpp::cot_selectmenu)
                        .set_placeholder("Выберите какое либо действие")
                        .add_select_option(dpp::select_option("Выдать/Снять мут","value1","Заткни кого-то").set_emoji("icons896",1179421370774474802))
                        // .add_select_option(dpp::select_option("Выдать/Снять бан","value2","Тоби пизда").set_emoji("icons8296", 1179421848044310629))
                        // .add_select_option(dpp::select_option("Выдать/Снять варн","value3","Дать/забрать варн").set_emoji("icons896", 1179422180421935225))
                        // .add_select_option(dpp::select_option("Верификация","value4","Подтверждаю").set_emoji("icons8961",1179101745893355692))
                        // .add_select_option(dpp::select_option("Профиль","value5","Вот он я!").set_emoji("icons8961", 1179111178019012669))
                        // .add_select_option(dpp::select_option("Изменить роли","value6","Ты больше не армянин").set_emoji("icons896",1179112995767472260))
                        // .add_select_option(dpp::select_option("Нарушители","value7","Проказники").set_emoji("icons896", 1179116453035774062))
                        // .add_select_option(dpp::select_option("Топы","value8","Лучшиие").set_emoji("icons896", 1179123594375209000))
                        // .add_select_option(dpp::select_option("Взять/Снять отпуск","value9","На отдых!").set_emoji("icons896", 1179124082487332936))
                        // .add_select_option(dpp::select_option("Выговоры","value10","Все дела суда").set_emoji("icons896",1179124960560689172))
                        // .add_select_option(dpp::select_option("Список стаффа","value11","Наша комманда").set_emoji("icons896", 1179125876273725572))
                        // .add_select_option(dpp::select_option("Выдать/Снять валюту","value12","Деньги").set_emoji("icons896", 1179126480261890048))
                        // .add_select_option(dpp::select_option("Проблемы сервера","value13","Что-то случилось?").set_emoji("icons896", 1179127168303906817))
                        // .add_select_option(dpp::select_option("Выдать/Снять выговор","value14","description2").set_emoji("icons896",1179422884817539084))
                        // .add_select_option(dpp::select_option("База данных","value15","description1").set_emoji("icons896", 1179424414689927260))
                        // .add_select_option(dpp::select_option("Настроить бота","value16","description2").set_emoji("icons896", 1179424918014795806))
                        // .add_select_option(dpp::select_option("Выхол","value17","description1").set_emoji("icons896", 1179425719932162079))
                        .set_id("selectmenu")
                    )
                )
            );
            return ;
        }
                }
            
                }
                event.reply(u8"Y петухов нет прав");
            }

        });
bot.on_select_click(&message_listener::select_click);

          bot.start(dpp::st_wait);
}
