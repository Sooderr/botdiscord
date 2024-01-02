	#pragma once
 
#include <dpp/dpp.h>
 
class message_listener {
 
public:
 
    /* Create a static function that can be called anywhere. */
    static void select_click(const dpp::select_click_t& event);
 
};