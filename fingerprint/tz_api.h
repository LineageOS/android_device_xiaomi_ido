/*
 * Copyright (C) 2016 Shane Francis / Jens Andersen
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TZAPI_H_
#define __TZAPI_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FP_TZAPP_PATH "/firmware/image/"
#define FP_TZAPP_NAME "tzfinger"
//#define FP_TZAPP_PATH "/etc/firmware/"
//#define FP_TZAPP_NAME "fpctzapp"

#define BUFFER_SIZE 64

//enumerate tz app command ID's
enum fingerprint_cmd_t {
    FPC_INIT = 0x00,  //fpc_ta_init // send_cmd_get
    FPC_ENROLL_START = 0x03,  //fpc_ta_begin_enrol // send_cmd
    FPC_ENROLL_STEP = 0x04,  //fpc_ta_enrol // send_cmd
    FPC_ENROLL_END = 0x05,  //fpc_ta_end_enrol // send_cmd
    FPC_ENROLL_EXTENDED = 0x06, //fpc_tac_enrol_extended  NOT USED
    FPC_AUTH_START = 0x07, //fpc_ta_begin_identify  // send_cmd
    FPC_AUTH_STEP = 0x08, //fpc_ta_identify // send_cmd
    FPC_AUTH_END = 0x09, //fpc_ta_end_identify // send_cmd
    FPC_CHK_FP_LOST = 0x0B, // fpc_ta_check_finger_lost  // send_cmd_get
    FPC_SET_WAKE = 0x27, // fpc_tac_wakeup_setup // send_cmd
    FPC_GET_WAKE_TYPE = 0x0C, //fpc_ta_wakeup_qualification // send_cmd
    FPC_SET_FP_STORE = 0x20, //fpc_tac_set_active_fingerprint_set  // send_cmd
    FPC_GET_PRINT_ID = 0x28,  // fpc_tac_get_template_id_from_index
    FPC_SET_DB_DATA = 0x1E, //fpc_tac_send_set_template_db_path  ?
    FPC_GET_DB_LENGTH = 0x13, // fpc_tac_send_get_template_size_cmd
    FPC_GET_DB_DATA = 0x1D, //fpc_ta_load_template_db
    FPC_GET_ID_LIST = 0x10, //fpc_ta_get_indices
    FPC_GET_ID_COUNT = 0x11, // fpc_ta_get_template_count // send_cmd_get
    FPC_GET_DEL_PRINT = 0x12, //fpc_ta_delete_template  // send_cmd
    FPC_CAPTURE_IMAGE = 0x16, //fpc_ta_capture_image // send_cmd	
    FPC_GET_INIT_STATE = 0x1f, // fpc_init_lib step 2 
    FPC_INIT_UNK_0 = 0x25, // fpc_get_sensor_info 
    FPC_INIT_UNK_1 = 0x26, // fpc_tac_open  (check if return 13) engeneering mode
};   


typedef struct {
    uint32_t cmd_id;
    uint32_t ret_val; //Some cases this is used for return value of the command
    uint32_t length; //Some length of data supplied by previous modified command
    uint32_t extra; //Some length of data supplied by previous modified command
} fpc_send_std_cmd_t;



typedef struct {
    uint32_t cmd_id;
    uint32_t ret_val; //Some cases this is used for return value of the command
    uint32_t length; //Some length of data supplied by previous modified command
    uint32_t id; //Some length of data supplied by previous modified command
} fpc_send_auth_cmd_t;


typedef struct {
    uint32_t cmd_id;
    uint32_t ret_val; //Some cases this is used for return value of the command
    uint32_t na1; // always 0x45 ?
    uint32_t na2; //???
    uint32_t na3; //???
    uint32_t na4; //???
    uint32_t print_index;
} fpc_send_enroll_start_cmd_t;


typedef struct {
    uint32_t cmd_id;
    uint32_t p1; //Some cases this is used for return value of the command
    uint32_t p2; // always 0x45 ?
    uint32_t p3; //???
    uint32_t p4; //???
    uint32_t p5; //???
    uint32_t print_count;
} fpc_get_pint_index_cmd_t;

typedef struct {
    uint32_t cmd_id;
    uint32_t v_addr; //Virtual address of ion mmap buffer
    uint32_t length; //Length of data on ion buffer
    uint32_t extra; //???
} fpc_send_mod_cmd_t;


typedef struct {
    uint32_t cmd_id;
    uint32_t v_addr;
    uint64_t ret_val; //64bit int
} fpc_send_int64_cmd_t;

#ifdef __cplusplus
}
#endif
#endif
