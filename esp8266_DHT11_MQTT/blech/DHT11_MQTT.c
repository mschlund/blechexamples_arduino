/*
** This is generated code - do not touch!
*/

#include <string.h>

/*
** used C headers
*/

#include "env.h"
#include "Utils.h"

/*
** blech types
*/

#include "blech.h"

/*
** exports, user types and C wrappers
*/

#include "blech/DHT11_MQTT.h"

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

#define blc_DHT11_MQTT_publish_conditions(blc_temperature, blc_humidity) \
    publish_conditions(blc_temperature, blc_humidity)

#define blc_DHT11_MQTT_interrupts_on() \
    interrupts_on()

#define blc_DHT11_MQTT_interrupts_off() \
    interrupts_off()

#define blc_DHT11_MQTT_reconnect() \
    reconnect()

#define blc_DHT11_MQTT_client_loop() \
    client_loop()

#define blc_DHT11_MQTT_is_client_connected() \
    is_client_connected()

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

static blc_pc_t blc_DHT11_MQTT_Main (struct blc_DHT11_MQTT_Main *blc_blech_ctx) {
    loopHead:
    if ( blc_blech_ctx->pc_6 == 2 ) {
        memset((&blc_blech_ctx->blc_Main_environment_conditions),
               0,
               sizeof(struct blc_DHT11_MQTT_EnvCond));
        blc_blech_ctx->blc_Main_environment_conditions.temperature = 0;
        blc_blech_ctx->blc_Main_environment_conditions.humidity = 0;
        blc_blech_ctx->pc_6 = 4;
    }
    if ( blc_blech_ctx->pc_6 == 4 ) {
        blc_blech_ctx->blc_Main_19_status = 0;
        blc_blech_ctx->pc_6_blc_DHT11_MQTT_measure.pc_5 = 2;
        blc_int32 blc_blech_aux_retcode_2;
        blc_blech_aux_retcode_2 = blc_DHT11_MQTT_measure(&blc_blech_ctx->pc_6_blc_DHT11_MQTT_measure,
                                                         (&blc_blech_ctx->blc_Main_environment_conditions),
                                                         (&blc_blech_ctx->blc_Main_19_status));
        BLC_UNUSED(blc_blech_aux_retcode_2);
        blc_blech_ctx->pc_6 = 8;
    }
    if ( blc_blech_ctx->pc_6 == 6 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_2;
            blc_blech_aux_retcode_2 = blc_DHT11_MQTT_measure(&blc_blech_ctx->pc_6_blc_DHT11_MQTT_measure,
                                                             (&blc_blech_ctx->blc_Main_environment_conditions),
                                                             (&blc_blech_ctx->blc_Main_19_status));
            if ( (0 == blc_blech_aux_retcode_2) ) {
                blc_blech_ctx->pc_6 = 10;
            } else if ( !((0 == blc_blech_aux_retcode_2)) ) {
                blc_blech_ctx->pc_6 = 8;
            }
        }
    }
    if ( blc_blech_ctx->pc_6 == 8 ) {
        blc_blech_ctx->pc_6 = 7; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_6 == 10 ) {
        if ( blc_blech_ctx->blc_Main_19_status ) {
            blc_blech_ctx->pc_6 = 12;
        } else if ( !(blc_blech_ctx->blc_Main_19_status) ) {
            blc_blech_ctx->pc_6 = 14;
        }
    }
    if ( blc_blech_ctx->pc_6 == 12 ) {
        
        blc_blech_ctx->pc_6 = 16;
    }
    if ( blc_blech_ctx->pc_6 == 14 ) {
        blc_blech_ctx->blc_Main_environment_conditions.humidity = 4294967295;
        blc_blech_ctx->blc_Main_environment_conditions.temperature = 4294967295;
        blc_blech_ctx->pc_6 = 16;
    }
    if ( blc_blech_ctx->pc_6 == 16 ) {
        blc_blech_ctx->pc_6_blc_DHT11_MQTT_delay.pc_1 = 2;
        blc_int32 blc_blech_aux_retcode_3;
        blc_blech_aux_retcode_3 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_6_blc_DHT11_MQTT_delay,
                                                       2000);
        BLC_UNUSED(blc_blech_aux_retcode_3);
        blc_blech_ctx->pc_6 = 20;
    }
    if ( blc_blech_ctx->pc_6 == 18 ) {
        if ( 1 ) {
            blc_int32 blc_blech_aux_retcode_3;
            blc_blech_aux_retcode_3 = blc_DHT11_MQTT_delay(&blc_blech_ctx->pc_6_blc_DHT11_MQTT_delay,
                                                           2000);
            if ( (0 == blc_blech_aux_retcode_3) ) {
                blc_blech_ctx->pc_6 = 22;
            } else if ( !((0 == blc_blech_aux_retcode_3)) ) {
                blc_blech_ctx->pc_6 = 20;
            }
        }
    }
    if ( blc_blech_ctx->pc_6 == 20 ) {
        blc_blech_ctx->pc_6 = 19; /* proceed from surface to depth */
    }
    if ( blc_blech_ctx->pc_6 == 22 ) {
        blc_DHT11_MQTT_publish_conditions(blc_blech_ctx->blc_Main_environment_conditions.temperature,
                                          blc_blech_ctx->blc_Main_environment_conditions.humidity);
        if ( blc_DHT11_MQTT_is_client_connected() ) {
            blc_blech_ctx->pc_6 = 24;
        } else if ( !(blc_DHT11_MQTT_is_client_connected()) ) {
            blc_blech_ctx->pc_6 = 26;
        }
    }
    if ( blc_blech_ctx->pc_6 == 24 ) {
        
        blc_blech_ctx->pc_6 = 28;
    }
    if ( blc_blech_ctx->pc_6 == 26 ) {
        blc_DHT11_MQTT_reconnect();
        blc_blech_ctx->pc_6 = 28;
    }
    if ( blc_blech_ctx->pc_6 == 28 ) {
        blc_DHT11_MQTT_client_loop();
        if ( 1 ) {
            blc_blech_ctx->pc_6 = 4;
            goto loopHead;
        } else if ( 0 ) {
            blc_blech_ctx->pc_6 = 30;
        }
    }
    if ( blc_blech_ctx->pc_6 == 30 ) {
        blc_blech_ctx->pc_6 = 0; /* end */
    }
    
    
    BLC_SWITCH_TO_NEXTSTEP(blc_blech_ctx->pc_6);
    return blc_blech_ctx->pc_6 ;
}

/*
** blech program
*/

void blc_blech_DHT11_MQTT_tick (void) {
    blc_DHT11_MQTT_Main(&blc_blech_ctx);
}

void blc_blech_DHT11_MQTT_init (void) {
    blc_blech_ctx.pc_6 = 2;
}