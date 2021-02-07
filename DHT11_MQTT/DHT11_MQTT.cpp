/*
** This is generated code - do not touch!
*/

#include <string.h>

/*
** used C headers
*/

#include "env.hpp"
#include "Utils.hpp"

/*
** blech types
*/

#include "blech.hpp"

/*
** exports, user types and C wrappers
*/

#include "DHT11_MQTT.hpp"

/*
** direct C constants
*/

#define blc_DHT11_MQTT_MILLIS_PER_TICK (MILLIS_PER_TICK)

/*
** direct C functions
*/

#define blc_DHT11_MQTT_get_duration_of_high() \
    get_duration_of_high()

#define blc_DHT11_MQTT_write_to_pin(blc_level) \
    write_to_pin(blc_level)

#define blc_DHT11_MQTT_activate_input() \
    activate_input()

#define blc_DHT11_MQTT_print_conditions_raw(blc_temperature, blc_humidity) \
    print_conditions_raw(blc_temperature, blc_humidity)

#define blc_DHT11_MQTT_print_conditions(blc_temperature, blc_humidity) \
    print_conditions(blc_temperature, blc_humidity)

#define blc_DHT11_MQTT_interrupts_on() \
    interrupts_on()

#define blc_DHT11_MQTT_interrupts_off() \
    interrupts_off()

#define blc_DHT11_MQTT_publish_conditions(blc_temperature, blc_humidity) \
    publish_conditions(blc_temperature, blc_humidity)

#define blc_DHT11_MQTT_client_loop() \
    client_loop()

#define blc_DHT11_MQTT_is_client_connected() \
    is_client_connected()

#define blc_DHT11_MQTT_connect() \
    connect()

#define blc_DHT11_MQTT_LED_on() \
    LED_on()

#define blc_DHT11_MQTT_LED_off() \
    LED_off()

/*
** parameters
*/

/*
** state
*/

struct blc_DHT11_MQTT_Main blc_blech_ctx;

/*
** activities and functions
*/

/**  Delays the trail for the given period. */
static blc_pc_t blc_DHT11_MQTT_delay (struct blc_DHT11_MQTT_delay *blc_blech_ctx,
                                      const blc_nat32 blc_millis) {
    loopHead:
    if ( blc_blech_ctx->pc_1 == 2 ) {
        blc_blech_ctx->blc_delay_ticks = (blc_millis
        / blc_DHT11_MQTT_MILLIS_PER_TICK);
        if ( !((blc_blech_ctx->blc_delay_ticks == 0)) ) {
            blc_blech_ctx->pc_1 = 4;
        } else if ( (blc_blech_ctx->blc_delay_ticks == 0) ) {
            blc_blech_ctx->pc_1 = 6;
        }
    }
    if ( blc_blech_ctx->pc_1 == 4 ) {
        
        blc_blech_ctx->pc_1 = 8;
    }
    if ( blc_blech_ctx->pc_1 == 6 ) {
        blc_blech_ctx->blc_delay_ticks = 1;
        blc_blech_ctx->pc_1 = 8;
    }
    if ( blc_blech_ctx->pc_1 == 8 ) {
        blc_blech_ctx->blc_delay_ticks = (blc_blech_ctx->blc_delay_ticks - 1);
        blc_blech_ctx->pc_1 = 11; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_1 == 10 ) {
        if ( 1 ) {
            if ( !((blc_blech_ctx->blc_delay_ticks == 0)) ) {
                blc_blech_ctx->pc_1 = 8;
                goto loopHead;
            } else if ( (blc_blech_ctx->blc_delay_ticks == 0) ) {
                blc_blech_ctx->pc_1 = 12;
            }
        }
    }
    if ( blc_blech_ctx->pc_1 == 12 ) {
        blc_blech_ctx->pc_1 = 0; /* end */
    }
    
    
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_1);
    return blc_blech_ctx->pc_1 ;
}

static blc_pc_t blc_DHT11_MQTT_initiate_mesurement (struct blc_DHT11_MQTT_initiate_mesurement *blc_blech_ctx,
                                                    blc_bool *blc_retvar) {
    if ( blc_blech_ctx->pc_2 == 2 ) {
        blc_DHT11_MQTT_write_to_pin(0);
        blc_blech_ctx->pc_2_blc_DHT11_MQTT_delay.pc_1 = 2;
        blc_int32 blc_blech_aux_retcode_0;
        blc_blech_aux_retcode_0 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_2_blc_DHT11_MQTT_delay,
                                                       20);
        BLC_UNUSED(blc_blech_aux_retcode_0);
        blc_blech_ctx->pc_2 = 6;
    }
    if ( blc_blech_ctx->pc_2 == 4 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_0;
            blc_blech_aux_retcode_0 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_2_blc_DHT11_MQTT_delay,
                                                           20);
            if ( (0 == blc_blech_aux_retcode_0) ) {
                blc_blech_ctx->pc_2 = 8;
            } else if ( !((0 == blc_blech_aux_retcode_0)) ) {
                blc_blech_ctx->pc_2 = 6;
            }
        }
    }
    if ( blc_blech_ctx->pc_2 == 6 ) {
        blc_blech_ctx->pc_2 = 5; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_2 == 8 ) {
        blc_DHT11_MQTT_activate_input();
        blc_blech_ctx->blc_initiate_mesurement_initial_sequence = blc_DHT11_MQTT_get_duration_of_high();
        if ( !((100
        < blc_blech_ctx->blc_initiate_mesurement_initial_sequence)) ) {
            blc_blech_ctx->pc_2 = 10;
        } else if ( (100
        < blc_blech_ctx->blc_initiate_mesurement_initial_sequence) ) {
            blc_blech_ctx->pc_2 = 12;
        }
    }
    if ( blc_blech_ctx->pc_2 == 10 ) {
        (*blc_retvar) = 1;
        blc_blech_ctx->pc_2 = 0;
    }
    if ( blc_blech_ctx->pc_2 == 12 ) {
        (*blc_retvar) = 0;
        blc_blech_ctx->pc_2 = 0;
    }
    if ( blc_blech_ctx->pc_2 == 14 ) {
        blc_blech_ctx->pc_2 = 0; /* end */
    }
    
    
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_2);
    return blc_blech_ctx->pc_2 ;
}

static void blc_DHT11_MQTT_get_bits (blc_nat8 blc_bitfield[40]) {
    blc_DHT11_MQTT_interrupts_off();
    blc_nat8 blc_i;
    blc_i = 0;
    do {
        blc_nat32 blc_duration;
        blc_duration = blc_DHT11_MQTT_get_duration_of_high();
        if ( (50 < blc_duration) ) {
            blc_bitfield[blc_i] = 1;
        } else {
            blc_bitfield[blc_i] = 0;
        }
        blc_i = (blc_i + 1);
    } while ( !((40 <= blc_i)) );
    blc_DHT11_MQTT_interrupts_on();
}

static blc_bool blc_DHT11_MQTT_extract_bytes (const blc_nat8 blc_bitfield[40],
                                              blc_bits32 blc_data[5]) {
    blc_nat8 blc_i;
    blc_i = 0;
    do {
        blc_data[(blc_i / 8)] = (blc_data[(blc_i / 8)] << 1);
        if ( (blc_bitfield[blc_i] == 1) ) {
            blc_data[(blc_i / 8)] = (blc_data[(blc_i / 8)] | 1);
        }
        blc_i = (blc_i + 1);
    } while ( !((40 <= blc_i)) );
    blc_bool blc_checksum_valid;
    blc_checksum_valid = 0;
    blc_checksum_valid = (blc_data[4] == ((((blc_data[0] + blc_data[1])
    + blc_data[2]) + blc_data[3]) & 255));
    if ( blc_checksum_valid ) {
        return 1;
    } else {
        return 0;
    }
}

static blc_pc_t blc_DHT11_MQTT_measure (struct blc_DHT11_MQTT_measure *blc_blech_ctx,
                                        struct blc_DHT11_MQTT_EnvCond *blc_environment_conditions,
                                        blc_bool *blc_retvar) {
    if ( blc_blech_ctx->pc_5 == 2 ) {
        memset(blc_blech_ctx->blc_measure_bitfield, 0, 40 * sizeof(blc_nat8));
        blc_blech_ctx->blc_measure_init_valid = 0;
        blc_blech_ctx->pc_5_blc_DHT11_MQTT_initiate_mesurement.pc_2 = 2;
        blc_int32 blc_blech_aux_retcode_1;
        blc_blech_aux_retcode_1 = blc_DHT11_MQTT_initiate_mesurement(&blc_blech_ctx->pc_5_blc_DHT11_MQTT_initiate_mesurement,
                                                                     (&blc_blech_ctx->blc_measure_init_valid));
        BLC_UNUSED(blc_blech_aux_retcode_1);
        blc_blech_ctx->pc_5 = 6;
    }
    if ( blc_blech_ctx->pc_5 == 4 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_1;
            blc_blech_aux_retcode_1 = blc_DHT11_MQTT_initiate_mesurement(&blc_blech_ctx->pc_5_blc_DHT11_MQTT_initiate_mesurement,
                                                                         (&blc_blech_ctx->blc_measure_init_valid));
            if ( (0 == blc_blech_aux_retcode_1) ) {
                blc_blech_ctx->pc_5 = 8;
            } else if ( !((0 == blc_blech_aux_retcode_1)) ) {
                blc_blech_ctx->pc_5 = 6;
            }
        }
    }
    if ( blc_blech_ctx->pc_5 == 6 ) {
        blc_blech_ctx->pc_5 = 5; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_5 == 8 ) {
        if ( blc_blech_ctx->blc_measure_init_valid ) {
            blc_blech_ctx->pc_5 = 10;
        } else if ( !(blc_blech_ctx->blc_measure_init_valid) ) {
            blc_blech_ctx->pc_5 = 12;
        }
    }
    if ( blc_blech_ctx->pc_5 == 10 ) {
        
        blc_blech_ctx->pc_5 = 14;
    }
    if ( blc_blech_ctx->pc_5 == 12 ) {
        (*blc_retvar) = 0;
        blc_blech_ctx->pc_5 = 0;
    }
    if ( blc_blech_ctx->pc_5 == 14 ) {
        blc_DHT11_MQTT_get_bits(blc_blech_ctx->blc_measure_bitfield);
        memset(blc_blech_ctx->blc_measure_data, 0, 5 * sizeof(blc_bits32));
        blc_blech_ctx->blc_measure_checksum_correct = blc_DHT11_MQTT_extract_bytes(blc_blech_ctx->blc_measure_bitfield,
                                                                                   blc_blech_ctx->blc_measure_data);
        if ( !(blc_blech_ctx->blc_measure_checksum_correct) ) {
            blc_blech_ctx->pc_5 = 16;
        } else if ( blc_blech_ctx->blc_measure_checksum_correct ) {
            blc_blech_ctx->pc_5 = 18;
        }
    }
    if ( blc_blech_ctx->pc_5 == 16 ) {
        (*blc_retvar) = 0;
        blc_blech_ctx->pc_5 = 0;
    }
    if ( blc_blech_ctx->pc_5 == 18 ) {
        (*blc_environment_conditions).humidity = blc_blech_ctx->blc_measure_data[0];
        (*blc_environment_conditions).temperature = blc_blech_ctx->blc_measure_data[2];
        (*blc_retvar) = 1;
        blc_blech_ctx->pc_5 = 0;
    }
    if ( blc_blech_ctx->pc_5 == 20 ) {
        blc_blech_ctx->pc_5 = 0; /* end */
    }
    
    
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_5);
    return blc_blech_ctx->pc_5 ;
}

static blc_pc_t blc_DHT11_MQTT_flash_LED (struct blc_DHT11_MQTT_flash_LED *blc_blech_ctx) {
    loopHead:
    if ( blc_blech_ctx->pc_6 == 2 ) {
        blc_DHT11_MQTT_LED_on();
        blc_blech_ctx->pc_6_blc_DHT11_MQTT_delay.pc_1 = 2;
        blc_int32 blc_blech_aux_retcode_2;
        blc_blech_aux_retcode_2 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_6_blc_DHT11_MQTT_delay,
                                                       1000);
        BLC_UNUSED(blc_blech_aux_retcode_2);
        blc_blech_ctx->pc_6 = 6;
    }
    if ( blc_blech_ctx->pc_6 == 4 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_2;
            blc_blech_aux_retcode_2 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_6_blc_DHT11_MQTT_delay,
                                                           1000);
            if ( (0 == blc_blech_aux_retcode_2) ) {
                blc_blech_ctx->pc_6 = 8;
            } else if ( !((0 == blc_blech_aux_retcode_2)) ) {
                blc_blech_ctx->pc_6 = 6;
            }
        }
    }
    if ( blc_blech_ctx->pc_6 == 6 ) {
        blc_blech_ctx->pc_6 = 5; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_6 == 8 ) {
        blc_DHT11_MQTT_LED_off();
        if ( 1 ) {
            blc_blech_ctx->pc_6 = 2;
            goto loopHead;
        } else if ( 0 ) {
            blc_blech_ctx->pc_6 = 10;
        }
    }
    if ( blc_blech_ctx->pc_6 == 10 ) {
        blc_blech_ctx->pc_6 = 0; /* end */
    }
    
    
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_6);
    return blc_blech_ctx->pc_6 ;
}

static blc_pc_t blc_DHT11_MQTT_reconnect_if_necessary (struct blc_DHT11_MQTT_reconnect_if_necessary *blc_blech_ctx) {
    loopHead:
    if ( blc_blech_ctx->pc_7 == 2 ) {
        blc_blech_ctx->blc_reconnect_if_necessary_is_connected = blc_DHT11_MQTT_is_client_connected();
        if ( blc_blech_ctx->blc_reconnect_if_necessary_is_connected ) {
            blc_blech_ctx->pc_7 = 4;
        } else if ( !(blc_blech_ctx->blc_reconnect_if_necessary_is_connected) ) {
            blc_blech_ctx->pc_7 = 18;
        }
    }
    if ( blc_blech_ctx->pc_7 == 4 ) {
        
        blc_blech_ctx->pc_7 = 30;
    }
    if ( blc_blech_ctx->pc_9 == 6 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_5;
            blc_blech_aux_retcode_5 = blc_DHT11_MQTT_flash_LED(&blc_blech_ctx->pc_9_blc_DHT11_MQTT_flash_LED);
            if ( !((0 == blc_blech_aux_retcode_5)) ) {
                blc_blech_ctx->pc_9 = 22;
            } else if ( (0 == blc_blech_aux_retcode_5) ) {
                blc_blech_ctx->pc_9 = 8;
            }
        }
    }
    if ( blc_blech_ctx->pc_9 == 8 ) {
        blc_blech_ctx->pc_9 = 0; /* term */
    }
    if ( blc_blech_ctx->pc_7 == 10 ) {
        if ( 1 ) {
            blc_blech_ctx->pc_7 = 28;
        }
    }
    if ( blc_blech_ctx->pc_8 == 12 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_4;
            blc_blech_aux_retcode_4 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_8_blc_DHT11_MQTT_delay,
                                                           5000);
            if ( !((0 == blc_blech_aux_retcode_4)) ) {
                blc_blech_ctx->pc_8 = 26;
            } else if ( (0 == blc_blech_aux_retcode_4) ) {
                blc_blech_ctx->pc_8 = 14;
            }
        }
    }
    if ( blc_blech_ctx->pc_8 == 14 ) {
        if ( !(blc_blech_ctx->blc_reconnect_if_necessary_is_connected) ) {
            blc_blech_ctx->pc_8 = 24;
            goto loopHead;
        } else if ( blc_blech_ctx->blc_reconnect_if_necessary_is_connected ) {
            blc_blech_ctx->pc_8 = 16;
        }
    }
    if ( blc_blech_ctx->pc_8 == 16 ) {
        blc_blech_ctx->pc_8 = 0; /* term */
    }
    if ( blc_blech_ctx->pc_7 == 18 ) {
        blc_blech_ctx->pc_8 = 24;
        blc_blech_ctx->pc_9 = 20;
        blc_blech_ctx->pc_7 = 28;
    }
    if ( blc_blech_ctx->pc_9 == 20 ) {
        blc_blech_ctx->pc_9_blc_DHT11_MQTT_flash_LED.pc_6 = 2;
        blc_int32 blc_blech_aux_retcode_5;
        blc_blech_aux_retcode_5 = blc_DHT11_MQTT_flash_LED(&blc_blech_ctx->pc_9_blc_DHT11_MQTT_flash_LED);
        BLC_UNUSED(blc_blech_aux_retcode_5);
        blc_blech_ctx->pc_9 = 22;
    }
    if ( blc_blech_ctx->pc_9 == 22 ) {
        blc_blech_ctx->pc_9 = 7; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_8 == 24 ) {
        blc_blech_ctx->blc_reconnect_if_necessary_is_connected = blc_DHT11_MQTT_connect();
        blc_blech_ctx->pc_8_blc_DHT11_MQTT_delay.pc_1 = 2;
        blc_int32 blc_blech_aux_retcode_4;
        blc_blech_aux_retcode_4 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_8_blc_DHT11_MQTT_delay,
                                                       5000);
        BLC_UNUSED(blc_blech_aux_retcode_4);
        blc_blech_ctx->pc_8 = 26;
    }
    if ( blc_blech_ctx->pc_8 == 26 ) {
        blc_blech_ctx->pc_8 = 13; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_7 == 28 ) {
        blc_bool blc_blech_aux_termVar_3;
        if ( blc_blech_ctx->pc_8 == 0 ) {
            blc_blech_ctx->pc_8 = 0;
            blc_blech_ctx->pc_9 = 0;
            blc_blech_aux_termVar_3 = 1;
        } else {
            blc_blech_aux_termVar_3 = 0;
        }
        if ( !(blc_blech_aux_termVar_3) ) {
            blc_blech_ctx->pc_7 = 34;
        } else if ( blc_blech_aux_termVar_3 ) {
            blc_blech_ctx->pc_7 = 30;
        }
    }
    if ( blc_blech_ctx->pc_7 == 30 ) {
        blc_DHT11_MQTT_LED_off();
        blc_blech_ctx->pc_7 = 33; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_7 == 32 ) {
        if ( 1 ) {
            blc_blech_ctx->pc_7 = 0;
            blc_blech_ctx->pc_8 = 0;
            blc_blech_ctx->pc_9 = 0; /* end */
        }
    }
    if ( blc_blech_ctx->pc_7 == 34 ) {
        blc_blech_ctx->pc_7 = 11; /* proceed from surface to depth */
    }
    
    
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_7);
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_8);
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_9);
    return blc_blech_ctx->pc_7 ;
}

static blc_pc_t blc_DHT11_MQTT_mqtt_loop (struct blc_DHT11_MQTT_mqtt_loop *blc_blech_ctx) {
    if ( blc_blech_ctx->pc_10 == 2 ) {
        blc_DHT11_MQTT_client_loop();
        blc_blech_ctx->pc_10 = 5; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_10 == 4 ) {
        if ( 1 ) {
            blc_blech_ctx->pc_10 = 0; /* end */
        }
    }
    
    
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_10);
    return blc_blech_ctx->pc_10 ;
}

static blc_pc_t blc_DHT11_MQTT_Main (struct blc_DHT11_MQTT_Main *blc_blech_ctx) {
    loopHead:
    if ( blc_blech_ctx->pc_11 == 2 ) {
        memset((&blc_blech_ctx->blc_Main_environment_conditions),
               0,
               sizeof(struct blc_DHT11_MQTT_EnvCond));
        blc_blech_ctx->blc_Main_environment_conditions.temperature = 0;
        blc_blech_ctx->blc_Main_environment_conditions.humidity = 0;
        blc_blech_ctx->pc_11 = 4;
    }
    if ( blc_blech_ctx->pc_11 == 4 ) {
        blc_blech_ctx->blc_Main_25_status = 0;
        blc_blech_ctx->pc_11_blc_DHT11_MQTT_measure.pc_5 = 2;
        blc_int32 blc_blech_aux_retcode_6;
        blc_blech_aux_retcode_6 = blc_DHT11_MQTT_measure(&blc_blech_ctx->pc_11_blc_DHT11_MQTT_measure,
                                                         (&blc_blech_ctx->blc_Main_environment_conditions),
                                                         (&blc_blech_ctx->blc_Main_25_status));
        BLC_UNUSED(blc_blech_aux_retcode_6);
        blc_blech_ctx->pc_11 = 8;
    }
    if ( blc_blech_ctx->pc_11 == 6 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_6;
            blc_blech_aux_retcode_6 = blc_DHT11_MQTT_measure(&blc_blech_ctx->pc_11_blc_DHT11_MQTT_measure,
                                                             (&blc_blech_ctx->blc_Main_environment_conditions),
                                                             (&blc_blech_ctx->blc_Main_25_status));
            if ( (0 == blc_blech_aux_retcode_6) ) {
                blc_blech_ctx->pc_11 = 10;
            } else if ( !((0 == blc_blech_aux_retcode_6)) ) {
                blc_blech_ctx->pc_11 = 8;
            }
        }
    }
    if ( blc_blech_ctx->pc_11 == 8 ) {
        blc_blech_ctx->pc_11 = 7; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_11 == 10 ) {
        if ( blc_blech_ctx->blc_Main_25_status ) {
            blc_blech_ctx->pc_11 = 12;
        } else if ( !(blc_blech_ctx->blc_Main_25_status) ) {
            blc_blech_ctx->pc_11 = 14;
        }
    }
    if ( blc_blech_ctx->pc_11 == 12 ) {
        
        blc_blech_ctx->pc_11 = 16;
    }
    if ( blc_blech_ctx->pc_11 == 14 ) {
        blc_blech_ctx->blc_Main_environment_conditions.humidity = 4294967295;
        blc_blech_ctx->blc_Main_environment_conditions.temperature = 4294967295;
        blc_blech_ctx->pc_11 = 16;
    }
    if ( blc_blech_ctx->pc_11 == 16 ) {
        blc_DHT11_MQTT_publish_conditions(blc_blech_ctx->blc_Main_environment_conditions.temperature,
                                          blc_blech_ctx->blc_Main_environment_conditions.humidity);
        blc_blech_ctx->pc_11_blc_DHT11_MQTT_delay.pc_1 = 2;
        blc_int32 blc_blech_aux_retcode_7;
        blc_blech_aux_retcode_7 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_11_blc_DHT11_MQTT_delay,
                                                       2000);
        BLC_UNUSED(blc_blech_aux_retcode_7);
        blc_blech_ctx->pc_11 = 20;
    }
    if ( blc_blech_ctx->pc_11 == 18 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_7;
            blc_blech_aux_retcode_7 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_11_blc_DHT11_MQTT_delay,
                                                           2000);
            if ( (0 == blc_blech_aux_retcode_7) ) {
                blc_blech_ctx->pc_11 = 22;
            } else if ( !((0 == blc_blech_aux_retcode_7)) ) {
                blc_blech_ctx->pc_11 = 20;
            }
        }
    }
    if ( blc_blech_ctx->pc_11 == 20 ) {
        blc_blech_ctx->pc_11 = 19; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_11 == 22 ) {
        blc_blech_ctx->pc_11_blc_DHT11_MQTT_mqtt_loop.pc_10 = 2;
        blc_int32 blc_blech_aux_retcode_8;
        blc_blech_aux_retcode_8 = blc_DHT11_MQTT_mqtt_loop(&blc_blech_ctx->pc_11_blc_DHT11_MQTT_mqtt_loop);
        BLC_UNUSED(blc_blech_aux_retcode_8);
        blc_blech_ctx->pc_11 = 26;
    }
    if ( blc_blech_ctx->pc_11 == 24 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_8;
            blc_blech_aux_retcode_8 = blc_DHT11_MQTT_mqtt_loop(&blc_blech_ctx->pc_11_blc_DHT11_MQTT_mqtt_loop);
            if ( (0 == blc_blech_aux_retcode_8) ) {
                blc_blech_ctx->pc_11 = 28;
            } else if ( !((0 == blc_blech_aux_retcode_8)) ) {
                blc_blech_ctx->pc_11 = 26;
            }
        }
    }
    if ( blc_blech_ctx->pc_11 == 26 ) {
        blc_blech_ctx->pc_11 = 25; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_11 == 28 ) {
        blc_blech_ctx->pc_11_blc_DHT11_MQTT_reconnect_if_necessary.pc_7 = 2;
        blc_blech_ctx->pc_11_blc_DHT11_MQTT_reconnect_if_necessary.pc_8 = 0;
        blc_blech_ctx->pc_11_blc_DHT11_MQTT_reconnect_if_necessary.pc_9 = 0;
        blc_int32 blc_blech_aux_retcode_9;
        blc_blech_aux_retcode_9 = blc_DHT11_MQTT_reconnect_if_necessary(&blc_blech_ctx->pc_11_blc_DHT11_MQTT_reconnect_if_necessary);
        BLC_UNUSED(blc_blech_aux_retcode_9);
        blc_blech_ctx->pc_11 = 32;
    }
    if ( blc_blech_ctx->pc_11 == 30 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_9;
            blc_blech_aux_retcode_9 = blc_DHT11_MQTT_reconnect_if_necessary(&blc_blech_ctx->pc_11_blc_DHT11_MQTT_reconnect_if_necessary);
            if ( !((0 == blc_blech_aux_retcode_9)) ) {
                blc_blech_ctx->pc_11 = 32;
            } else if ( (0 == blc_blech_aux_retcode_9) ) {
                blc_blech_ctx->pc_11 = 34;
            }
        }
    }
    if ( blc_blech_ctx->pc_11 == 32 ) {
        blc_blech_ctx->pc_11 = 31; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_11 == 34 ) {
        if ( 1 ) {
            blc_blech_ctx->pc_11 = 4;
            goto loopHead;
        } else if ( 0 ) {
            blc_blech_ctx->pc_11 = 36;
        }
    }
    if ( blc_blech_ctx->pc_11 == 36 ) {
        blc_blech_ctx->pc_11 = 0; /* end */
    }
    
    
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_11);
    return blc_blech_ctx->pc_11 ;
}

/*
** blech program
*/

void blc_blech_DHT11_MQTT_tick (void) {
    blc_DHT11_MQTT_Main(&blc_blech_ctx);
}

void blc_blech_DHT11_MQTT_init (void) {
    blc_blech_ctx.pc_11 = 2;
}