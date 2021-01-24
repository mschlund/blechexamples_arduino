#ifndef BLECH_DHT11_MQTT_H_INCLUDED
#define BLECH_DHT11_MQTT_H_INCLUDED

/*
** This is generated code - do not touch!
*/

/*
** blech types
*/

#include "blech.h"

/*
** all user defined types
*/

struct blc_DHT11_MQTT_EnvCond {
    blc_bits32 temperature;
    blc_bits32 humidity;
};

/*
** activity contexts
*/

struct blc_DHT11_MQTT_delay {
    blc_nat32 blc_delay_ticks;
    blc_pc_t pc_1;
};
struct blc_DHT11_MQTT_initiate_mesurement {
    blc_nat32 blc_initiate_mesurement_initial_sequence;
    blc_pc_t pc_2;
    struct blc_DHT11_MQTT_delay pc_2_blc_DHT11_MQTT_delay;
};
struct blc_DHT11_MQTT_measure {
    blc_nat8 blc_measure_bitfield[40];
    blc_bool blc_measure_init_valid;
    blc_bits32 blc_measure_data[5];
    blc_bool blc_measure_checksum_correct;
    blc_pc_t pc_5;
    struct blc_DHT11_MQTT_initiate_mesurement pc_5_blc_DHT11_MQTT_initiate_mesurement;
};
struct blc_DHT11_MQTT_Main {
    struct blc_DHT11_MQTT_EnvCond blc_Main_environment_conditions;
    blc_bool blc_Main_19_status;
    blc_pc_t pc_6;
    struct blc_DHT11_MQTT_delay pc_6_blc_DHT11_MQTT_delay;
    struct blc_DHT11_MQTT_measure pc_6_blc_DHT11_MQTT_measure;
};

/*
** extern functions to be implemented in C
*/

/*
** program functions: tick, init
*/

void blc_blech_DHT11_MQTT_tick (void);

void blc_blech_DHT11_MQTT_init (void);

void blc_blech_DHT11_MQTT_printState (void);

#endif /* BLECH_DHT11_MQTT_H_INCLUDED */